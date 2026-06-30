# Motor de Consultas y Operaciones para MongoDB (E-commerce Data)

Este proyecto proporciona un motor de ejecución basado en Python para interactuar con una base de datos MongoDB (específicamente para un conjunto de datos de E-commerce) de manera flexible y sencilla.

El objetivo principal es **separar la lógica de las consultas (qué queremos hacer) de la ejecución técnica (cómo lo hace Python)**. Esto permite definir todas las operaciones CRUD, consultas complejas y análisis empresariales (KPIs) en archivos de configuración JSON fáciles de leer y editar, sin necesidad de modificar ni una sola línea de código Python.

---

## Cómo Funciona

El funcionamiento del motor se puede resumir en cuatro pasos simples:

1.  **Define tu "Pedido" (el JSON):** Crea un archivo JSON que describe exactamente qué operación quieres realizar. Piensa en esto como elegir un plato del menú de un restaurante. Especificas la "acción" (FIND, INSERT, UPDATE, DELETE, AGGREGATE) y proporcionas los detalles necesarios (filtros, documentos, etc.).
2.  **Realiza el "Pedido" (Ejecuta el Comando):** Usas la terminal para decirle al "Chef" (el script `mongo_engine.py`) qué "Pedido" (el archivo JSON) quieres que cocine.
3.  **El Chef Prepara el Plato:** El script lee tu archivo JSON, se conecta a la "Despensa" (la base de datos MongoDB) y ejecuta la operación exacta que solicitaste usando un ayudante técnico (PyMongo).
4.  **Sirve el Plato (Ver los Resultados):** El Chef te presenta los resultados directamente en tu pantalla, formateados para que sean fáciles de leer, o confirma que la operación se completó con éxito.

## Estructura del Proyecto

El proyecto está organizado de forma modular para gestionar las diferentes operaciones:

```text
mongodb/
│
├── mongo_engine.py          ← EL MOTOR (CLI principal): Ejecuta cualquier operación definida en JSON.
│
├── actions/                  ← PLANTILLAS CRUD (Crea, Lee, Actualiza, Borra):
│   ├── insert.json          ← Añadir nuevos pedidos.
│   ├── read.json            ← Buscar pedidos básicos.
│   ├── update.json          ← Modificar pedidos existentes (ej: cambiar estado).
│   └── delete.json          ← Eliminar pedidos (ej: cancelados).
│
├── queries/                  ← CONSULTAS ESPECÍFICAS (Búsquedas Complejas):
│   ├── q1_country.json      ← Buscar pedidos por país.
│   ├── q2_category.json     ← Buscar pedidos por categoría.
│   ├── q3_high_revenue.json ← Buscar pedidos con altos ingresos.
│   └── q4_delivered_2024.json ← Buscar pedidos entregados en 2024.
│
└── aggregations/             ← ANÁLISIS DE DATOS (KPIs y Agregados):
    ├── summary.json         ← Resumen global de ingresos y beneficios.
    ├── revenue_by_category.json ← Ingresos totales por categoría de producto.
    ├── monthly_revenue.json  ← Tendencia mensual de ingresos.
    └── profit_margin.json   ← Margen de beneficio por categoría.