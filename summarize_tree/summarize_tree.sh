#!/bin/bash
cd $1
echo "Processed all the files from $1"
echo "there were `find -type d -print | wc -l` directories."
echo "there were `find -type f -print | wc -l` files."

