#!/bin/bash

# Get the folder number from argument
num=$1

# Validate input
if [[ ! $num =~ ^[0-9]+$ ]] || (( num < 0 || num > 9 )); then
    echo "Usage: ./make-run [0-9]"
    exit 1
fi

# Go to exercise directory
cd ex$num || exit 1

# Make clean first
make clean || true

# Compile
make || exit 1

# Run the program
./main || exit 1

make clean

# Go back to original directory
cd ..
