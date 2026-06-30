"""
=============================================================
  export_dashboard.py
  Project : Global E-Commerce Sales — MongoDB & BI

  Reads the processed dataset and produces one CSV per KPI
  table, ready to be uploaded to Power BI online.

  Output files written to:  data/processed/dashboard/

  Run with:
    python scripts/export_dashboard.py

=============================================================
"""

import os
import pandas as pd

# ── paths ─────────────────────────────────────────────────
INPUT  = os.path.join("data", "processed", "ecommerce_sales_dataset_clean.csv")
OUTDIR = os.path.join("data", "processed", "dashboard")

os.makedirs(OUTDIR, exist_ok=True)


# ── load ──────────────────────────────────────────────────
print("Loading dataset...")
df = pd.read_csv(INPUT, parse_dates=["Order_Date"])

print(f"  Rows     : {len(df):,}")
print(f"  Columns  : {list(df.columns)}")
print(f"  Years    : {sorted(df['Year'].unique())}")
print(f"  Statuses : {sorted(df['Order_Status'].unique())}")
print()


# ─────────────────────────────────────────────────────────
#  TABLE 1 — orders_raw
#  The full dataset with a derived Profit_Margin column.
#  Power BI uses this as the base table for slicers and
#  row-level filters (Region, Country, Category, Year).
# ─────────────────────────────────────────────────────────
print("Building orders_raw...")

orders_raw = df.copy()
orders_raw["Profit_Margin_Pct"] = (
    (orders_raw["Profit"] / orders_raw["Revenue"]) * 100
).round(2)

out = os.path.join(OUTDIR, "orders_raw.csv")
orders_raw.to_csv(out, index=False)
print(f"  Written  : {out}  ({len(orders_raw):,} rows)")


# ─────────────────────────────────────────────────────────
#  TABLE 2 — kpi_global
#  Single-row summary: total orders, revenue, profit, AOV.
#  Used for the headline KPI cards at the top of the page.
# ─────────────────────────────────────────────────────────
print("Building kpi_global...")

kpi_global = pd.DataFrame([{
    "Total_Orders"    : len(df),
    "Total_Revenue"   : round(df["Revenue"].sum(), 2),
    "Total_Profit"    : round(df["Profit"].sum(), 2),
    "Avg_Order_Value" : round(df["Revenue"].mean(), 2),
    "Profit_Margin_Pct": round(
        (df["Profit"].sum() / df["Revenue"].sum()) * 100, 2
    ),
    "Delivered_Orders": int((df["Order_Status"] == "Delivered").sum()),
    "Delivery_Rate_Pct": round(
        (df["Order_Status"] == "Delivered").mean() * 100, 2
    ),
}])

out = os.path.join(OUTDIR, "kpi_global.csv")
kpi_global.to_csv(out, index=False)
print(f"  Written  : {out}")
print(f"  Preview  :\n{kpi_global.to_string(index=False)}\n")


# ─────────────────────────────────────────────────────────
#  TABLE 3 — kpi_by_category
#  Revenue, profit, orders and margin grouped by Category.
#  Used for bar/column charts and category-level KPIs.
# ─────────────────────────────────────────────────────────
print("Building kpi_by_category...")

kpi_by_category = (
    df.groupby("Category")
    .agg(
        Orders  = ("Order_ID", "count"),
        Revenue = ("Revenue", "sum"),
        Profit  = ("Profit",  "sum"),
    )
    .reset_index()
)
kpi_by_category["Profit_Margin_Pct"] = (
    (kpi_by_category["Profit"] / kpi_by_category["Revenue"]) * 100
).round(2)
kpi_by_category["Revenue"] = kpi_by_category["Revenue"].round(2)
kpi_by_category["Profit"]  = kpi_by_category["Profit"].round(2)
kpi_by_category = kpi_by_category.sort_values("Revenue", ascending=False)

out = os.path.join(OUTDIR, "kpi_by_category.csv")
kpi_by_category.to_csv(out, index=False)
print(f"  Written  : {out}  ({len(kpi_by_category)} rows)")


# ─────────────────────────────────────────────────────────
#  TABLE 4 — kpi_by_country
#  Revenue, profit and orders grouped by Country.
#  Used for map visuals and country ranking charts.
# ─────────────────────────────────────────────────────────
print("Building kpi_by_country...")

kpi_by_country = (
    df.groupby(["Country", "Region"])
    .agg(
        Orders  = ("Order_ID", "count"),
        Revenue = ("Revenue", "sum"),
        Profit  = ("Profit",  "sum"),
    )
    .reset_index()
)
kpi_by_country["Revenue"] = kpi_by_country["Revenue"].round(2)
kpi_by_country["Profit"]  = kpi_by_country["Profit"].round(2)
kpi_by_country = kpi_by_country.sort_values("Revenue", ascending=False)

out = os.path.join(OUTDIR, "kpi_by_country.csv")
kpi_by_country.to_csv(out, index=False)
print(f"  Written  : {out}  ({len(kpi_by_country)} rows)")


# ─────────────────────────────────────────────────────────
#  TABLE 5 — kpi_monthly_trend
#  Revenue and orders per Year + Month.
#  Used for the time-series line chart.
# ─────────────────────────────────────────────────────────
print("Building kpi_monthly_trend...")

kpi_monthly_trend = (
    df.groupby(["Year", "Month"])
    .agg(
        Orders  = ("Order_ID", "count"),
        Revenue = ("Revenue", "sum"),
        Profit  = ("Profit",  "sum"),
    )
    .reset_index()
)

# Readable label like "2023-04" for the X axis
kpi_monthly_trend["Period"] = (
    kpi_monthly_trend["Year"].astype(str)
    + "-"
    + kpi_monthly_trend["Month"].astype(str).str.zfill(2)
)
kpi_monthly_trend["Revenue"] = kpi_monthly_trend["Revenue"].round(2)
kpi_monthly_trend["Profit"]  = kpi_monthly_trend["Profit"].round(2)
kpi_monthly_trend = kpi_monthly_trend.sort_values(["Year", "Month"])

out = os.path.join(OUTDIR, "kpi_monthly_trend.csv")
kpi_monthly_trend.to_csv(out, index=False)
print(f"  Written  : {out}  ({len(kpi_monthly_trend)} rows)")


# ─────────────────────────────────────────────────────────
#  TABLE 6 — kpi_by_payment
#  Orders and revenue split by Payment_Method.
#  Used for donut / pie chart.
# ─────────────────────────────────────────────────────────
print("Building kpi_by_payment...")

kpi_by_payment = (
    df.groupby("Payment_Method")
    .agg(
        Orders  = ("Order_ID", "count"),
        Revenue = ("Revenue", "sum"),
    )
    .reset_index()
)
kpi_by_payment["Revenue"]   = kpi_by_payment["Revenue"].round(2)
kpi_by_payment["Share_Pct"] = (
    (kpi_by_payment["Orders"] / len(df)) * 100
).round(2)
kpi_by_payment = kpi_by_payment.sort_values("Orders", ascending=False)

out = os.path.join(OUTDIR, "kpi_by_payment.csv")
kpi_by_payment.to_csv(out, index=False)
print(f"  Written  : {out}  ({len(kpi_by_payment)} rows)")


# ─────────────────────────────────────────────────────────
#  TABLE 7 — kpi_by_status
#  Order count by Order_Status.
#  Used for the status KPI / donut chart.
# ─────────────────────────────────────────────────────────
print("Building kpi_by_status...")

kpi_by_status = (
    df.groupby("Order_Status")
    .agg(
        Orders  = ("Order_ID", "count"),
        Revenue = ("Revenue", "sum"),
    )
    .reset_index()
)
kpi_by_status["Revenue"]   = kpi_by_status["Revenue"].round(2)
kpi_by_status["Share_Pct"] = (
    (kpi_by_status["Orders"] / len(df)) * 100
).round(2)

out = os.path.join(OUTDIR, "kpi_by_status.csv")
kpi_by_status.to_csv(out, index=False)
print(f"  Written  : {out}  ({len(kpi_by_status)} rows)")


# ─────────────────────────────────────────────────────────
#  TABLE 8 — kpi_by_shipping
#  Orders and revenue by Shipping_Method.
# ─────────────────────────────────────────────────────────
print("Building kpi_by_shipping...")

kpi_by_shipping = (
    df.groupby("Shipping_Method")
    .agg(
        Orders  = ("Order_ID", "count"),
        Revenue = ("Revenue", "sum"),
    )
    .reset_index()
)
kpi_by_shipping["Revenue"]   = kpi_by_shipping["Revenue"].round(2)
kpi_by_shipping["Share_Pct"] = (
    (kpi_by_shipping["Orders"] / len(df)) * 100
).round(2)

out = os.path.join(OUTDIR, "kpi_by_shipping.csv")
kpi_by_shipping.to_csv(out, index=False)
print(f"  Written  : {out}  ({len(kpi_by_shipping)} rows)")


# ─────────────────────────────────────────────────────────
#  SUMMARY
# ─────────────────────────────────────────────────────────
print()
print("=" * 54)
print("  Export complete")
print("=" * 54)

files = sorted(os.listdir(OUTDIR))
for f in files:
    path = os.path.join(OUTDIR, f)
    size = os.path.getsize(path)
    print(f"  {f:<35} {size:>8,} bytes")

print()
print(f"Upload all files in  {OUTDIR}/  to Power BI online.")
print()
