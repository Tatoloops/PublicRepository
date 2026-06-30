# Big Data Project — MongoDB & Power BI

## Overview

This project implements a complete data analysis workflow using a NoSQL database (MongoDB) and a Business Intelligence tool (Power BI).

The objective is to demonstrate the use of MongoDB CRUD operations, data querying, and dashboard creation using an e-commerce sales dataset.

Although developed as an academic project, the repository is organized similarly to a small professional data analytics project. Documentation, code, datasets and evidence are separated to simplify maintenance and future modifications.

---

## Project Goal

Analyze e-commerce sales data in order to support business decision making.

The project includes:

* Data preparation
* MongoDB database creation
* CRUD operations
* Data queries
* Business Intelligence dashboard
* Data pipeline diagram
* Technical report
* Presentation video

---

## Dataset

Dataset:

Global E-Commerce Sales Dataset (Synthetic)

Characteristics

* 10,000 sales records
* CSV format
* 26 attributes
* Synthetic but realistic data
* Covers years 2021–2024

The original dataset will always remain unchanged.

A cleaned version will be generated before importing into MongoDB.

---

## Technologies

| Tool            | Purpose             |
| --------------- | ------------------- |
| MongoDB Compass | Database management |
| MongoDB         | NoSQL database      |
| Power BI        | Dashboard           |
| PlantUML        | Project diagrams    |
| Markdown        | Documentation       |

---

## Repository Structure

```text
docs/
    Project documentation

data/
    Original and processed datasets

mongodb/
    CRUD operations and queries

dashboard/
    Power BI project

report/
    Final report

evidence/
    Screenshots required by the assignment

local/
    Personal files not included in the final submission
```

---

## Main Workflow

```text
Raw Dataset
        │
        ▼
Data Cleaning
        │
        ▼
MongoDB
        │
        ▼
Queries
        │
        ▼
Power BI
        │
        ▼
Dashboard
        │
        ▼
Business Analysis
```

---

## Project Scope

The project intentionally focuses only on the requirements requested by the assignment.

Included:

* MongoDB database
* One collection
* CRUD operations
* Five queries
* Interactive dashboard
* Pipeline diagram
* Technical report

Not included:

* Machine Learning
* Spark
* Hadoop
* Multiple collections
* Distributed processing

---

## Guiding Principle

The objective is not to build the largest possible system.

The objective is to build a clean, coherent and well documented solution that clearly demonstrates the concepts evaluated in the assignment.
