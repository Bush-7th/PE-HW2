#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

int main() {
    int node_count;
    std::cin >> node_count;
    std::cin.ignore();

    std::vector<std::vector<int>> graph(node_count + 1);
    for (int i = 0; i < node_count; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream row(line);

        int node;
        row >> node;

        int neighbor;
        while (row >> neighbor)
            graph[node].push_back(neighbor);
    }

    int source, target;
    std::cin >> source >> target;

    std::vector<int> dist(node_count + 1, -1);
    std::queue<int> queue;
    dist[source] = 0;
    queue.push(source);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        if (node == target)
            break;

        for (int neighbor : graph[node])
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                queue.push(neighbor);
            }
    }

    std::cout << dist[target] << '\n';
}
