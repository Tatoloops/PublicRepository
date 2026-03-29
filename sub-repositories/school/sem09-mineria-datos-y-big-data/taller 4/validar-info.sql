-- PARTE 2: EXPLORACIÓN DE DATOS (EDA)


--¿Cuántos registros contiene el dataset?
SELECT COUNT(*) AS total_registros 
FROM ventas_urban;


-- ¿Cuántos clientes únicos existen?
SELECT COUNT(DISTINCT cliente_id) AS clientes_unicos 
FROM ventas_urban;


-- ¿Cuál es el rango de fechas?
SELECT 
    MIN(fecha) AS fecha_inicio, 
    MAX(fecha) AS fecha_fin,
    MAX(fecha) - MIN(fecha) AS duracion_dias
FROM ventas_urban;


-- ¿Existen valores nulos?
SELECT 
    SUM(CASE WHEN id_venta IS NULL THEN 1 ELSE 0 END) AS nulos_id,
    SUM(CASE WHEN precio IS NULL THEN 1 ELSE 0 END) AS nulos_precio,
    SUM(CASE WHEN costo IS NULL THEN 1 ELSE 0 END) AS nulos_costo,
    SUM(CASE WHEN canal IS NULL THEN 1 ELSE 0 END) AS nulos_canal
FROM ventas_urban;

-- ¿Existen valores atípicos (outliers)?
SELECT 
    MIN(precio) AS precio_min, 
    MAX(precio) AS precio_max, 
    AVG(precio) AS precio_promedio,
    MIN(cantidad) AS cant_min,
    MAX(cantidad) AS cant_max
FROM ventas_urban;

-- ¿Qué patrones observas inicialmente?

SELECT canal, COUNT(*) AS total_ventas, SUM(precio * cantidad) AS ingresos_totales
FROM ventas_urban
GROUP BY canal
ORDER BY ingresos_totales DESC;

-- Ventas por Ciudad:
SELECT ciudad, COUNT(*) AS transacciones
FROM ventas_urban
GROUP BY ciudad
ORDER BY transacciones DESC;