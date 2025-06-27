using S3_191095049_NET8.DTOs;
using S3_191095049_NET8.Modelos;

namespace S3_191095049_NET8.Servicios.interfaces;

// interfaz para manejar las operaciones de la entidad Usuario
public interface IUsuarioServicio {
    Task<string?> Registrar(UsuarioRegistroDto dto);
    Task<string?> Login(UsuarioLoginDto dto);
}
