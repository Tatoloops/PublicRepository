# INstrucciones Solemne 3
    Tomas Castillo A.

## Introduccion
Crear un proyecto en .NET 8 que implemente los puntos del ejercicio. El proyecto debe subirse al portal siguiendo las indicaciones proporcionadas por el docente. El nombre del proyecto debe ser S3-[RUN]-NET8, reemplazando [RUN] por su RUN personal sin puntos ni guion, incluyendo el dígito verificador. El proyecto tiene que estar comprimido en formato .zip.

## .NET 8 - Proyecto: Administrador de Tareas 
Desarrollar una API RESTful en ASP.NET Core 8 para administrar tareas. El sistema debe permitir a los usuarios registrarse, iniciar sesión, y gestionar sus tareas (crear, actualizar, listar y eliminar). Todo debe ser protegido mediante autenticación JWT, con persistencia en PostgreSQL usando ADO.NET.

Reglas generales:

1. El desarrollo debe realizarse en español (nombres de clases, variables y propiedades).  
2. Usar ADO.NET para acceso a datos (no usar Entity Framework ni otros ORMs).  
3. La base de datos será PostgreSQL.
4. El proyecto debe ser modular: controladores, servicios, repositorios, modelos.
5. Entregar el proyecto comprimido (ZIP), junto con un archivo README.md, el archivo README.md que incluya:
    * Reseña básica del proyecto: descripción breve de la finalidad y funcionalidad principal de la API.
    * Instrucciones de instalación: cómo configurar y ejecutar el proyecto.
    * Requisitos técnicos: versiones de .NET, PostgreSQL, herramientas utilizadas...

6. (6 puntos) Introducción y Configuración de Proyecto
   * (2 pt) Proyecto creado con dotnet new webapi o VS y funcional
    * (2 pt) Archivo README.md con instrucciones
    * (2 pt) Proyecto bien estructurado y organizado

7. (20 puntos) Configuración y Estructura
    * (3 pt) Configuración correcta en appsettings.json
    * (3 pt) Acceso a configuración con IConfiguration
    * (6 pt) Registro de servicios y repositorios con builder.Services
    * (8 pt) Comentarios explicativos o documentación en el código
  
8. (15 puntos) Controlador de Tareas
    * (3 pt) Controlador TareasController creado con [ApiController]
    * (6 pt) Endpoints RESTful (GET, POST, PUT, DELETE)
    * (3 pt) Uso correcto de [FromRoute], [FromQuery], [FromBody]
    * (3 pt) Ruta general /api/tareas
  
9. (18 puntos) Servicios y Lógica de Negocio
    * (12 pt) Servicio TareaServicio con lógica independiente
    * (3 pt) Inyección de dependencias (AddScoped)
    * (3 pt) Uso de interfaces (ITareaServicio)
  
10. (24 puntos) Persistencia y Repositorio con ADO.NET
    * (3 pt) Capa TareaRepositorio implementada de forma manual
    * (3 pt) Uso de NpgsqlConnection, NpgsqlCommand, NpgsqlDataReader
    * (12 pt) Operaciones CRUD funcionales con parámetros
    * (3 pt) Uso de al menos 1 procedimiento almacenado o función PostgreSQL
    * (3 pt) Mapeo manual de datos a modelos
  
11. (30 puntos) Seguridad con JWT y PasswordHasher
    * (8 pt) Registro de usuarios funcional:
        * (2 pt) Implementar un endpoint POST /api/usuarios/registro
        * (2 pt) Recibir datos del nuevo usuario (nombre, correo y contraseña)
        * (2 pt) Utilizar PasswordHasher&lt;Usuario> para generar un hash seguro de la contraseña
        * (2 pt) Guardar en la base de datos solo el hash, no la contraseña original
        * (2 pt) Verificar que el correo electrónico no exista previamente antes de registrar
  
    * (14 pt) Inicio de sesión funcional:
        * (2 pt) Implementar un endpoint POST /api/usuarios/login
        * (2 pt) Validar la contraseña ingresada usando PasswordHasher&lt;Usuario>.VerifyHashedPassword
        * (2 pt) Si es válida, generar un token JWT con System.IdentityModel.Tokens.Jwt
        * (2 pt) Incluir en el token: id, correo, y rol del usuario
        * (2 pt) Usar [Authorize] para proteger controladores de tareas
        * (2 pt) Configurar el middleware de autenticación JWT en Program.cs
        * (2 pt) Permitir autorización basada en roles (Usuario, Administrador)
  
    * (8 pt) Protección de endpoints:
        * (2 pt) Generación y validación de tokens JWT con JwtBearer
        * (2 pt) Protección de endpoints con [Authorize] y validación de rol
        * (2 pt) Uso de al menos 1 procedimiento almacenado o función PostgreSQL
        * (2 pt) Mapeo manual de datos a modelos

## Base de datos

```sql
-- Crear base de datos y conectarse (psql)
CREATE DATABASE "AdministradorTareas";

-- Crear tabla de usuarios
CREATE TABLE IF NOT EXISTS Usuarios (
    Id SERIAL PRIMARY KEY,
    Nombre VARCHAR(100) NOT NULL,
    CorreoElectronico VARCHAR(100) UNIQUE NOT NULL,
    ContrasenaHash TEXT NOT NULL,
    Rol VARCHAR(50) NOT NULL
);

-- Crear tabla de tareas
CREATE TABLE IF NOT EXISTS Tareas (
    Id SERIAL PRIMARY KEY,
    Titulo VARCHAR(200) NOT NULL,
    Descripcion TEXT,
    FechaVencimiento DATE NOT NULL,
    Completada BOOLEAN NOT NULL DEFAULT FALSE,
    UsuarioId INTEGER NOT NULL,
    CONSTRAINT fk_usuario FOREIGN KEY (UsuarioId) REFERENCES Usuarios(Id) ON DELETE CASCADE
);

-- Funcion para insertar tarea
CREATE OR REPLACE FUNCTION InsertarTarea(
    _Titulo VARCHAR,
    _Descripcion TEXT,
    _FechaVencimiento DATE,
    _UsuarioId INT
)
RETURNS VOID AS $$
BEGIN
    INSERT INTO Tareas (Titulo, Descripcion, FechaVencimiento, Completada, UsuarioId)
    VALUES (_Titulo, _Descripcion, _FechaVencimiento, FALSE, _UsuarioId);
END;
$$ LANGUAGE plpgsql;
```


## Base de datos
Dibuje a Anders Hejlsberg, un ingeniero de software danés nacido en 1960, conocido por su destacada contribución al desarrollo de lenguajes de programación y herramientas de software. Entre sus logros más importantes se encuentran la creación de Turbo Pascal y Delphi, así como su papel como arquitecto principal en el desarrollo de C# y TypeScript en Microsoft. Dependiendo del nivel de perfección que usted logre, su calificación puede aumentar en un máximo de dos décimas.