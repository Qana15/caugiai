#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm xây dựng cây từ mảng theo level-order
TreeNode* buildTree(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || arr[0] == -1) return nullptr;

    vector<TreeNode*> nodes(n, nullptr);
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1)
            nodes[i] = new TreeNode(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (nodes[i] != nullptr) {
            int leftIdx = 2 * i + 1;
            int rightIdx = 2 * i + 2;
            if (leftIdx < n)
                nodes[i]->left = nodes[leftIdx];
            if (rightIdx < n)
                nodes[i]->right = nodes[rightIdx];
        }
    }

    return nodes[0];
}

// Hàm DFS để tìm đường từ gốc đến lá
void dfs(TreeNode* node, vector<int>& path, vector<string>& result) {
    if (!node) return;

    path.push_back(node->val);

    if (!node->left && !node->right) {
        // Tạo chuỗi từ đường đi
        string s = to_string(path[0]);
        for (int i = 1; i < path.size(); ++i) {
            s += "->" + to_string(path[i]);
        }
        result.push_back(s);
    } else {
        dfs(node->left, path, result);
        dfs(node->right, path, result);
    }

    path.pop_back();
}

vector<string> findPaths(TreeNode* root) {
    vector<string> result;
    vector<int> path;
    dfs(root, path, result);
    return result;
}

// === Main function ===
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        TreeNode* root = buildTree(arr);
        vector<string> paths = findPaths(root);

        if (paths.empty()) {
            cout << 0 << endl;
        } else {
            for (const string& s : paths) {
                cout << s << endl;
            }
        }
    }

    return 0;
}
