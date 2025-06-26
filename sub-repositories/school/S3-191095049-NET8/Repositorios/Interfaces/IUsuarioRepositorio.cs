using S3_191095049_NET8.Modelos;

namespace S3_191095049_NET8.Repositorios.Interfaces;

public interface IUsuarioRepositorio {
    Task<Usuario?> ObtenerPorCorreo(string correo);
    Task<Usuario?> ObtenerPorId(int id);
    Task Crear(Usuario usuario);
}
