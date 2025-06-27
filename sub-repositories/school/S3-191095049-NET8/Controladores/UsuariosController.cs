using Microsoft.AspNetCore.Mvc;
using S3_191095049_NET8.DTOs;
using S3_191095049_NET8.Servicios.interfaces;

namespace S3_191095049_NET8.Controladores;

[ApiController]
[Route("api/usuarios")]

// controlador para manejar las operaciones de usuario
public class UsuariosController : ControllerBase {
    private readonly IUsuarioServicio _usuarioServicio;

    // constructor que recibe el servicio de usuario
    public UsuariosController(IUsuarioServicio usuarioServicio) {
        _usuarioServicio = usuarioServicio;
    }


    [HttpPost("registro")]
    // registrar un nuevo usuario
    public async Task<IActionResult> Registrar([FromBody] UsuarioRegistroDto dto) {
        var error = await _usuarioServicio.Registrar(dto);
        if (error != null)
            return BadRequest(new { mensaje = error });

        return Ok(new { mensaje = "Usuario registrado correctamente" });
    }

    [HttpPost("login")]
    // iniciar sesión de un usuario
    public async Task<IActionResult> Login([FromBody] UsuarioLoginDto dto) {
        var token = await _usuarioServicio.Login(dto);
        if (token == null)
            return Unauthorized(new { mensaje = "Credenciales inválidas" });

        return Ok(new { token });
    }
}
