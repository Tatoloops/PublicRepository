#!/usr/bin/env bash

set -e

echo "========================================"
echo "Removing previous database..."
echo "========================================"

mongosh mongodb/00_drop_database.js

echo

echo "========================================"
echo "Creating database..."
echo "========================================"

mongosh mongodb/00_create_database.js

echo

echo "========================================"
echo "Importing dataset..."
echo "========================================"

mongoimport \
    --db ecommerce \
    --collection orders \
    --type csv \
    --headerline \
    --file data/processed/ecommerce_sales_dataset_clean.csv

echo

echo "========================================"
echo "Finished"
echo "========================================"

mongosh mongodb/00_show_database.js