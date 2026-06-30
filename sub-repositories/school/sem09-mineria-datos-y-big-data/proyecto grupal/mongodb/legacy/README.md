# MongoDB Scripts

Database: `ecommerce`  
Collection: `orders`

All scripts run with:
```bash
mongosh --file mongodb/<script>.js
```

---

## Script index

| File | Purpose |
|---|---|
| `00_check_connection.js` | Verify mongosh can reach the server |
| `00_create_database.js` | Create the database and collection |
| `00_drop_database.js` | Drop the database (destructive) |
| `00_show_database.js` | Show current databases and collections |
| `import.sh` | Drop → create → import the CSV dataset |
| `02_crud.js` | CRUD demonstration with a test document |
| `03_queries.js` | Five required academic queries |
| `04_manage.js` | **Interactive CRUD** — edit and run your own operations |
| `05_aggregations.js` | Summary metrics (KPIs) used by the dashboard |

---

## Quick start

```bash
# 1. Load the dataset
source mongodb/import.sh

# 2. Run the CRUD demonstration (for the report)
mongosh --file mongodb/02_crud.js

# 3. Run the required queries
mongosh --file mongodb/03_queries.js

# 4. Run the KPI aggregations
mongosh --file mongodb/05_aggregations.js
```

---

## Using 04_manage.js

Open the file and change two things:

**1. Set the action**
```javascript
const ACTION = "INSERT";   // INSERT | READ | UPDATE | DELETE
```

**2. Fill in the data for that action**

- `INSERT` → edit `INSERT_DOCUMENT`
- `READ`   → edit `READ_FILTER` (and optionally `READ_LIMIT`)
- `UPDATE` → edit `UPDATE_FILTER` and `UPDATE_FIELDS`
- `DELETE` → edit `DELETE_FILTER`

Then run:
```bash
mongosh --file mongodb/04_manage.js
```

The script prints a before/after view for UPDATE and DELETE so you can take a screenshot for the evidence folder.
