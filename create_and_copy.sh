#!/bin/bash

# this script is used to create n new folders (first single digit argument of skript)
# of the format ex00, ex01, ex02, ..., ex0n
# and copy the specified files into them (arbitrary number of files following)

# Check if we have at least 2 arguments (number and at least one file)
if [ $# -lt 1 ]; then
    echo "Usage: $0 <last_number 0-9> [file1] [file2] [file3] ..."
    exit 1
fi

# Extract the first argument (the number)
last_number=$1
shift  # Remove first argument, leaving only file paths

# Check if the first argument was a number between 0 and 9
if ! [[ $last_number =~ ^[0-9]$ ]]; then
    echo "Error: First argument must be a single digit (0-9)"
    exit 1
fi

# Check if all specified files exist
for file in "$@"; do
    if [ ! -f "$file" ]; then
        echo "Error: File '$file' does not exist"
        exit 1
    fi
done

# Create folders if needed and copy files
for ((i=0; i<=last_number; i++)); do
    # Create folder name with padding
    folder_name="ex$(printf "%02d" $i)"
    
    # Create the folder if it doesn't exist
    if [ ! -d "$folder_name" ]; then
        mkdir -p "$folder_name"
        echo "Created new folder: $folder_name"
    fi
    
    # Copy each file into the folder
    for file in "$@"; do
        cp "$file" "$folder_name/"
        echo "Copied $(basename "$file") into $folder_name"
    done
done

echo "Done! Created/Updated $((last_number + 1)) folders with ${#@} files"
