#include <iostream>
#include <vector>

std::vector<int> circularPath(int n, int m) {
    std::vector<int> path;
    int currentPos = 1;

    for (int i = 0; i < n; ++i) {
        path.push_back(currentPos);
        currentPos = (currentPos + m - 1) % n + 1; 
    }

    return path;
}

int main() {
    int n, m;
    std::cout << "Input n and m: ";
    std::cin >> n >> m;

    std::vector<int> path = circularPath(n, m);

    std::cout << "Path: ";
    for (int i : path) {
        std::cout << i;
    }
    std::cout << std::endl;

    return 0;
}
