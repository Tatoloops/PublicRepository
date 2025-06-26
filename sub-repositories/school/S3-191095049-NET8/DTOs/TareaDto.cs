namespace S3_191095049_NET8.DTOs;

public class TareaDto {
    public string Titulo { get; set; } = null!;
    public string? Descripcion { get; set; }
    public DateTime FechaVencimiento { get; set; }
    public bool Completada { get; set; } = false;
}
