# Quick Usage

## 1. Profile dataset

```bash
python scripts/profile_dataset.py
```

---

## 2. Clean dataset

```bash
python scripts/clean_dataset.py
```

---

## 3. Import into MongoDB

```bash
source mongodb/import.sh
```

---

## 4. CRUD

Insert

```bash
python mongodb/mongo_engine.py mongodb/actions/insert.json
```

Read

```bash
python mongodb/mongo_engine.py mongodb/actions/read.json
```

Update

```bash
python mongodb/mongo_engine.py mongodb/actions/update.json
```

Delete

```bash
python mongodb/mongo_engine.py mongodb/actions/delete.json
```

---

## 5. Queries

```bash
python mongodb/mongo_engine.py mongodb/queries/q1_country.json

python mongodb/mongo_engine.py mongodb/queries/q3_high_revenue.json

python mongodb/mongo_engine.py mongodb/queries/q4_delivered_2024.json
```

---

## 6. Aggregations

```bash
python mongodb/mongo_engine.py mongodb/aggregations/summary.json

python mongodb/mongo_engine.py mongodb/aggregations/revenue_by_category.json

python mongodb/mongo_engine.py mongodb/aggregations/monthly_revenue.json

python mongodb/mongo_engine.py mongodb/aggregations/profit_margin.json
```

---

## 7. Export CSV for Power BI

```bash
python dashboard/export_dashboard.py
```