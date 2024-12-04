# Bellman-Ford-Algorithm-Implementation
This repository contains an implementation of the Bellman-Ford algorithm for finding the shortest paths from a single source vertex to all other vertices in a weighted graph. The algorithm also detects negative weight cycles.

## Features

- Implements the Bellman-Ford algorithm.
- Detects negative weight cycles in the graph.
- Prints the shortest distances and paths from the source vertex to all other vertices.

## Requirements

- C++11 or higher
- CMake 3.0 or higher

## Building the Project

1. Clone the repository:
   ```sh
   git clone <repository_url>
   cd <repository_directory>
2. Create a build directory and navigate into it:
mkdir build
cd build

3. Run CMake to configure the project:
cmake ..

4. Build the project:
cmake --build .

## Running the Program
After building the project, you can run the executable:
./BellmanFord

## Example
The provided main function demonstrates the usage of the Bellman-Ford algorithm with a sample graph:

int V = 5; // Number of vertices
int E = 8; // Number of edges
std::vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
};

bellmanFord(V, E, edges, 0);

## License
This project is licensed under the MIT License. See the LICENSE file for details.
