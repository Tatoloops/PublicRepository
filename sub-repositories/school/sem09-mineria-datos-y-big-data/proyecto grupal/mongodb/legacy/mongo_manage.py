#!/usr/bin/env python3

"""
=========================================================
MongoDB CRUD Manager

Usage

python mongo_manage.py actions/insert.json
python mongo_manage.py actions/read.json
python mongo_manage.py actions/update.json
python mongo_manage.py actions/delete.json

=========================================================
"""

from pathlib import Path
import argparse
import json

from pymongo import MongoClient


DATABASE = "ecommerce"
COLLECTION = "orders"


def connect():
    client = MongoClient("mongodb://localhost:27017/")
    return client[DATABASE][COLLECTION]


def load_json(path):

    with open(path, encoding="utf-8") as f:
        return json.load(f)


def insert(collection, config):

    result = collection.insert_one(config["document"])

    print("\nINSERT")
    print("=" * 40)

    print("Inserted ID:", result.inserted_id)


def read(collection, config):

    cursor = collection.find(
        config.get("filter", {}),
        config.get("projection")
    )

    limit = config.get("limit")

    if limit:
        cursor = cursor.limit(limit)

    print("\nREAD")
    print("=" * 40)

    count = 0

    for doc in cursor:
        print(doc)
        count += 1

    print()
    print("Documents shown:", count)


def update(collection, config):

    result = collection.update_one(

        config["filter"],

        {
            "$set": config["update"]
        }

    )

    print("\nUPDATE")
    print("=" * 40)

    print("Matched :", result.matched_count)
    print("Modified:", result.modified_count)


def delete(collection, config):

    result = collection.delete_one(

        config["filter"]

    )

    print("\nDELETE")
    print("=" * 40)

    print("Deleted:", result.deleted_count)


def main():

    parser = argparse.ArgumentParser()

    parser.add_argument(

        "json",

        help="CRUD action json"

    )

    args = parser.parse_args()

    config = load_json(args.json)

    collection = connect()

    action = config["action"].upper()

    if action == "INSERT":

        insert(collection, config)

    elif action == "READ":

        read(collection, config)

    elif action == "UPDATE":

        update(collection, config)

    elif action == "DELETE":

        delete(collection, config)

    else:

        raise ValueError(f"Unknown action: {action}")


if __name__ == "__main__":
    main()