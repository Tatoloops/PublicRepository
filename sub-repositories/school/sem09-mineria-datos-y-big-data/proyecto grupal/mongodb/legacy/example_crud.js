/*
=========================================================
  MongoDB CRUD Demonstration
  Database  : ecommerce
  Collection: orders

  This script demonstrates the four CRUD operations
  using a single test document that is created,
  read, modified, and then removed at the end.

  Run with:
    mongosh --file mongodb/02_crud.js
=========================================================
*/

use("ecommerce");

// ── identifier used across every operation ─────────────
const TEST_ID = "ORD-DEMO-000001";

// ── helpers ────────────────────────────────────────────
function separator(label) {
    print("\n" + "=".repeat(50));
    print("  " + label);
    print("=".repeat(50));
}


// ══════════════════════════════════════════════════════
//  BASELINE COUNT
// ══════════════════════════════════════════════════════
separator("BASELINE — total documents before demo");
print("Documents in collection:", db.orders.countDocuments());


// ══════════════════════════════════════════════════════
//  CREATE — insertOne
//  Inserts one new order document.
// ══════════════════════════════════════════════════════
separator("CREATE — insertOne");

const newOrder = {
    Order_ID:        TEST_ID,
    Order_Date:      new Date("2026-06-29"),
    Year:            2026,
    Month:           6,
    Region:          "South America",
    Country:         "Chile",
    Category:        "Electronics",
    Product_Name:    "Mechanical Keyboard",
    Unit_Price:      120,
    Quantity:        2,
    Revenue:         240,
    Profit:          80,
    Payment_Method:  "Credit Card",
    Shipping_Method: "Express",
    Order_Status:    "Processing"
};

const insertResult = db.orders.insertOne(newOrder);

print("Acknowledged:", insertResult.acknowledged);
print("Inserted _id:", insertResult.insertedId);


// ══════════════════════════════════════════════════════
//  READ — findOne
//  Retrieves the document we just created.
// ══════════════════════════════════════════════════════
separator("READ — findOne");

const found = db.orders.findOne({ Order_ID: TEST_ID });
printjson(found);


// ══════════════════════════════════════════════════════
//  UPDATE — updateOne with $set
//  Changes the order status and records a delivery date.
// ══════════════════════════════════════════════════════
separator("UPDATE — updateOne ($set)");

const updateResult = db.orders.updateOne(
    { Order_ID: TEST_ID },
    {
        $set: {
            Order_Status:   "Delivered",
            Delivery_Date:  new Date("2026-07-01")
        }
    }
);

print("Matched :", updateResult.matchedCount);
print("Modified:", updateResult.modifiedCount);

print("\nDocument after update:");
printjson(db.orders.findOne({ Order_ID: TEST_ID }));


// ══════════════════════════════════════════════════════
//  DELETE — deleteOne
//  Removes the test document from the collection.
// ══════════════════════════════════════════════════════
separator("DELETE — deleteOne");

const deleteResult = db.orders.deleteOne({ Order_ID: TEST_ID });

print("Deleted count:", deleteResult.deletedCount);

// confirm it is gone
const check = db.orders.findOne({ Order_ID: TEST_ID });
print("Document still exists:", check !== null ? "YES — ERROR" : "NO — confirmed deleted");


// ══════════════════════════════════════════════════════
//  FINAL COUNT
// ══════════════════════════════════════════════════════
separator("FINAL COUNT — must match baseline");
print("Documents in collection:", db.orders.countDocuments());

print("\nCRUD demonstration completed.\n");
