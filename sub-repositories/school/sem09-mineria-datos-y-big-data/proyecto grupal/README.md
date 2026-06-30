# Global E-Commerce Sales Analysis

## Big Data Final Project — MongoDB & Business Intelligence

Este proyecto implementa una solución completa para el análisis de datos utilizando tecnologías NoSQL, MongoDB y herramientas de Business Intelligence.

El flujo de trabajo cubre todo el proceso, desde la limpieza del conjunto de datos hasta la generación de archivos listos para ser visualizados en Power BI.

---

# Objetivos

* Limpiar y preparar un conjunto de datos de e-commerce.
* Almacenar la información utilizando MongoDB.
* Realizar operaciones CRUD.
* Ejecutar consultas y agregaciones.
* Exportar información resumida para herramientas BI.
* Construir un dashboard para apoyar la toma de decisiones.

---

# Estructura del proyecto

```
.
├── dashboard/
├── data/
│   ├── raw/
│   └── processed/
├── docs/
├── mongodb/
├── scripts/
├── report/
├── evidence/
└── README.md
```

---

# Flujo completo del proyecto

```
Dataset CSV
      │
      ▼
clean_dataset.py
      │
      ▼
Dataset limpio
      │
      ▼
MongoDB
(import.sh)
      │
      ▼
mongo_engine.py
(CRUD + Queries + Aggregations)
      │
      ▼
export_dashboard.py
      │
      ▼
CSV para Power BI
      │
      ▼
Dashboard
```

---

# Requisitos

Python 3.10+
(3.12.11 de ser posible)

MongoDB Community Edition

MongoDB Database Tools

Instalar dependencias:

```bash
pip install -r requirements.txt
```

---

# Paso 1 — Perfilar el dataset

Antes de modificar el conjunto de datos es posible obtener un pequeño análisis descriptivo.

```bash
python scripts/profile_dataset.py
```

Este script muestra:

* número de filas
* columnas
* valores nulos
* tipos de datos
* estadísticas básicas

---

# Paso 2 — Limpiar el dataset

Genera una versión limpia del archivo original.

```bash
python scripts/clean_dataset.py
```

Entrada:

```
data/raw/ecommerce_sales_dataset.csv
```

Salida:

```
data/processed/ecommerce_sales_dataset_clean.csv
```

Durante este proceso se eliminan columnas innecesarias y se preparan los datos para MongoDB.

---

# Paso 3 — Crear la base de datos

Importar el dataset limpio.

```bash
source mongodb/import.sh
```

El script realiza automáticamente:

* elimina la base anterior
* crea la nueva base
* importa el CSV
* verifica la importación
* muestra el número de documentos

---

# Paso 4 — Operaciones sobre MongoDB

Todas las operaciones se realizan mediante:

```
mongodb/mongo_engine.py
```

El motor utiliza archivos JSON como configuración.

No es necesario modificar el código Python.

---

## Insertar documentos

```bash
python mongodb/mongo_engine.py mongodb/actions/insert.json
```

---

## Leer documentos

```bash
python mongodb/mongo_engine.py mongodb/actions/read.json
```

---

## Actualizar documentos

```bash
python mongodb/mongo_engine.py mongodb/actions/update.json
```

---

## Eliminar documentos

```bash
python mongodb/mongo_engine.py mongodb/actions/delete.json
```

---

# Consultas

Las consultas se encuentran en:

```
mongodb/queries/
```

Ejemplo:

```bash
python mongodb/mongo_engine.py mongodb/queries/q3_high_revenue.json
```

Las consultas pueden utilizar:

* filtros
* proyecciones
* ordenamiento
* límite de resultados

---

# Agregaciones

Las agregaciones se encuentran en:

```
mongodb/aggregations/
```

Ejemplo:

```bash
python mongodb/mongo_engine.py mongodb/aggregations/summary.json
```

Las agregaciones utilizan MongoDB Aggregation Pipeline para generar indicadores utilizados posteriormente en el dashboard.

---

# Exportar datos para Power BI

Una vez realizadas las modificaciones sobre la base de datos se generan archivos CSV para Business Intelligence.

```bash
python dashboard/export_dashboard.py
```

Se generan automáticamente varios archivos dentro de:

```
data/processed/dashboard/
```

Ejemplo:

```
kpi_global.csv

kpi_by_category.csv

kpi_by_country.csv

kpi_monthly_trend.csv

kpi_by_status.csv

kpi_by_payment.csv

kpi_by_shipping.csv

orders_raw.csv
```

Estos archivos pueden importarse directamente en Power BI.

---

# Flujo recomendado

```text
1.
python scripts/profile_dataset.py

↓

2.
python scripts/clean_dataset.py

↓

3.
source mongodb/import.sh

↓

4.
python mongodb/mongo_engine.py mongodb/actions/...

↓

5.
python mongodb/mongo_engine.py mongodb/queries/...

↓

6.
python mongodb/mongo_engine.py mongodb/aggregations/...

↓

7.
python dashboard/export_dashboard.py

↓

8.
Importar los CSV en Power BI
```

---

# Documentación

La carpeta `docs/` contiene documentación adicional del proyecto:

* arquitectura
* diagramas UML
* pipeline
* estructura del repositorio
* funcionamiento del motor MongoDB

---

# Tecnologías utilizadas

* Python
* MongoDB
* PyMongo
* MongoDB Shell
* MongoDB Database Tools
* PlantUML
* Power BI

---

# Autores

Proyecto desarrollado como trabajo final de la asignatura Big Data.

El objetivo es demostrar el uso de tecnologías NoSQL, procesamiento de datos y Business Intelligence mediante un flujo reproducible de análisis de datos.
