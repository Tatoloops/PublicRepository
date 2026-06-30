LISTA DE CONTENIDOS, HERRAMIENTAS Y TÉCNICAS
1. FUNDAMENTOS DE BIG DATA
Definición de Big Data.

Objetivos de Big Data (capturar, almacenar, procesar, analizar).

Las 5 V's de Big Data:

Volumen

Velocidad

Variedad

Veracidad

Valor

Tipos de Datos en Big Data:

Datos Estructurados

Datos Semiestructurados (XML, JSON)

Datos No Estructurados (videos, imágenes, audios)

Ventajas y Desventajas de Big Data.

Desafíos de Big Data (Almacenamiento, Procesamiento, Seguridad, Calidad, Integración, Escalabilidad).

2. ARQUITECTURAS DE PROCESAMIENTO DE DATOS
Arquitectura Big Data:

Definición y Componentes Generales:

Fuentes de Datos

Ingesta de Datos

Almacenamiento

Procesamiento

Visualización

Ventajas y Desventajas.

Arquitectura Batch:

Definición y Características (procesamiento diferido, alta precisión).

Tipos: Batch Diario, Semanal, Mensual.

Ventajas y Desventajas.

Arquitectura Streaming:

Definición y Características (baja latencia, procesamiento continuo).

Tipos: Real-Time Streaming, Near Real-Time Streaming, Event Streaming.

Ventajas y Desventajas.

Arquitectura Lambda:

Definición (modelo híbrido Batch + Streaming).

Componentes: Batch Layer, Speed Layer, Serving Layer.

Características, Ventajas y Desventajas.

Arquitectura Kappa:

Definición (modelo basado únicamente en Streaming).

Componentes: Event Log, Stream Processing, Serving Layer.

Características, Ventajas y Desventajas.

3. ECOSISTEMA HADOOP
Definición de Hadoop y su objetivo.

Componentes Principales del Ecosistema Hadoop:

HDFS (Hadoop Distributed File System): Sistema de almacenamiento distribuido.

Funcionamiento (división en bloques, distribución, replicación).

Arquitectura y Características.

Ventajas y Desventajas.

YARN (Yet Another Resource Negotiator): Administrador de recursos y tareas.

Arquitectura y Características (gestión centralizada, ejecución paralela).

Beneficios.

MapReduce: Modelo de procesamiento distribuido.

Definición y Funcionamiento (Fase Map, Shuffle and Sort, Fase Reduce).

Características (procesamiento paralelo, distribución automática).

Ventajas y Desventajas (no apto para tiempo real).

Hive: Almacén de datos para consultas SQL.

Pig: Plataforma para análisis de datos.

HBase: Base de datos NoSQL distribuida.

Sqoop: Transferencia de datos entre bases relacionales y Hadoop.

Flume: Recolección y transporte de datos.

Spark: Procesamiento de datos en memoria (también detallado abajo).

Características, Ventajas y Desventajas de Hadoop.

Procesamiento Batch (en el contexto de Hadoop): Concepto, características y ejemplos.

Comparativa Batch vs. Tiempo Real (velocidad, volumen, complejidad, ejemplos).

4. APACHE SPARK Y PROCESAMIENTO DISTRIBUIDO
Definición de Apache Spark (framework de código abierto, procesamiento en memoria).

Características de Apache Spark:

Procesamiento en Memoria (RAM)

Escalabilidad

Tolerancia a fallos

Procesamiento Distribuido

Soporte Multi lenguaje (Scala, Python, Java, R)

Integración con Big Data (Hadoop, Hive, Kafka, Cassandra, nube)

Arquitectura General de Spark:

Driver Program

Cluster Manager

Executors

Worker Nodes

RDD (Resilient Distributed Dataset):

Definición (estructura de datos fundamental).

Características (distribuidos, inmutables, tolerantes a fallos, lazy evaluation).

Operaciones sobre RDD:

Transformaciones: map(), filter(), flatMap(), distinct().

Acciones: collect(), count(), first(), reduce().

DataFrames:

Definición (estructura tabular, evolución de RDD).

Características (estructura tabular, Catalyst Optimizer, menor consumo de memoria, mayor rendimiento, compatibilidad con SQL).

Diferencias entre RDD y DataFrames: (Estructura, Rendimiento, Optimización).

Procesamiento Distribuido con Spark: Concepto, funcionamiento (particiones, paralelismo) y ejemplo.

Tipos de Procesamiento en Spark:

Batch Processing (reportes, ETL).

Stream Processing (Spark Streaming, IoT, redes sociales).

Machine Learning (Mllib).

SQL Analytics (Spark SQL).

Ventajas y Desventajas de Apache Spark.

5. ALGORITMOS DE MACHINE LEARNING
Árboles de Decisión:

Definición y Características (fácil interpretación, clasificación y regresión).

Criterios de división: Gini, Entropía, Ganancia de Información.

Tipos: Árboles de Clasificación, Árboles de Regresión.

Ventajas y Desventajas (overfitting, sensibilidad).

Naive Bayes:

Definición (basado en el Teorema de Bayes, independencia de variables).

Características (rápido, eficiente, bueno con texto).

Tipos: Gaussian Naive Bayes, Multinomial Naive Bayes, Bernoulli Naive Bayes.

Ventajas y Desventajas.

SVM (Support Vector Machine):

Definición (hiperplano de separación con margen máximo).

Características (efectivo en alta dimensión, funciones kernel).

Tipos: SVM Lineal, SVM No Lineal (Kernels: Lineal, Polinomial, RBF, Sigmoide), SVR (Regresión).

Ventajas (alta precisión) y Desventajas (alto costo computacional, difícil interpretación).

Comparativa General: Interpretabilidad, Velocidad, Precisión, Overfitting, Manejo de no linealidad, Escalabilidad, Uso típico.

6. REGLAS DE ASOCIACIÓN
Base Teórica: Frecuencia, Coocurrencia, Probabilidad.

Patrones Frecuentes:

Definición.

Tipos:

Itemsets Frecuentes (ej. {pan, leche}).

Secuencias Frecuentes (orden temporal).

Patrones Estructurados (grafos, redes sociales).

Algoritmo Apriori:

Principio de Apriori ("Si un conjunto es frecuente, todos sus subconjuntos también lo son").

Funcionamiento (generación de candidatos, cálculo de soporte).

Características (búsqueda por niveles, múltiples recorridos).

Ventajas y Desventajas (alto costo computacional, lento en Big Data).

Otros Algoritmos de Patrones Frecuentes:

Basados en Candidatos (Apriori).

Basados en Árboles (FP-Growth).

Basados en Intersección Vertical (ECLAT).

Aplicaciones de Reglas de Asociación: Market Basket Analysis, Recomendadores (Amazon, Netflix), Medicina, Seguridad Informática.

7. HERRAMIENTAS DE INGESTA, ALMACENAMIENTO, PROCESAMIENTO Y VISUALIZACIÓN
Ingesta de Datos: Apache Kafka.

Almacenamiento: Hadoop HDFS.

Procesamiento: Apache Spark, Hadoop MapReduce.

Visualización: Power BI, Tableau.

Motores de Streaming: Spark Streaming.

Librerías de Machine Learning: Mllib (de Spark).