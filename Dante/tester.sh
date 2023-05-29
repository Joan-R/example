#!/bin/bash

set -euo pipefail

echo "Hello, welcome to our generator !"

if [ $# -lt 2 ] || [ $# -gt 3 ]; then
    echo ""
    echo "Error: Invalid number of arguments. Usage: $0 <arg1> <arg2> [arg3]"
    echo "Refer to README if needed."
    exit 1
fi

if ! command -v ./generator/generator &> /dev/null; then
    echo "Error: 'generator' command not found."
    exit 1
fi

if [ $# -eq 2 ]; then
    echo "Generating imperfect maze..."
    time ./generator/generator "$1" "$2" > "maps/maze.txt"; echo ""
else
    echo "Generating maze..."
    time ./generator/generator "$1" "$2" "$3" > "maps/maze.txt"; echo ""
fi

if ! command -v ./solver/solver &> /dev/null; then
    echo "Error: 'solver' command not found."
    exit 1
fi

echo "Solving maze..."; echo ""
time ./solver/solver "maps/maze.txt" | sed 's/o/\o033[31mo\o033[0m/g'; echo ""

echo "Maze generated !"
