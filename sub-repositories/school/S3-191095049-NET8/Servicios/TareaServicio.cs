using S3_191095049_NET8.DTOs;
using S3_191095049_NET8.Modelos;
using S3_191095049_NET8.Repositorios.Interfaces;
using S3_191095049_NET8.Servicios.interfaces;

namespace S3_191095049_NET8.Servicios;

public class TareaServicio : ITareaServicio {
    private readonly ITareaRepositorio _tareaRepositorio;

    public TareaServicio(ITareaRepositorio tareaRepositorio) {
        _tareaRepositorio = tareaRepositorio;
    }

    public async Task<IEnumerable<Tarea>> ListarTareas(int usuarioId) {
        return await _tareaRepositorio.ListarTareasPorUsuario(usuarioId);
    }

    public async Task<Tarea?> ObtenerTarea(int id, int usuarioId) {
        return await _tareaRepositorio.ObtenerTareaPorId(id, usuarioId);
    }

    public async Task CrearTarea(TareaDto tareaDto, int usuarioId) {
        var tarea = new Tarea {
            Titulo = tareaDto.Titulo,
            Descripcion = tareaDto.Descripcion,
            FechaVencimiento = tareaDto.FechaVencimiento,
            Completada = tareaDto.Completada,
            UsuarioId = usuarioId
        };

        await _tareaRepositorio.CrearTarea(tarea);
    }

    public async Task ActualizarTarea(int id, TareaDto tareaDto, int usuarioId) {
        var tarea = new Tarea {
            Id = id,
            Titulo = tareaDto.Titulo,
            Descripcion = tareaDto.Descripcion,
            FechaVencimiento = tareaDto.FechaVencimiento,
            Completada = tareaDto.Completada,
            UsuarioId = usuarioId
        };

        await _tareaRepositorio.ActualizarTarea(tarea);
    }

    public async Task EliminarTarea(int id, int usuarioId) {
        await _tareaRepositorio.EliminarTarea(id, usuarioId);
    }
}
