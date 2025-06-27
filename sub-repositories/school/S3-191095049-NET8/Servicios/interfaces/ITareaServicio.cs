using S3_191095049_NET8.DTOs;
using S3_191095049_NET8.Modelos;

namespace S3_191095049_NET8.Servicios.interfaces;

// interfaz para manejar las operaciones de la entidad Tarea
public interface ITareaServicio {
    Task<IEnumerable<Tarea>> ListarTareas(int usuarioId);
    Task<Tarea?> ObtenerTarea(int id, int usuarioId);
    Task CrearTarea(TareaDto tareaDto, int usuarioId);
    Task ActualizarTarea(int id, TareaDto tareaDto, int usuarioId);
    Task EliminarTarea(int id, int usuarioId);
}
