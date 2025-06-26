-- Insertar usuario dummy 'admin' si no existe
INSERT INTO Usuarios (Nombre, CorreoElectronico, ContrasenaHash, Rol)
VALUES (
    'marta',
    'marta@example.com',
    'AQAAAAIAAYagAAAAEHm+0z5KGrMuzC8rbXyjJ4scs3FeTwrhf3hf+Nykm37Wt2aIFI1uv0qTzklccxXPfQ==',
    'Administrador'
)
ON CONFLICT (CorreoElectronico) DO NOTHING;