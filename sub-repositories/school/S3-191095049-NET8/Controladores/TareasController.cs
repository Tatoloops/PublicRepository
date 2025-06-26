using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using S3_191095049_NET8.DTOs;
using S3_191095049_NET8.Servicios.interfaces;
using System.Security.Claims;

namespace S3_191095049_NET8.Controladores;

[ApiController]
[Route("api/tareas")]
[Authorize] // Protege todo el controlador con JWT
public class TareasController : ControllerBase {
    private readonly ITareaServicio _tareaServicio;

    public TareasController(ITareaServicio tareaServicio) {
        _tareaServicio = tareaServicio;
    }

    [HttpGet]
    public async Task<IActionResult> Listar() {
        int usuarioId = int.Parse(User.FindFirstValue(ClaimTypes.NameIdentifier)!);
        var tareas = await _tareaServicio.ListarTareas(usuarioId);
        return Ok(tareas);
    }

    [HttpGet("{id}")]
    public async Task<IActionResult> Obtener(int id) {
        int usuarioId = int.Parse(User.FindFirstValue(ClaimTypes.NameIdentifier)!);
        var tarea = await _tareaServicio.ObtenerTarea(id, usuarioId);
        if (tarea == null) return NotFound();
        return Ok(tarea);
    }

    [HttpPost]
    public async Task<IActionResult> Crear([FromBody] TareaDto dto) {
        int usuarioId = int.Parse(User.FindFirstValue(ClaimTypes.NameIdentifier)!);
        await _tareaServicio.CrearTarea(dto, usuarioId);
        return Ok(new { mensaje = "Tarea creada" });
    }

    [HttpPut("{id}")]
    public async Task<IActionResult> Actualizar(int id, [FromBody] TareaDto dto) {
        int usuarioId = int.Parse(User.FindFirstValue(ClaimTypes.NameIdentifier)!);
        await _tareaServicio.ActualizarTarea(id, dto, usuarioId);
        return Ok(new { mensaje = "Tarea actualizada" });
    }

    [HttpDelete("{id}")]
    public async Task<IActionResult> Eliminar(int id) {
        int usuarioId = int.Parse(User.FindFirstValue(ClaimTypes.NameIdentifier)!);
        await _tareaServicio.EliminarTarea(id, usuarioId);
        return Ok(new { mensaje = "Tarea eliminada" });
    }
}
