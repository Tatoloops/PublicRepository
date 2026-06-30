#!/usr/bin/env python3
"""
=========================================================
MongoDB Engine - Data Processing & Analytics

Usage:
  python mongodb/mongo_engine.py mongodb/actions/insert.json
  python mongodb/mongo_engine.py mongodb/queries/q3_high_revenue.json
  python mongodb/mongo_engine.py mongodb/aggregations/summary.json
=========================================================
"""

import argparse
import json
from pathlib import Path
from pymongo import MongoClient
import pprint

DATABASE = "ecommerce"
COLLECTION = "orders"

def connect():
    client = MongoClient("mongodb://localhost:27017/")
    return client[DATABASE][COLLECTION]

def load_json(path):
    with open(path, encoding="utf-8") as f:
        return json.load(f)

def execute_insert(collection, config):
    if "documents" in config:
        result = collection.insert_many(config["documents"])
        print(f"Inserted {len(result.inserted_ids)} documents.")
    else:
        result = collection.insert_one(config["document"])
        print(f"Inserted ID: {result.inserted_id}")

def execute_find(collection, config):
    query_filter = config.get("filter", {})
    projection = config.get("projection")
    sort_config = config.get("sort")
    limit = config.get("limit")

    cursor = collection.find(query_filter, projection)
    
    if sort_config:
        # PyMongo requires sort to be a list of tuples: [("field", 1)]
        sort_list = [(k, v) for k, v in sort_config.items()]
        cursor = cursor.sort(sort_list)
        
    if limit:
        cursor = cursor.limit(limit)

    count = 0
    for doc in cursor:
        pprint.pprint(doc)
        count += 1

    print(f"\nDocuments shown: {count}")

def execute_update(collection, config):
    # Defaulting to update_many for wider analytical updates
    result = collection.update_many(
        config.get("filter", {}),
        config.get("update", {})
    )
    print(f"Matched : {result.matched_count}")
    print(f"Modified: {result.modified_count}")

def execute_delete(collection, config):
    result = collection.delete_many(config.get("filter", {}))
    print(f"Deleted: {result.deleted_count}")

def execute_aggregate(collection, config):
    pipeline = config.get("pipeline", [])
    cursor = collection.aggregate(pipeline)
    
    count = 0
    for doc in cursor:
        pprint.pprint(doc)
        count += 1
        
    print(f"\nAggregated results: {count}")

def main():
    parser = argparse.ArgumentParser(description="MongoDB Execution Engine")
    parser.add_argument("json", help="Path to JSON config file (action, query, or aggregation)")
    args = parser.parse_args()

    try:
        config = load_json(args.json)
    except FileNotFoundError:
        print(f"Error: File '{args.json}' not found.")
        return
    except json.JSONDecodeError as e:
        print(f"Error parsing JSON: {e}")
        return

    collection = connect()
    action = config.get("action", "").lower()

    print(f"\n=== EXECUTING ACTION: {action.upper()} ===")
    print("=" * 45)

    if action == "insert":
        execute_insert(collection, config)
    elif action in ["read", "find"]:
        execute_find(collection, config)
    elif action == "update":
        execute_update(collection, config)
    elif action == "delete":
        execute_delete(collection, config)
    elif action == "aggregate":
        execute_aggregate(collection, config)
    else:
        raise ValueError(f"Unknown action: '{action}'. Allowed: insert, find/read, update, delete, aggregate.")

if __name__ == "__main__":
    main()