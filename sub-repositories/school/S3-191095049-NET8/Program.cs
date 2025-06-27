// importar librerías necesarias
using Microsoft.AspNetCore.Authentication.JwtBearer;
using Microsoft.IdentityModel.Tokens;
using Microsoft.OpenApi.Models;
using System.Text;

// agregar los namespaces necesarios
using S3_191095049_NET8.Repositorios;
using S3_191095049_NET8.Repositorios.Interfaces;
using S3_191095049_NET8.Servicios;
using S3_191095049_NET8.Servicios.interfaces;


// crear el builder de la aplicación
var builder = WebApplication.CreateBuilder(args);

// leer configuración
var configuration = builder.Configuration;

// Agregar controladores
builder.Services.AddControllers();

// Configurar autenticación JWT
builder.Services.AddAuthentication(JwtBearerDefaults.AuthenticationScheme)
    .AddJwtBearer(options => {
        options.TokenValidationParameters = new TokenValidationParameters {
            ValidateIssuer = true,
            ValidateAudience = true,
            ValidateLifetime = true,
            ValidateIssuerSigningKey = true,
            ValidIssuer = configuration["Jwt:Issuer"],
            ValidAudience = configuration["Jwt:Audience"],
            IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(configuration["Jwt:Key"]!))
        };
    });

// registrar servicios y repositorios
builder.Services.AddScoped<ITareaRepositorio, TareaRepositorio>();
builder.Services.AddScoped<IUsuarioRepositorio, UsuarioRepositorio>();
builder.Services.AddScoped<ITareaServicio, TareaServicio>();
builder.Services.AddScoped<IUsuarioServicio, UsuarioServicio>();

//Swagger para probar la API
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen(c => {
    //JWT en Swagger
    c.AddSecurityDefinition("Bearer", new OpenApiSecurityScheme {
        Description = "Token JWT usando el esquema Bearer. Ej: 'Bearer {token}'",
        Name = "Authorization",
        In = ParameterLocation.Header,
        Type = SecuritySchemeType.ApiKey,
        Scheme = "Bearer"
    });

    // Requerir autenticación en Swagger
    c.AddSecurityRequirement(new OpenApiSecurityRequirement { {
        new OpenApiSecurityScheme {
            Reference = new OpenApiReference {
                Type = ReferenceType.SecurityScheme,
                Id = "Bearer"
            }
        },
        Array.Empty<string>()
    }});
});

var app = builder.Build();

// habilitar Swagger solo en desarrollo
if (app.Environment.IsDevelopment()) {
    app.UseSwagger();
    app.UseSwaggerUI();
}

// HTTPS
app.UseHttpsRedirection();

// Activar middlewares de autenticación y autorización
app.UseAuthentication();
app.UseAuthorization();

// Mapear los controladores
app.MapControllers();

app.Run();
