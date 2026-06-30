/*
=========================================================
  MongoDB Aggregation Pipelines
  Database  : ecommerce
  Collection: orders

  These queries produce the summary metrics used in the
  Power BI dashboard.  Run them to verify the numbers
  before connecting Power BI.

  Run with:
    mongosh --file mongodb/05_aggregations.js
=========================================================
*/

use("ecommerce");

function section(title) {
    print("\n" + "═".repeat(54));
    print("  " + title);
    print("═".repeat(54));
}


// ══════════════════════════════════════════════════════
//  KPI 1 — Global summary
//  Single document with the four headline numbers.
// ══════════════════════════════════════════════════════
section("KPI 1 — Global Summary");

db.orders.aggregate([
    {
        $group: {
            _id:           null,
            total_orders:  { $sum: 1 },
            total_revenue: { $sum: "$Revenue" },
            total_profit:  { $sum: "$Profit" },
            avg_order_value: { $avg: "$Revenue" }
        }
    },
    {
        $project: {
            _id: 0,
            total_orders:    1,
            total_revenue:   { $round: ["$total_revenue",   2] },
            total_profit:    { $round: ["$total_profit",    2] },
            avg_order_value: { $round: ["$avg_order_value", 2] }
        }
    }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  KPI 2 — Revenue and Profit by Category
// ══════════════════════════════════════════════════════
section("KPI 2 — Revenue and Profit by Category");

db.orders.aggregate([
    {
        $group: {
            _id:     "$Category",
            revenue: { $sum: "$Revenue" },
            profit:  { $sum: "$Profit" },
            orders:  { $sum: 1 }
        }
    },
    {
        $project: {
            category: "$_id",
            _id:      0,
            revenue:  { $round: ["$revenue", 2] },
            profit:   { $round: ["$profit",  2] },
            orders:   1
        }
    },
    { $sort: { revenue: -1 } }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  KPI 3 — Revenue by Country (top 10)
// ══════════════════════════════════════════════════════
section("KPI 3 — Revenue by Country (top 10)");

db.orders.aggregate([
    {
        $group: {
            _id:     "$Country",
            revenue: { $sum: "$Revenue" },
            orders:  { $sum: 1 }
        }
    },
    {
        $project: {
            country: "$_id",
            _id:     0,
            revenue: { $round: ["$revenue", 2] },
            orders:  1
        }
    },
    { $sort:  { revenue: -1 } },
    { $limit: 10 }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  KPI 4 — Revenue per Year and Month (trend line)
// ══════════════════════════════════════════════════════
section("KPI 4 — Monthly Revenue Trend");

db.orders.aggregate([
    {
        $group: {
            _id:     { year: "$Year", month: "$Month" },
            revenue: { $sum: "$Revenue" },
            orders:  { $sum: 1 }
        }
    },
    {
        $project: {
            _id:     0,
            year:    "$_id.year",
            month:   "$_id.month",
            revenue: { $round: ["$revenue", 2] },
            orders:  1
        }
    },
    { $sort: { year: 1, month: 1 } }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  KPI 5 — Order Status distribution
// ══════════════════════════════════════════════════════
section("KPI 5 — Order Status Distribution");

db.orders.aggregate([
    {
        $group: {
            _id:    "$Order_Status",
            count:  { $sum: 1 }
        }
    },
    {
        $project: {
            status: "$_id",
            _id:    0,
            count:  1
        }
    },
    { $sort: { count: -1 } }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  KPI 6 — Payment Method distribution
// ══════════════════════════════════════════════════════
section("KPI 6 — Payment Method Distribution");

db.orders.aggregate([
    {
        $group: {
            _id:    "$Payment_Method",
            count:  { $sum: 1 },
            revenue: { $sum: "$Revenue" }
        }
    },
    {
        $project: {
            method:  "$_id",
            _id:     0,
            count:   1,
            revenue: { $round: ["$revenue", 2] }
        }
    },
    { $sort: { count: -1 } }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  KPI 7 — Profit margin by Category
//  Profit margin = (Profit / Revenue) * 100
// ══════════════════════════════════════════════════════
section("KPI 7 — Profit Margin by Category (%)");

db.orders.aggregate([
    {
        $group: {
            _id:     "$Category",
            revenue: { $sum: "$Revenue" },
            profit:  { $sum: "$Profit" }
        }
    },
    {
        $project: {
            category:      "$_id",
            _id:           0,
            revenue:       { $round: ["$revenue", 2] },
            profit:        { $round: ["$profit",  2] },
            margin_pct: {
                $round: [
                    { $multiply: [
                        { $divide: ["$profit", "$revenue"] },
                        100
                    ]},
                    2
                ]
            }
        }
    },
    { $sort: { margin_pct: -1 } }
]).forEach(printjson);


print("\nAll aggregations completed.\n");
