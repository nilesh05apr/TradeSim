#!/bin/sh

set -e pipefail

# Remove the old build directory if it exists
if [ -d "build" ]; then
  rm -rf build
fi

# Create a new build directory
mkdir -p build

# Copy the source files to the build directory
cd build

# Compile the source files
cmake ..

# Build the project
make

# Run the project
./TradeSim