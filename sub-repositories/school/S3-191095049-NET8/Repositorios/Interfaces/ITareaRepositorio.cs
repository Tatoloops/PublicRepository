using S3_191095049_NET8.Modelos;

namespace S3_191095049_NET8.Repositorios.Interfaces;

public interface ITareaRepositorio {
    Task<IEnumerable<Tarea>> ListarTareasPorUsuario(int usuarioId);
    Task<Tarea?> ObtenerTareaPorId(int id, int usuarioId);
    Task CrearTarea(Tarea tarea);
    Task ActualizarTarea(Tarea tarea);
    Task EliminarTarea(int id, int usuarioId);
}
