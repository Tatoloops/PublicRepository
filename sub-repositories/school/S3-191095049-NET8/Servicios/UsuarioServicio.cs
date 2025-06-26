using Microsoft.AspNetCore.Identity;
using Microsoft.IdentityModel.Tokens;
using S3_191095049_NET8.DTOs;
using S3_191095049_NET8.Modelos;
using S3_191095049_NET8.Repositorios.Interfaces;
using S3_191095049_NET8.Servicios.interfaces;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;

namespace S3_191095049_NET8.Servicios;

public class UsuarioServicio : IUsuarioServicio {
    private readonly IUsuarioRepositorio _usuarioRepositorio;
    private readonly IConfiguration _configuration;
    private readonly PasswordHasher<Usuario> _passwordHasher;

    public UsuarioServicio(IUsuarioRepositorio usuarioRepositorio, IConfiguration configuration){
        _usuarioRepositorio = usuarioRepositorio;
        _configuration = configuration;
        _passwordHasher = new PasswordHasher<Usuario>();
    }

    public async Task<string?> Registrar(UsuarioRegistroDto dto){
        var existe = await _usuarioRepositorio.ObtenerPorCorreo(dto.CorreoElectronico);
        if (existe != null) return "El correo ya está registrado";

        var usuario = new Usuario{
            Nombre = dto.Nombre,
            CorreoElectronico = dto.CorreoElectronico
        };

        usuario.ContrasenaHash = _passwordHasher.HashPassword(usuario, dto.Contrasena);

        await _usuarioRepositorio.Crear(usuario);
        return null;
    }

    public async Task<string?> Login(UsuarioLoginDto dto){
        var usuario = await _usuarioRepositorio.ObtenerPorCorreo(dto.CorreoElectronico);
        if (usuario == null) return null;

        var resultado = _passwordHasher.VerifyHashedPassword(usuario, usuario.ContrasenaHash, dto.Contrasena);
        if (resultado == PasswordVerificationResult.Failed) return null;

        // Crear token JWT
        var claims = new[]{
            new Claim(JwtRegisteredClaimNames.Sub, usuario.Id.ToString()),
            new Claim(JwtRegisteredClaimNames.Email, usuario.CorreoElectronico),
            new Claim(ClaimTypes.Role, usuario.Rol)
        };

        var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_configuration["Jwt:Key"]!));
        var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);

        var token = new JwtSecurityToken(
            issuer: _configuration["Jwt:Issuer"],
            audience: _configuration["Jwt:Audience"],
            claims: claims,
            expires: DateTime.UtcNow.AddHours(2),
            signingCredentials: creds
        );

        return new JwtSecurityTokenHandler().WriteToken(token);
    }
}
