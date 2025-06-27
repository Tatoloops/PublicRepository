namespace S3_191095049_NET8.Modelos;

// using System;
// using System.ComponentModel; // For [DefaultValue], [Description]
// using System.ComponentModel.DataAnnotations; // For [Required]
// using System.Text.Json.Serialization; // For [JsonPropertyName]
using NpgsqlTypes; // For NpgsqlDbType


// modelo tarea
public class Tarea {
    public int Id { get; set; }
    public string Titulo { get; set; } = null!;
    public string? Descripcion { get; set; }
    public DateTime FechaVencimiento { get; set; }
    public bool Completada { get; set; } = false;
    public int UsuarioId { get; set; }
}
