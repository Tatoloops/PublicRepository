namespace S3_191095049_NET8.Modelos;

public class Tarea {
    public int Id { get; set; }
    public string Titulo { get; set; } = null!;
    public string? Descripcion { get; set; }
    public DateTime FechaVencimiento { get; set; }
    public bool Completada { get; set; } = false;
    public int UsuarioId { get; set; }
}
