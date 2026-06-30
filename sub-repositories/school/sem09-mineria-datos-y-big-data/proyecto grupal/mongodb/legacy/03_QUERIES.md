# Queries

Database: `ecommerce` — Collection: `orders`

---

## Q1 — Orders per Country (Simple)

**Objective**
Identify which countries generate the highest volume of orders to understand market reach.

**Code**
```javascript
db.orders.aggregate([
    { $group: { _id: "$Country", total_orders: { $sum: 1 } } },
    { $sort:  { total_orders: -1 } }
])
```

**Expected result shape**
```json
{ "_id": "United States", "total_orders": 312 }
{ "_id": "Germany",       "total_orders": 287 }
...
```

**Interpretation**
The output ranks every country present in the dataset by order volume.
Countries at the top are the most active markets and should receive priority attention in sales strategy and inventory planning.

---

## Q2 — Orders per Category (Simple)

**Objective**
Determine which product categories attract the most orders to guide purchasing and marketing decisions.

**Code**
```javascript
db.orders.aggregate([
    { $group: { _id: "$Category", total_orders: { $sum: 1 } } },
    { $sort:  { total_orders: -1 } }
])
```

**Expected result shape**
```json
{ "_id": "Electronics", "total_orders": 1842 }
{ "_id": "Clothing",    "total_orders": 1601 }
...
```

**Interpretation**
Categories with the highest order count represent the core of the business.
A category with many orders but low revenue may indicate low-ticket products sold in volume, while a category with fewer orders but high revenue points to premium products.

---

## Q3 — High-Value Orders (Filter: Revenue > 500)

**Objective**
Find individual orders that exceed a revenue threshold of 500 to identify the most profitable transactions.

**Code**
```javascript
db.orders.find(
    { Revenue: { $gt: 500 } },
    { Order_ID: 1, Country: 1, Category: 1, Revenue: 1, _id: 0 }
).limit(10)
```

**Expected result shape**
```json
{ "Order_ID": "ORD-004521", "Country": "Japan", "Category": "Electronics", "Revenue": 1240 }
...
```

**Count**
```javascript
db.orders.countDocuments({ Revenue: { $gt: 500 } })
```

**Interpretation**
High-value orders represent a disproportionate share of total revenue despite being fewer in number.
Monitoring them separately allows the business to apply targeted logistics (express shipping, dedicated support) and loyalty incentives to the customers who placed them.

---

## Q4 — Delivered Orders in 2024 (Filter: status + year)

**Objective**
Retrieve orders that were successfully completed during the year 2024 to evaluate fulfilment performance for that period.

**Code**
```javascript
db.orders.find(
    { Order_Status: "Delivered", Year: 2024 },
    { Order_ID: 1, Country: 1, Revenue: 1, Order_Status: 1, _id: 0 }
).limit(10)
```

**Count**
```javascript
db.orders.countDocuments({ Order_Status: "Delivered", Year: 2024 })
```

**Interpretation**
The number of delivered orders in a given year is a key operational indicator.
A high ratio of delivered vs. total orders signals a reliable supply chain.
Comparing this figure across years reveals whether fulfilment capacity has improved or declined.

---

## Q5 — Top 10 Orders by Revenue (Sorted, descending)

**Objective**
Rank the ten highest-revenue individual orders to understand the ceiling of transaction value in the dataset.

**Code**
```javascript
db.orders.find(
    {},
    { Order_ID: 1, Country: 1, Category: 1, Revenue: 1, Profit: 1, _id: 0 }
)
.sort({ Revenue: -1 })
.limit(10)
```

**Expected result shape**
```json
{ "Order_ID": "ORD-007823", "Country": "USA", "Category": "Electronics", "Revenue": 4980, "Profit": 1200 }
...
```

**Interpretation**
The top 10 transactions often share common attributes: category, country, or payment method.
Identifying these patterns allows the business to replicate the conditions that produce high-value sales.
The gap between Revenue and Profit in these orders also reveals which products carry the best margin at scale.
