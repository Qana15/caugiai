#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

// Hàm tính độ sâu tối thiểu của cây nhị phân
int minDepth(TreeNode* root) {
    if (!root) return 0;
    
    // Nếu nút là lá, trả về 1
    if (!root->left && !root->right) return 1;
    
    // Nếu không có con trái, chỉ duyệt qua con phải
    if (!root->left) return minDepth(root->right) + 1;
    
    // Nếu không có con phải, chỉ duyệt qua con trái
    if (!root->right) return minDepth(root->left) + 1;
    
    // Duyệt cả con trái và con phải để lấy độ sâu tối thiểu
    return min(minDepth(root->left), minDepth(root->right)) + 1;
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
        
        // Xây dựng cây từ mảng
        int index = 0;
        TreeNode* root = buildTree(values, index);
        
        // Tính độ sâu tối thiểu và in ra kết quả
        cout << minDepth(root) << endl;
    }
    
    return 0;
}
