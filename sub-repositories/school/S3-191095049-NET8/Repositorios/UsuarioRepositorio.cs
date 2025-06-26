namespace S3_191095049_NET8.Repositorios;

using Npgsql;
using System.Data;
using S3_191095049_NET8.Modelos;
using S3_191095049_NET8.Repositorios.Interfaces;


public class UsuarioRepositorio : IUsuarioRepositorio {
    private readonly string _connectionString;

    public UsuarioRepositorio(IConfiguration configuration) {
        _connectionString = configuration.GetConnectionString("PostgresConnection")!;
    }

    public async Task<Usuario?> ObtenerPorCorreo(string correo) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        using var comando = new NpgsqlCommand("SELECT * FROM Usuarios WHERE CorreoElectronico = @correo", conexion);
        comando.Parameters.AddWithValue("@correo", correo);

        using var reader = await comando.ExecuteReaderAsync();
        if (await reader.ReadAsync()) {
            return new Usuario {
                Id = reader.GetInt32(0),
                Nombre = reader.GetString(1),
                CorreoElectronico = reader.GetString(2),
                ContrasenaHash = reader.GetString(3),
                Rol = reader.GetString(4)
            };
        }

        return null;
    }

    public async Task<Usuario?> ObtenerPorId(int id) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        using var comando = new NpgsqlCommand("SELECT * FROM Usuarios WHERE Id = @id", conexion);
        comando.Parameters.AddWithValue("@id", id);

        using var reader = await comando.ExecuteReaderAsync();
        if (await reader.ReadAsync()) {
            return new Usuario {
                Id = reader.GetInt32(0),
                Nombre = reader.GetString(1),
                CorreoElectronico = reader.GetString(2),
                ContrasenaHash = reader.GetString(3),
                Rol = reader.GetString(4)
            };
        }

        return null;
    }

    public async Task Crear(Usuario usuario) {
        using var conexion = new NpgsqlConnection(_connectionString);
        await conexion.OpenAsync();

        using var comando = new NpgsqlCommand(
            @"INSERT INTO Usuarios (Nombre, CorreoElectronico, ContrasenaHash, Rol)
              VALUES (@nombre, @correo, @hash, @rol)", conexion);

        comando.Parameters.AddWithValue("@nombre", usuario.Nombre);
        comando.Parameters.AddWithValue("@correo", usuario.CorreoElectronico);
        comando.Parameters.AddWithValue("@hash", usuario.ContrasenaHash);
        comando.Parameters.AddWithValue("@rol", usuario.Rol);

        await comando.ExecuteNonQueryAsync();
    }
}
