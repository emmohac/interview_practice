#!/bin/bash

d=$(pwd)
for file in "$d"/*.cpp
do
    touch $(basename -s .cpp $file).md
    echo "Created $(basename -s .cpp $file).md"
done
