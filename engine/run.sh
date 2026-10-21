# Configure when build settings or dependencies change
cmake -S . -B build -G Ninja

# Compile after changing code
cmake --build build

# Run the server
./build/outpost_server