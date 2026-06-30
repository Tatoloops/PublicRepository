/*
Displays all databases and collections.
*/

print("");
print("======================================");
print("DATABASES");
print("======================================");

db.adminCommand({ listDatabases: 1 }).databases.forEach(database => {
    print(database.name);
});

print("");

use("ecommerce");

print("======================================");
print("CURRENT DATABASE");
print("======================================");

print(db.getName());

print("");

print("======================================");
print("COLLECTIONS");
print("======================================");

db.getCollectionNames().forEach(collection => {
    print(collection);
});

print("");

print("======================================");
print("DOCUMENT COUNT");
print("======================================");

print(db.orders.countDocuments());

print("");