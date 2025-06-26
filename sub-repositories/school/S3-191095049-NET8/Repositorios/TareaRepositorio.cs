namespace S3_191095049_NET8.Repositorios;

using Npgsql;
using NpgsqlTypes; // Required for NpgsqlDbType
using System.Data;
using S3_191095049_NET8.Modelos;
using S3_191095049_NET8.Repositorios.Interfaces;


public class TareaRepositorio : ITareaRepositorio{
    private readonly string _connectionString;

    public TareaRepositorio(IConfiguration configuration) {
        _connectionString = configuration.GetConnectionString("PostgresConnection")!;
    }

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

    public async Task<Tarea?> ObtenerTareaPorId(int id, int usuarioId) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

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

    public async Task CrearTarea(Tarea tarea) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        // Insertar con la función almacenada (sin Completada)
        using var comando = new NpgsqlCommand(
            @"SELECT InsertarTarea(@Titulo, 
            @Descripcion, 
            @FechaVencimiento, 
            @Completada, 
            @UsuarioId)", conexion);
        comando.Parameters.AddWithValue("@Titulo", NpgsqlDbType.Text, tarea.Titulo);
        comando.Parameters.AddWithValue("@Descripcion", NpgsqlDbType.Text, tarea.Descripcion ?? (object)DBNull.Value);
        comando.Parameters.AddWithValue("@FechaVencimiento", NpgsqlDbType.Date, tarea.FechaVencimiento.Date); // Solo la fecha
        comando.Parameters.AddWithValue("@Completada", tarea.Completada);
        comando.Parameters.AddWithValue("@UsuarioId", NpgsqlDbType.Integer, tarea.UsuarioId);
        await comando.ExecuteNonQueryAsync();

        // // Si está completada, actualizamos su estado
        // if (tarea.Completada)
        // {
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

    public async Task EliminarTarea(int id, int usuarioId) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        using var comando = new NpgsqlCommand("DELETE FROM Tareas WHERE Id = @id AND UsuarioId = @usuarioId", conexion);
        comando.Parameters.AddWithValue("@id", id);
        comando.Parameters.AddWithValue("@usuarioId", usuarioId);

        await comando.ExecuteNonQueryAsync();
    }
}
