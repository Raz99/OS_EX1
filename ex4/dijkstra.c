// C Program to Implement Shortest Path Algorithm
// From GeeksForGeeks: https://www.geeksforgeeks.org/shortest-path-algorithm-in-c/#implementation-of-dijkstras-algorithm-in-c
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to find the vertex with the minimum distance
// value from the set of vertices not yet included in the
// shortest path tree
int findminDistance(int dist[], int included[], int V) {
    int min = INT_MAX, min_index;

    // Traverse all vertices to find the vertex with the
    // minimum distance value
    for (int v = 0; v < V; v++) {
        if (included[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t INF\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

// Function that implements Dijkstra's algorithm
void DijkstrasAlgo(int **graph, int src, int V) {
    // Array to store the minimum distance from source node
    // to the current node
    int dist[V];
    // Array to keep track of included nodes
    int included[V];

    // Initialize all distances as INFINITE and included as
    // false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        included[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed
        int u = findminDistance(dist, included, V);

        // Mark the selected vertex as included
        included[u] = 1;

        // Update the distance of all the adjacent vertices
        // of the selected vertex
        for (int v = 0; v < V; v++) {
            // Skip non-existent edges (represented by INT_MAX)
            if (!included[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

int main() {
    int V, E;

    for (;;) { // Infinite loop for accepting new graphs dynamically
        printf("-- Dijkstra's Algorithm --\n");
        printf("Enter the number of vertices: ");
        scanf("%d", &V);

        if (V <= 0) {
            printf("Invalid number of vertices.\n");
            continue;
        }

        // Dynamically allocate memory for the graph
        int **graph = (int **)malloc(V * sizeof(int *));
        for (int i = 0; i < V; i++) {
            graph[i] = (int *)malloc(V * sizeof(int));
        }

        // Initialize the graph to INT_MAX (no edge) and diagonal to 0
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (i == j) {
                    graph[i][j] = 0; // Distance to self is 0
                } else {
                    graph[i][j] = INT_MAX; // No edge
                }
            }
        }

        printf("Enter the number of edges: ");
        scanf("%d", &E);

        // Clear the input buffer
        while (getchar() != '\n');

        if (E < 0 || E > V * (V - 1) / 2) { // Validate number of edges
            printf("Invalid number of edges.\n");
            for (int i = 0; i < V; i++) free(graph[i]);
            free(graph);
            continue;
        }

        if (E != 0) printf("Enter the edges in the format: src dest weight\n");
        for (int i = 0; i < E; i++) {
            int src, dest, weight;

            // Read the edge input in format of (src dest weight)
            if (scanf("%d %d %d", &src, &dest, &weight) != 3) {
                printf("Invalid input format. Enter exactly three integers separated by spaces (src dest weight).\n");
                while (getchar() != '\n'); // Clear the buffer
                i--; // Request input for this edge again
                continue;
            }

            if (src < 0 || src >= V || dest < 0 || dest >= V || src == dest || weight < 0) {
                printf("Invalid edge (self-loop, out of range or negative weight), try again.\n");
                i--; // Request input for this edge again
                continue;
            }

            if (graph[src][dest] != INT_MAX) {
                printf("Edge already exists, pick another combination of vertices.\n");
                i--; // Request input for this edge again
                continue;
            }

            graph[src][dest] = weight;
            graph[dest][src] = weight; // Assuming the graph is undirected
        }

        int src;
        printf("Enter the source vertex: ");
        scanf("%d", &src);

        while (src < 0 || src >= V) {
            printf("Invalid source vertex.\n");
            printf("Enter the source vertex: ");
            scanf("%d", &src);
        }

        DijkstrasAlgo(graph, src, V);

        // Free dynamically allocated memory
        for (int i = 0; i < V; i++) free(graph[i]);
        free(graph);

        char choice;
        printf("\nYou are about to create a new graph. Enter '0' if you want to stop the running of the script or enter something else to continue: ");
        scanf(" %c", &choice);
        if (choice == '0') {
            break;
        }
    }

    return 0;
}