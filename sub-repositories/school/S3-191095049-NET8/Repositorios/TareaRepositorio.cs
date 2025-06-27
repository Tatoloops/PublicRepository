namespace S3_191095049_NET8.Repositorios;

// importar las librerías necesarias
using Npgsql;
using NpgsqlTypes; // requerido for NpgsqlDbType -> para compatibilidad postgresql
// using System.Data;

// importar los modelos y las interfaces
using S3_191095049_NET8.Modelos;
using S3_191095049_NET8.Repositorios.Interfaces;

// repositorio para manejar las operaciones de la entidad Tarea
public class TareaRepositorio : ITareaRepositorio {

    //cadena de conexión a la base de datos PostgreSQL
    private readonly string _connectionString;


    // constructor que recibe la configuración para obtener la cadena de conexión
    public TareaRepositorio(IConfiguration configuration){
        _connectionString = configuration.GetConnectionString("PostgresConnection")!;
    }

    // metodo para listar todas las tareas de un usuario
    public async Task<IEnumerable<Tarea>> ListarTareasPorUsuario(int usuarioId) {
        var tareas = new List<Tarea>();

        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        using var comando = new NpgsqlCommand("SELECT * FROM Tareas WHERE UsuarioId = @usuarioId", conexion);
        comando.Parameters.AddWithValue("@usuarioId", usuarioId);

        using var reader = await comando.ExecuteReaderAsync();
        while (await reader.ReadAsync()) {
            tareas.Add(new Tarea {
                Id = reader.GetInt32(0),
                Titulo = reader.GetString(1),
                Descripcion = reader.IsDBNull(2) ? null : reader.GetString(2),
                FechaVencimiento = reader.GetDateTime(3),
                Completada = reader.GetBoolean(4),
                UsuarioId = reader.GetInt32(5)
            });
        }

        return tareas;
    }
    
    
    // metodo para obtener una tarea por su id y el id del usuario
    public async Task<Tarea?> ObtenerTareaPorId(int id, int usuarioId) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        // usar un comando parametrizado para evitar inyecciones SQL
        using var comando = new NpgsqlCommand("SELECT * FROM Tareas WHERE Id = @id AND UsuarioId = @usuarioId", conexion);
        comando.Parameters.AddWithValue("@id", id);
        comando.Parameters.AddWithValue("@usuarioId", usuarioId);

        using var reader = await comando.ExecuteReaderAsync();
        if (await reader.ReadAsync()) {
            return new Tarea {
                Id = reader.GetInt32(0),
                Titulo = reader.GetString(1),
                Descripcion = reader.IsDBNull(2) ? null : reader.GetString(2),
                FechaVencimiento = reader.GetDateTime(3),
                Completada = reader.GetBoolean(4),
                UsuarioId = reader.GetInt32(5)
            };
        }

        return null;
    }


    // mtodo para crear una nueva tarea
    public async Task CrearTarea(Tarea tarea) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        // Insertar con la función almacenada (sin Completada)
        using var comando = new NpgsqlCommand(
            @"SELECT InsertarTarea(@Titulo, 
            @Descripcion, 
            @FechaVencimiento, 
            0, -- Completada por defecto como false
            @UsuarioId)", conexion);
        comando.Parameters.AddWithValue("@Titulo", NpgsqlDbType.Text, tarea.Titulo);
        comando.Parameters.AddWithValue("@Descripcion", NpgsqlDbType.Text, tarea.Descripcion ?? (object)DBNull.Value);
        comando.Parameters.AddWithValue("@FechaVencimiento", NpgsqlDbType.Date, tarea.FechaVencimiento.Date); // Solo la fecha
        // comando.Parameters.AddWithValue("@Completada", tarea.Completada); // tarea no completada por defecto
        comando.Parameters.AddWithValue("@UsuarioId", NpgsqlDbType.Integer, tarea.UsuarioId);
        await comando.ExecuteNonQueryAsync();

        // Si está completada, actualizamos su estado
        // if (tarea.Completada) {
        // 
        //     using var updateCommand = new NpgsqlCommand(@"
        //         UPDATE Tareas 
        //         SET Completada = @completada
        //         WHERE Titulo = @titulo AND UsuarioId = @usuarioId
        //         ORDER BY Id DESC LIMIT 1", conexion);

        //     updateCommand.Parameters.AddWithValue("@completada", tarea.Completada);
        //     updateCommand.Parameters.AddWithValue("@titulo", NpgsqlDbType.Text, tarea.Titulo);
        //     updateCommand.Parameters.AddWithValue("@usuarioId", NpgsqlDbType.Integer, tarea.UsuarioId);

        //     await updateCommand.ExecuteNonQueryAsync();
        // }
    }




    // metodo para actualizar una tarea
    public async Task ActualizarTarea(Tarea tarea) {

        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        using var comando = new NpgsqlCommand(
            @"UPDATE Tareas SET 
                Titulo = @titulo,
                Descripcion = @descripcion,
                FechaVencimiento = @fecha,
                Completada = @completada
              WHERE Id = @id AND UsuarioId = @usuarioId", conexion);

        comando.Parameters.AddWithValue("@titulo", tarea.Titulo);
        comando.Parameters.AddWithValue("@descripcion", tarea.Descripcion ?? (object)DBNull.Value);
        comando.Parameters.AddWithValue("@fecha", tarea.FechaVencimiento);
        comando.Parameters.AddWithValue("@completada", tarea.Completada);
        comando.Parameters.AddWithValue("@id", tarea.Id);
        comando.Parameters.AddWithValue("@usuarioId", tarea.UsuarioId);

        await comando.ExecuteNonQueryAsync();
    }


    // metodo para eliminar una tarea por su id y el id del usuario
    public async Task EliminarTarea(int id, int usuarioId) {

        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        // usar un comando parametrizado para evitar inyecciones sql
        using var comando = new NpgsqlCommand("DELETE FROM Tareas WHERE Id = @id AND UsuarioId = @usuarioId", conexion);
        comando.Parameters.AddWithValue("@id", id);
        comando.Parameters.AddWithValue("@usuarioId", usuarioId);

        await comando.ExecuteNonQueryAsync();
    }
}
