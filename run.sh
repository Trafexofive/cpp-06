#!/bin/bash

# Get the folder number or command from argument
num=$1

# If arg is "clean" then clean all directories
if [ "$num" == "clean" ]; then
    for i in {0..9}; do
        cd ex0$i || continue
        make clean
        cd ..
    done
    exit 0
fi

# If arg is "fclean" then force clean all directories
if [ "$num" == "fclean" ]; then
    for i in {0..9}; do
        cd ex0$i || continue
        make fclean
        cd ..
    done
    exit 0
fi

# Validate input day number (must be a number between 0 and 9)
if [[ ! $num =~ ^[0-9]+$ ]] || (( num < 0 || num > 9 )); then
    echo "Usage: ./make-run.sh [0-9] [optional arguments for main]"
    exit 1
fi

# Remove the day number argument so that remaining parameters are passed to main
shift

# Change to the corresponding exercise directory
cd ex$num || exit 1

# Run make clean once before compiling (ignore error if it fails)
make clean || true

# Compile the program
make || exit 1

# Run the program with any additional arguments
./main "$@" || exit 1

# Clean up after execution
make clean

# Return to the original directory
cd ..
