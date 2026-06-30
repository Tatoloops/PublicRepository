/*
=========================================================
  MongoDB CRUD Manager
  Database  : ecommerce
  Collection: orders

  HOW TO USE
  ──────────
  1. Choose an action by setting the ACTION variable:
       "INSERT"  — add a new order
       "READ"    — find orders matching a filter
       "UPDATE"  — modify one existing order
       "DELETE"  — remove one order

  2. Fill in the corresponding section below with your
     own data.

  3. Run with:
       mongosh --file mongodb/04_manage.js

  The script will execute only the selected action and
  print the result.
=========================================================
*/

use("ecommerce");

// ══════════════════════════════════════════════════════
//  CHOOSE WHAT TO DO
//  Set ACTION to one of: "INSERT" | "READ" | "UPDATE" | "DELETE"
// ══════════════════════════════════════════════════════

const ACTION = "INSERT";   // ← change this line


// ══════════════════════════════════════════════════════
//  INSERT
//  Fill in the document you want to add.
//  Order_ID must be unique (check with a READ first).
// ══════════════════════════════════════════════════════

const INSERT_DOCUMENT = {
    Order_ID:        "ORD-CUSTOM-00001",   // unique identifier
    Order_Date:      new Date("2026-06-29"),
    Year:            2026,
    Month:           6,
    Region:          "South America",
    Country:         "Chile",
    Category:        "Electronics",        // Electronics | Clothing | Books | ...
    Product_Name:    "My Product",
    Unit_Price:      99.99,
    Quantity:        1,
    Revenue:         99.99,
    Profit:          30.00,
    Payment_Method:  "Credit Card",        // Credit Card | PayPal | Bank Transfer
    Shipping_Method: "Standard",           // Standard | Express | Free
    Order_Status:    "Processing"          // Processing | Shipped | Delivered | Cancelled
};


// ══════════════════════════════════════════════════════
//  READ
//  Set READ_FILTER to narrow down which documents to
//  return. Use {} to return all (limited to 20 below).
//
//  Examples:
//    { Country: "Chile" }
//    { Category: "Electronics", Year: 2024 }
//    { Revenue: { $gt: 1000 } }
// ══════════════════════════════════════════════════════

const READ_FILTER = { Country: "Chile" };

// Fields to show — set to {} to show everything
const READ_PROJECTION = {
    Order_ID: 1, Country: 1, Category: 1,
    Revenue: 1, Order_Status: 1, _id: 0
};

// Maximum number of results to display
const READ_LIMIT = 20;


// ══════════════════════════════════════════════════════
//  UPDATE
//  SET UPDATE_FILTER to identify the document and
//  UPDATE_FIELDS to the values you want to change.
//
//  Only the fields listed in UPDATE_FIELDS will change;
//  everything else stays the same.
// ══════════════════════════════════════════════════════

const UPDATE_FILTER = { Order_ID: "ORD-CUSTOM-00001" };

const UPDATE_FIELDS = {
    Order_Status:   "Shipped",
    Shipping_Method: "Express"
};


// ══════════════════════════════════════════════════════
//  DELETE
//  Set DELETE_FILTER to identify the document to remove.
//  The script will only delete ONE document (deleteOne).
//
//  Safety: the script will ask you to confirm the
//  document before deleting — just check the READ output.
// ══════════════════════════════════════════════════════

const DELETE_FILTER = { Order_ID: "ORD-CUSTOM-00001" };


// ══════════════════════════════════════════════════════
//  ENGINE — do not edit below this line
// ══════════════════════════════════════════════════════

function separator(label) {
    print("\n" + "─".repeat(50));
    print("  " + label);
    print("─".repeat(50));
}

print("\n" + "═".repeat(50));
print("  CRUD MANAGER  —  action: " + ACTION);
print("═".repeat(50));

if (ACTION === "INSERT") {

    separator("Inserting document");
    printjson(INSERT_DOCUMENT);

    const result = db.orders.insertOne(INSERT_DOCUMENT);

    print("\nResult:");
    print("  acknowledged :", result.acknowledged);
    print("  insertedId   :", result.insertedId);
    print("\nVerification — document as stored:");
    printjson(db.orders.findOne({ Order_ID: INSERT_DOCUMENT.Order_ID }));


} else if (ACTION === "READ") {

    separator("Reading documents with filter");
    print("Filter:"); printjson(READ_FILTER);
    print("Limit:", READ_LIMIT);

    const docs = db.orders.find(READ_FILTER, READ_PROJECTION).limit(READ_LIMIT);
    let count = 0;

    print("\nResults:");
    docs.forEach(doc => { printjson(doc); count++; });

    print("\nDocuments returned:", count);
    print(
        "Total matching (no limit):",
        db.orders.countDocuments(READ_FILTER)
    );


} else if (ACTION === "UPDATE") {

    separator("Reading document before update");

    const before = db.orders.findOne(UPDATE_FILTER);

    if (before === null) {
        print("ERROR: No document matched the filter. Nothing was updated.");
        print("Filter used:"); printjson(UPDATE_FILTER);
    } else {
        print("Before:"); printjson(before);

        const result = db.orders.updateOne(
            UPDATE_FILTER,
            { $set: UPDATE_FIELDS }
        );

        print("\nUpdate result:");
        print("  matched :", result.matchedCount);
        print("  modified:", result.modifiedCount);

        print("\nAfter:");
        printjson(db.orders.findOne(UPDATE_FILTER));
    }


} else if (ACTION === "DELETE") {

    separator("Reading document before deletion");

    const target = db.orders.findOne(DELETE_FILTER);

    if (target === null) {
        print("ERROR: No document matched the filter. Nothing was deleted.");
        print("Filter used:"); printjson(DELETE_FILTER);
    } else {
        print("Document to be deleted:"); printjson(target);

        const result = db.orders.deleteOne(DELETE_FILTER);

        print("\nDelete result:");
        print("  acknowledged:", result.acknowledged);
        print("  deleted     :", result.deletedCount);

        const check = db.orders.findOne(DELETE_FILTER);
        print("\nDocument still exists:", check !== null ? "YES — ERROR" : "NO — deleted successfully");
    }


} else {

    print('ERROR: Unknown ACTION "' + ACTION + '"');
    print('Valid values: "INSERT" | "READ" | "UPDATE" | "DELETE"');

}

print("\nDone.\n");
