"""
profile_dataset.py

Generates a basic profile of the processed dataset.

This script DOES NOT modify the dataset.
It only analyzes the data and prints useful statistics that can be
included in the technical report.
"""

from pathlib import Path
import pandas as pd

# ---------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------

PROJECT_ROOT = Path(__file__).resolve().parent.parent

DATASET = PROJECT_ROOT / "data" / "processed" / "ecommerce_sales_dataset_clean.csv"

# ---------------------------------------------------------------------
# Load dataset
# ---------------------------------------------------------------------

print("Loading processed dataset...")

df = pd.read_csv(DATASET)

print("Dataset loaded successfully.\n")

# ---------------------------------------------------------------------
# General Information
# ---------------------------------------------------------------------

print("=" * 60)
print("DATASET PROFILE")
print("=" * 60)

print(f"Rows      : {len(df)}")
print(f"Columns   : {len(df.columns)}")

memory = df.memory_usage(deep=True).sum() / 1024**2
print(f"Memory    : {memory:.2f} MB")

print("\n")

# ---------------------------------------------------------------------
# Column Information
# ---------------------------------------------------------------------

print("=" * 60)
print("COLUMN TYPES")
print("=" * 60)

for column in df.columns:
    print(f"{column:<20} {df[column].dtype}")

print("\n")

# ---------------------------------------------------------------------
# Missing Values
# ---------------------------------------------------------------------

print("=" * 60)
print("MISSING VALUES")
print("=" * 60)

missing = df.isnull().sum()

for column, value in missing.items():
    print(f"{column:<20} {value}")

print("\n")

# ---------------------------------------------------------------------
# Duplicate Orders
# ---------------------------------------------------------------------

print("=" * 60)
print("DUPLICATE ORDER IDs")
print("=" * 60)

duplicates = df["Order_ID"].duplicated().sum()

print(f"Duplicated Order_ID: {duplicates}")

print("\n")

# ---------------------------------------------------------------------
# Numeric Statistics
# ---------------------------------------------------------------------

numeric_columns = [
    "Unit_Price",
    "Quantity",
    "Revenue",
    "Profit",
]

print("=" * 60)
print("NUMERIC SUMMARY")
print("=" * 60)

for column in numeric_columns:

    print(f"\n{column}")

    print(f"  Min  : {df[column].min():.2f}")
    print(f"  Max  : {df[column].max():.2f}")
    print(f"  Mean : {df[column].mean():.2f}")
    print(f"  Std  : {df[column].std():.2f}")

print("\n")

# ---------------------------------------------------------------------
# Unique Values
# ---------------------------------------------------------------------

categorical_columns = [
    "Region",
    "Country",
    "Category",
    "Payment_Method",
    "Shipping_Method",
    "Order_Status",
]

print("=" * 60)
print("UNIQUE VALUES")
print("=" * 60)

for column in categorical_columns:
    print(f"{column:<20} {df[column].nunique()} unique values")

print("\n")

# ---------------------------------------------------------------------
# Top Categories
# ---------------------------------------------------------------------

print("=" * 60)
print("TOP PRODUCT CATEGORIES")
print("=" * 60)

print(df["Category"].value_counts())

print("\n")

# ---------------------------------------------------------------------
# Top Countries
# ---------------------------------------------------------------------

print("=" * 60)
print("TOP COUNTRIES")
print("=" * 60)

print(df["Country"].value_counts().head(10))

print("\n")

# ---------------------------------------------------------------------
# Payment Methods
# ---------------------------------------------------------------------

print("=" * 60)
print("PAYMENT METHODS")
print("=" * 60)

print(df["Payment_Method"].value_counts())

print("\n")

# ---------------------------------------------------------------------
# Order Status
# ---------------------------------------------------------------------

print("=" * 60)
print("ORDER STATUS")
print("=" * 60)

print(df["Order_Status"].value_counts())

print("\n")

# ---------------------------------------------------------------------
# Revenue by Category
# ---------------------------------------------------------------------

print("=" * 60)
print("REVENUE BY CATEGORY")
print("=" * 60)

revenue_category = (
    df.groupby("Category")["Revenue"]
      .sum()
      .sort_values(ascending=False)
)

print(revenue_category)

print("\n")

# ---------------------------------------------------------------------
# Profit by Category
# ---------------------------------------------------------------------

print("=" * 60)
print("PROFIT BY CATEGORY")
print("=" * 60)

profit_category = (
    df.groupby("Category")["Profit"]
      .sum()
      .sort_values(ascending=False)
)

print(profit_category)

print("\n")

# ---------------------------------------------------------------------
# Time Span
# ---------------------------------------------------------------------

print("=" * 60)
print("TIME RANGE")
print("=" * 60)

dates = pd.to_datetime(df["Order_Date"])

print(f"First Order : {dates.min().date()}")
print(f"Last Order  : {dates.max().date()}")

print("\n")

print("=" * 60)
print("PROFILE COMPLETED")
print("=" * 60)