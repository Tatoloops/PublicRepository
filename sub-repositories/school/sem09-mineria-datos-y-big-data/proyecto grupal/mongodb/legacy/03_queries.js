/*
=========================================================
  MongoDB Queries
  Database  : ecommerce
  Collection: orders

  Covers the five queries required by the assignment:
    Q1 — Simple   : orders by country
    Q2 — Simple   : orders by category
    Q3 — Filter   : high-value orders
    Q4 — Filter   : delivered orders in a date range
    Q5 — Sorted   : top 10 orders by revenue (descending)

  Run with:
    mongosh --file mongodb/03_queries.js
=========================================================
*/

use("ecommerce");

// ── helper ─────────────────────────────────────────────
function section(title, objective) {
    print("\n" + "═".repeat(54));
    print("  " + title);
    print("  Objective: " + objective);
    print("═".repeat(54));
}


// ══════════════════════════════════════════════════════
//  Q1 — SIMPLE
//  Count orders grouped by Country.
//  Useful for identifying the most active markets.
// ══════════════════════════════════════════════════════
section(
    "Q1 — Orders per Country",
    "Identify which countries generate the most orders."
);

db.orders.aggregate([
    { $group: { _id: "$Country", total_orders: { $sum: 1 } } },
    { $sort:  { total_orders: -1 } }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  Q2 — SIMPLE
//  Count orders grouped by Category.
//  Shows which product categories are most popular.
// ══════════════════════════════════════════════════════
section(
    "Q2 — Orders per Category",
    "Determine the most ordered product categories."
);

db.orders.aggregate([
    { $group: { _id: "$Category", total_orders: { $sum: 1 } } },
    { $sort:  { total_orders: -1 } }
]).forEach(printjson);


// ══════════════════════════════════════════════════════
//  Q3 — FILTER
//  Orders where Revenue exceeds 500.
//  Identifies high-value transactions.
// ══════════════════════════════════════════════════════
section(
    "Q3 — High-Value Orders (Revenue > 500)",
    "Find orders that generate significant revenue."
);

const highValue = db.orders.find(
    { Revenue: { $gt: 500 } },
    { Order_ID: 1, Country: 1, Category: 1, Revenue: 1, _id: 0 }
).limit(10);

print("Showing first 10 results:");
highValue.forEach(printjson);

print(
    "Total high-value orders:",
    db.orders.countDocuments({ Revenue: { $gt: 500 } })
);


// ══════════════════════════════════════════════════════
//  Q4 — FILTER
//  Delivered orders placed in 2024.
//  Useful for analysing completed sales in a given year.
// ══════════════════════════════════════════════════════
section(
    "Q4 — Delivered Orders in 2024",
    "Retrieve completed orders from a specific period."
);

const delivered2024 = db.orders.find(
    {
        Order_Status: "Delivered",
        Year: 2024
    },
    { Order_ID: 1, Country: 1, Revenue: 1, Order_Status: 1, _id: 0 }
).limit(10);

print("Showing first 10 results:");
delivered2024.forEach(printjson);

print(
    "Total delivered orders in 2024:",
    db.orders.countDocuments({ Order_Status: "Delivered", Year: 2024 })
);


// ══════════════════════════════════════════════════════
//  Q5 — SORTED
//  Top 10 orders by Revenue, highest first.
//  Highlights the most profitable individual transactions.
// ══════════════════════════════════════════════════════
section(
    "Q5 — Top 10 Orders by Revenue (descending)",
    "Rank the ten most profitable orders in the dataset."
);

db.orders.find(
    {},
    { Order_ID: 1, Country: 1, Category: 1, Revenue: 1, Profit: 1, _id: 0 }
)
.sort({ Revenue: -1 })
.limit(10)
.forEach(printjson);


print("\nAll queries completed.\n");
