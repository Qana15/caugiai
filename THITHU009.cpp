#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX; // Union
        }
    }

private:
    vector<int> parent;
};

int main() {
    int t;
    cin >> t; // Số lượng test case
    while (t--) {
        int n;
        cin >> n; // Số lượng cạnh
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            edges[i].resize(2);
            cin >> edges[i][0] >> edges[i][1]; // Nhập các cạnh
        }

        UnionFind uf(n);
        vector<int> edgeToRemove;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (uf.find(u) == uf.find(v)) {
                // Nếu u và v đã thuộc cùng một tập hợp, có chu trình
                edgeToRemove = edge; // Lưu lại cạnh cuối cùng tạo chu trình
            } else {
                uf.unionSets(u, v); // Kết hợp hai đỉnh
            }
        }

        // In ra cạnh cần loại bỏ
        cout << edgeToRemove[0] << " " << edgeToRemove[1] << endl;
    }
    return 0;
}