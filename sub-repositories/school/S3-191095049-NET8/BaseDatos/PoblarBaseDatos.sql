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

-- Insertar usuario dummy 'admin' si no existe
INSERT INTO Usuarios (Nombre, CorreoElectronico, ContrasenaHash, Rol)
VALUES (
    'marta',
    'marta@example.com',
    'AQAAAAIAAYagAAAAEHm+0z5KGrMuzC8rbXyjJ4scs3FeTwrhf3hf+Nykm37Wt2aIFI1uv0qTzklccxXPfQ==',
    'Administrador'
)
ON CONFLICT (CorreoElectronico) DO NOTHING;
