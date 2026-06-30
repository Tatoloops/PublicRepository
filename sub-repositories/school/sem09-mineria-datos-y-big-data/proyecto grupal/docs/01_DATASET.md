# Dataset Specification

## Overview

This document defines the official dataset used throughout the project.

It specifies the origin of the data, its structure, the cleaning process, the fields used by the application, and the business meaning of each attribute.

Once this document is approved, the dataset structure should remain unchanged during the rest of the project.

---

# Dataset Information

**Name**

Global E-Commerce Sales Dataset (Synthetic)

**Format**

CSV

**Records**

10,000 orders

**Time Period**

2021–2024

**Domain**

E-Commerce Sales

**Purpose**

Simulate the sales activity of an online store for data analysis and Business Intelligence.

---

# Dataset Versions

Two versions of the dataset exist.

## Raw Dataset

Location

```text
data/raw/ecommerce_sales_dataset.csv
```

Characteristics

* Original dataset.
* Never modified.
* Used as backup.

---

## Processed Dataset

Location

```text
data/processed/ecommerce_sales_dataset_clean.csv
```

Characteristics

* Cleaned version.
* Ready for MongoDB import.
* Used throughout the project.

---

# Cleaning Strategy

Before importing the dataset into MongoDB, the following validations must be performed.

## Missing Values

Verify whether null or empty values exist.

If present:

* Remove empty rows.
* Replace values only when appropriate.
* Document the change if necessary.

---

## Duplicate Records

Check for duplicated orders using `Order_ID`.

Expected result:

No duplicate primary identifiers.

---

## Data Types

Validate that every field has the correct type.

Examples:

| Column     | Expected Type |
| ---------- | ------------- |
| Order_Date | Date          |
| Year       | Integer       |
| Unit_Price | Decimal       |
| Quantity   | Integer       |
| Revenue    | Decimal       |
| Profit     | Decimal       |

---

## Data Consistency

Verify that values remain coherent.

Examples

* Revenue ≥ 0
* Profit may be negative only if justified (not expected in this dataset)
* Quantity > 0
* Shipping Days > 0

---

# Official Columns

The project will use the following columns.

| Column          | Description             |
| --------------- | ----------------------- |
| Order_ID        | Unique order identifier |
| Order_Date      | Date of purchase        |
| Year            | Purchase year           |
| Month           | Purchase month          |
| Region          | Geographic region       |
| Country         | Customer country        |
| Category        | Product category        |
| Product_Name    | Product sold            |
| Unit_Price      | Product price           |
| Quantity        | Units sold              |
| Revenue         | Total revenue           |
| Profit          | Profit obtained         |
| Payment_Method  | Payment method          |
| Shipping_Method | Shipping type           |
| Order_Status    | Current order status    |

Other columns may remain in the dataset but are not required by the project.

---

# Business Questions

The selected fields must allow answering the following questions.

* What is the total revenue?
* What is the total profit?
* Which product categories perform best?
* Which countries generate the highest sales?
* Which payment methods are most common?
* How do sales evolve over time?

Every dashboard element and MongoDB query should contribute to answering one or more of these questions.

---

# MongoDB Mapping

The processed dataset will be imported into the following database.

Database

```text
ecommerce
```

Collection

```text
orders
```

Each CSV row represents one MongoDB document.

No additional collections are required.

---

# Notes

The assignment requires at least five attributes and at least 300 records.

This dataset largely exceeds those requirements while remaining simple enough for CRUD operations, MongoDB queries and Business Intelligence visualizations.
