# Proyecto Big Data

## MongoDB + Business Intelligence para Análisis de Comercio Electrónico

---

# Visión General

## Objetivo

Construir una pequeña solución de análisis de datos que simule cómo una empresa de comercio electrónico almacena información de ventas, la consulta mediante MongoDB y posteriormente genera indicadores para apoyar la toma de decisiones utilizando Power BI.

Aunque el proyecto es académico, estará diseñado siguiendo un flujo de trabajo similar al utilizado en proyectos reales de análisis de datos.

---

# Historia del proyecto

Imaginemos una empresa de comercio electrónico que diariamente registra miles de ventas.

Cada venta contiene información como:

* Producto
* Categoría
* Cliente
* Fecha
* Precio
* Cantidad
* Ciudad
* Medio de pago

Toda esta información se almacena en MongoDB.

Posteriormente un analista necesita responder preguntas como:

* ¿Qué categorías venden más?
* ¿Qué ciudades generan mayores ingresos?
* ¿Cuál es el ingreso total?
* ¿Qué productos tienen mejor rendimiento?

Para responder estas preguntas se realizan consultas sobre MongoDB y posteriormente se construye un Dashboard en Power BI.

---

# Objetivos del proyecto

## Objetivo principal

Implementar una solución sencilla de almacenamiento y análisis de datos utilizando MongoDB y Power BI.

## Objetivos técnicos

* Comprender NoSQL.
* Comprender MongoDB.
* Trabajar con documentos.
* Ejecutar operaciones CRUD.
* Realizar consultas.
* Construir un Dashboard.
* Interpretar resultados.

---

# Dataset

## Temática

Comercio electrónico.

## Requisitos

* Más de 300 registros.
* Al menos 5 atributos.

## Idealmente contendrá

```text
id

fecha

producto

categoria

precio

cantidad

ciudad

medio_pago

cliente
```

No es necesario usar todos los campos en el Dashboard.

---

# Tecnologías

## MongoDB

Será nuestro almacenamiento principal.

Responsabilidades:

* almacenar documentos
* realizar consultas
* ejecutar CRUD

---

## MongoDB Compass

Será la interfaz gráfica para administrar la base de datos.

---

## Power BI

Construirá el Dashboard utilizando la información del dataset.

---

# Flujo del proyecto

```text
Dataset CSV

↓

MongoDB

↓

Colección

↓

Consultas

↓

Power BI

↓

Dashboard

↓

Análisis

↓

Conclusiones
```

---

# Arquitectura

```text
                 CSV

                  │

                  ▼

        Base de datos MongoDB

                  │

                  ▼

          Colección ventas

                  │

       ┌──────────┴─────────┐

       ▼                    ▼

 Operaciones CRUD      Consultas

       │                    │

       └──────────┬─────────┘

                  ▼

            Power BI

                  ▼

             Dashboard

                  ▼

       Toma de decisiones
```

---

# Base de datos

Nombre sugerido

```
ecommerce
```

Colección

```
ventas
```

---

# CRUD

Debemos demostrar las cuatro operaciones.

## Create

Insertar una venta nueva.

---

## Read

Consultar ventas.

---

## Update

Modificar algún dato.

Ejemplo:

Actualizar precio.

Actualizar ciudad.

Actualizar cantidad.

---

## Delete

Eliminar un documento.

---

# Consultas

Necesitamos cinco.

## Consulta simple 1

Mostrar todas las ventas.

---

## Consulta simple 2

Mostrar únicamente algunos campos.

---

## Consulta con filtro 1

Ventas de una categoría.

---

## Consulta con filtro 2

Ventas sobre cierto precio.

---

## Consulta ordenada

Ordenar por precio.

---

# Dashboard

Debe contener como mínimo:

## KPI

Ingreso total.

---

## Gráfico 1

Ventas por categoría.

---

## Gráfico 2

Ventas por ciudad.

---

## Segmentador

Categoría.

o

Ciudad.

---

## Título

Análisis de Ventas de Comercio Electrónico

---

# Preguntas que debe responder el Dashboard

* ¿Qué categoría vende más?

* ¿Cuál genera mayores ingresos?

* ¿Qué ciudades concentran las ventas?

* ¿Cuál es el ingreso total?

* ¿Existen categorías con bajo rendimiento?

---

# Pipeline

```text
Fuente de datos

↓

MongoDB

↓

Consultas

↓

Power BI

↓

Dashboard

↓

Análisis

↓

Conclusiones
```

---

# Informe

## 1

Portada

---

## 2

Introducción

---

## 3

Objetivos

---

## 4

Descripción del Dataset

---

## 5

Fundamentación Teórica

* NoSQL
* MongoDB
* CRUD
* Business Intelligence

---

## 6

Implementación

* Base de datos
* Colección
* Importación

---

## 7

CRUD

Con capturas.

---

## 8

Consultas

Con explicación.

---

## 9

Dashboard

Con explicación.

---

## 10

Pipeline

Con diagrama.

---

## 11

Resultados

Interpretación.

---

## 12

Conclusiones.

---

## 13

Bibliografía.

---

# Video

Duración aproximada

6 minutos.

## Orden

1. Presentación.

2. Explicar el problema.

3. Mostrar el dataset.

4. Mostrar MongoDB.

5. CRUD.

6. Consultas.

7. Dashboard.

8. Conclusiones.

---

# Evidencias

Guardar durante todo el proyecto:

* Captura de importación.
* Captura de la colección.
* Captura de cada CRUD.
* Captura de cada consulta.
* Captura del Dashboard.
* Captura del Pipeline.

---

# Organización del proyecto

```
Proyecto/

│

├── dataset/

│      ventas.csv

│

├── mongodb/

│      consultas.js

│

├── dashboard/

│      ecommerce.pbix

│

├── informe/

│      informe.docx

│

├── evidencias/

│      CRUD/

│      Consultas/

│      Dashboard/

│

└── pipeline/

       pipeline.drawio
```

---

# Filosofía del proyecto

No buscamos construir el sistema más complejo.

Buscamos construir un proyecto:

* claro,
* ordenado,
* justificable,
* fácil de explicar,
* y que cumpla completamente la rúbrica.

Cada elemento del proyecto debe responder una pregunta concreta del negocio y aportar información útil para la toma de decisiones. Esa coherencia será el principal indicador de calidad del trabajo.
