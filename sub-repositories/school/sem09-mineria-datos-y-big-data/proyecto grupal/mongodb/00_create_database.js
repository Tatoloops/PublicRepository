/*
Creates the database and the orders collection.

MongoDB creates the database automatically once a collection exists.
*/

use("ecommerce");

db.createCollection("orders");

print("");
print("======================================");
print("Database created successfully");
print("======================================");
print("Database : " + db.getName());
print("Collection: orders");
print("");