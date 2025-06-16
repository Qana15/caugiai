#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm dựng cây từ mảng giá trị
TreeNode* buildTree(const vector<int>& values, int& index) {
    if (index >= values.size() || values[index] == -1) {
        index++;
        return nullptr;
    }
    TreeNode* node = new TreeNode(values[index++]);
    node->left = buildTree(values, index);
    node->right = buildTree(values, index);
    return node;
}

// Hàm tìm tất cả các đường đi từ gốc đến lá có tổng = target
void findPaths(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& result) {
    if (!root) return;

    // Thêm giá trị nút hiện tại vào đường đi
    path.push_back(root->val);
    target -= root->val;

    // Nếu là nút lá và tổng bằng target, lưu đường đi
    if (!root->left && !root->right && target == 0) {
        result.push_back(path);
    }

    // Duyệt qua con trái và con phải
    findPaths(root->left, target, path, result);
    findPaths(root->right, target, path, result);

    // Quay lại khi duyệt xong con hiện tại
    path.pop_back();
}

int main() {
    int t;
    cin >> t;  // Số lượng testcases
    
    while (t--) {
        vector<int> values;
        int x;
        
        // Đọc các giá trị cho cây
        while (cin >> x) {
            values.push_back(x);
            if (cin.get() == '\n') break;  // Kết thúc dòng
        }
        
        int target;
        cin >> target;  // Đọc số nguyên target
        
        // Xây dựng cây từ mảng
        int index = 0;
        TreeNode* root = buildTree(values, index);
        
        vector<vector<int>> result;
        vector<int> path;
        
        // Tìm tất cả các đường đi có tổng bằng target
        findPaths(root, target, path, result);
        
        if (result.empty()) {
            cout << "0" << endl;
        } else {
            // In tất cả các đường đi
            for (const auto& p : result) {
                cout << "[";
                for (size_t i = 0; i < p.size(); ++i) {
                    cout << p[i];
                    if (i < p.size() - 1) cout << ",";
                }
                cout << "]";
            }
            cout << endl;
        }
    }
    
    return 0;
}
