#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n+1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        parent[pv] = pu;
        return true;
    }
};

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> parent(n + 1, 0);
    vector<int> cand1, cand2;

    // Bước 1: kiểm tra đỉnh có 2 cha
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        if (parent[v] == 0) {
            parent[v] = u;
        } else {
            // v có hai cha
            cand1 = {parent[v], v};
            cand2 = {u, v};
            edge[1] = 0; // tạm thời bỏ edge thứ 2
        }
    }

    // Bước 2: kiểm tra chu trình dùng DSU
    UnionFind uf(n);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        if (v == 0) continue; // bỏ cạnh cand2
        if (!uf.unite(u, v)) {
            // Nếu có chu trình
            if (cand1.empty()) return edge;
            return cand1;
        }
    }

    // Nếu không có chu trình sau khi bỏ cand2, thì cand2 là lỗi
    return cand2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            cin >> edges[i][0] >> edges[i][1];
        }
        vector<int> result = findRedundantDirectedConnection(edges);
        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}
