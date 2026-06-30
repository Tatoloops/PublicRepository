# AI Context

This document defines the permanent rules of the project.

Every AI working on this repository must follow these specifications.

---

# Project

Academic project about MongoDB and Business Intelligence.

Dataset:

Global E-Commerce Sales Dataset (Synthetic)

Business domain:

E-commerce sales analysis.

---

# Architecture

Raw Dataset

↓

Processed Dataset

↓

MongoDB

↓

Queries

↓

Power BI Dashboard

↓

Business Analysis

---

# Database

Database name

```text
ecommerce
```

Collection

```text
orders
```

Unless explicitly requested, the project will use only one collection.

---

# Dataset Rules

The original CSV must never be modified.

Any cleaning process must generate a new file inside:

```
data/processed/
```

The project should preserve the semantic meaning of every column.

---

# Coding Rules

Do not rename folders.

Do not invent additional technologies.

Keep every solution compatible with MongoDB Compass.

Avoid unnecessary complexity.

The assignment does not require advanced aggregation pipelines unless specifically requested.

---

# Dashboard Rules

The dashboard must remain focused on business analysis.

Expected elements:

* KPIs
* Category analysis
* Revenue analysis
* Country analysis
* Filters

Avoid decorative visualizations.

---

# Documentation Rules

Every technical decision should remain consistent with the rest of the repository.

Generated code should be understandable by undergraduate students.

When producing code, comments should explain the purpose rather than the syntax.

---

# Deliverables

The final repository must contain:

* Clean dataset
* MongoDB scripts
* Dashboard
* Evidence
* Report
* Pipeline diagram

Everything produced by an AI should integrate with these deliverables without requiring manual adaptation.
