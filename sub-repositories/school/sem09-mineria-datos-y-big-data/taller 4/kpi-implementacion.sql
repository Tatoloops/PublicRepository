-- 1. KPI FINANCIEROS
SELECT 
    SUM(precio * cantidad) AS ingresos_totales,
    SUM((precio - costo) * cantidad) AS margen_total,
    AVG(precio * cantidad) AS ticket_promedio,
    SUM(costo * cantidad) AS costo_total
FROM ventas_urban;

-- 2. KPI DE CLIENTES (Frecuencia e Ingreso por Cliente)
SELECT 
    CAST(COUNT(id_venta) AS FLOAT) / COUNT(DISTINCT cliente_id) AS frecuencia_compra,
    SUM(precio * cantidad) / COUNT(DISTINCT cliente_id) AS ingreso_por_cliente
FROM ventas_urban;

-- 3. KPI OPERACIONALES (Eficiencia de Canal)
SELECT 
    canal,
    COUNT(*) AS total_transacciones,
    ROUND(AVG(cantidad), 2) AS unidades_por_transaccion,
    SUM(precio * cantidad) AS ingresos_canal
FROM ventas_urban
GROUP BY canal;