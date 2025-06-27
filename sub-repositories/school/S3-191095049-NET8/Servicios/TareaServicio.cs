using S3_191095049_NET8.DTOs;
using S3_191095049_NET8.Modelos;
using S3_191095049_NET8.Repositorios.Interfaces;
using S3_191095049_NET8.Servicios.interfaces;


namespace S3_191095049_NET8.Servicios;

// servicio para manejar las operaciones de la entidad Tarea
public class TareaServicio : ITareaServicio  {

    // repositorio de tareas
    private readonly ITareaRepositorio _tareaRepositorio;

    // constructor que recibe el repositorio de tareas
    public TareaServicio(ITareaRepositorio tareaRepositorio) {
        _tareaRepositorio = tareaRepositorio;
    }


    // listar todas las tareas de un usuario
    public async Task<IEnumerable<Tarea>> ListarTareas(int usuarioId) {
        return await _tareaRepositorio.ListarTareasPorUsuario(usuarioId);
    }

    // obtener una tarea por su ID y el ID del usuario
    public async Task<Tarea?> ObtenerTarea(int id, int usuarioId) {
        return await _tareaRepositorio.ObtenerTareaPorId(id, usuarioId);
    }

    // crear una nueva tarea
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

    // actualizar una tarea existente

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

    // eliminar una tarea por su ID y el ID del usuario
    public async Task EliminarTarea(int id, int usuarioId) {
        await _tareaRepositorio.EliminarTarea(id, usuarioId);
    }
}
