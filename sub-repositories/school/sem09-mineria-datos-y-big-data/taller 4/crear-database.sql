-- 1. Crear la base de datos
CREATE DATABASE urban_style_db;

-- 2. Crear la tabla con tipos de datos adecuados
CREATE TABLE ventas_urban (
    id_venta INT PRIMARY KEY,
    fecha DATE,
    cliente_id INT,
    producto VARCHAR(100),
    categoria VARCHAR(50),
    precio INT,
    costo INT,
    cantidad INT,
    canal VARCHAR(20),
    ciudad VARCHAR(50)
);

-- cargar-datos.sql
\copy ventas_urban FROM 'urban_style_dataset_50000.csv' WITH (FORMAT CSV, HEADER, DELIMITER ',');