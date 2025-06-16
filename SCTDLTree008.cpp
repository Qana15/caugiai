#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

// Hàm kiểm tra xem có đường đi nào có tổng bằng target không
bool hasPathSum(TreeNode* root, int target) {
    if (!root) return false;
    
    // Nếu là nút lá, kiểm tra xem tổng có bằng target không
    if (!root->left && !root->right) {
        return root->val == target;
    }
    
    // Duyệt qua con trái và con phải
    int newTarget = target - root->val;
    return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
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
        
        // Kiểm tra có đường đi nào có tổng bằng target không
        if (hasPathSum(root, target)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    
    return 0;
}
