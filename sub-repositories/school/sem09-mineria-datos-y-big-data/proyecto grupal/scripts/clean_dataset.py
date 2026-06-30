"""
clean_dataset.py

Data preparation pipeline for the MongoDB project.

This script reads the original dataset, performs basic cleaning,
keeps only the columns required by the project and generates a
processed CSV ready to be imported into MongoDB.
"""

from pathlib import Path
import pandas as pd

# ---------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------

PROJECT_ROOT = Path(__file__).resolve().parent.parent

RAW_DATASET = PROJECT_ROOT / "data" / "raw" / "ecommerce_sales_dataset.csv"
OUTPUT_DATASET = PROJECT_ROOT / "data" / "processed" / "ecommerce_sales_dataset_clean.csv"

OFFICIAL_COLUMNS = [
    "Order_ID",
    "Order_Date",
    "Year",
    "Month",
    "Region",
    "Country",
    "Category",
    "Product_Name",
    "Unit_Price",
    "Quantity",
    "Revenue",
    "Profit",
    "Payment_Method",
    "Shipping_Method",
    "Order_Status",
]

# ---------------------------------------------------------------------
# Load
# ---------------------------------------------------------------------

print("Loading dataset...")

df = pd.read_csv(RAW_DATASET)

original_rows = len(df)

print(f"Rows loaded: {original_rows}")

# ---------------------------------------------------------------------
# Validate columns
# ---------------------------------------------------------------------

missing = [c for c in OFFICIAL_COLUMNS if c not in df.columns]

if missing:
    raise ValueError(
        f"The dataset is missing the following required columns:\n{missing}"
    )

# ---------------------------------------------------------------------
# Select official columns
# ---------------------------------------------------------------------

df = df[OFFICIAL_COLUMNS]

# ---------------------------------------------------------------------
# Remove empty rows
# ---------------------------------------------------------------------

before = len(df)

df = df.dropna(how="all")

print(f"Removed empty rows: {before - len(df)}")

# ---------------------------------------------------------------------
# Remove duplicated orders
# ---------------------------------------------------------------------

before = len(df)

df = df.drop_duplicates(subset="Order_ID")

print(f"Removed duplicated orders: {before - len(df)}")

# ---------------------------------------------------------------------
# Convert data types
# ---------------------------------------------------------------------

df["Order_Date"] = pd.to_datetime(df["Order_Date"])

numeric_columns = [
    "Year",
    "Month",
    "Unit_Price",
    "Quantity",
    "Revenue",
    "Profit",
]

for column in numeric_columns:
    df[column] = pd.to_numeric(df[column], errors="coerce")

# ---------------------------------------------------------------------
# Simple validations
# ---------------------------------------------------------------------

df = df[df["Quantity"] > 0]
df = df[df["Revenue"] >= 0]

# ---------------------------------------------------------------------
# Save
# ---------------------------------------------------------------------

OUTPUT_DATASET.parent.mkdir(parents=True, exist_ok=True)

df.to_csv(OUTPUT_DATASET, index=False)

# ---------------------------------------------------------------------
# Summary
# ---------------------------------------------------------------------

print("\nCleaning completed.")
print("-" * 40)
print(f"Original rows : {original_rows}")
print(f"Final rows    : {len(df)}")
print(f"Columns kept  : {len(df.columns)}")
print(f"Output file   : {OUTPUT_DATASET}")