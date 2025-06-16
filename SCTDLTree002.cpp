#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm tạo cây nhị phân từ mảng
TreeNode* buildTree(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    deque<TreeNode*> queue;
    queue.push_back(root);
    
    int index = 1;
    while (index < values.size()) {
        TreeNode* node = queue.front();
        queue.pop_front();
        
        // Xử lý con trái
        if (values[index] != -1) {
            node->left = new TreeNode(values[index]);
            queue.push_back(node->left);
        }
        index++;
        
        // Xử lý con phải
        if (index < values.size() && values[index] != -1) {
            node->right = new TreeNode(values[index]);
            queue.push_back(node->right);
        }
        index++;
    }
    
    return root;
}

// Hàm duyệt cây theo thứ tự ngoằn ngoèo (Zigzag)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};
    
    vector<vector<int>> result;
    deque<TreeNode*> queue;
    queue.push_back(root);
    
    bool leftToRight = true;  // Duyệt từ trái qua phải ở cấp độ đầu tiên
    
    while (!queue.empty()) {
        int levelSize = queue.size();
        vector<int> level;
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = queue.front();
            queue.pop_front();
            level.push_back(node->val);
            
            if (node->left) queue.push_back(node->left);
            if (node->right) queue.push_back(node->right);
        }
        
        // Nếu là cấp độ chẵn, đảo ngược thứ tự
        if (!leftToRight) {
            reverse(level.begin(), level.end());
        }
        
        result.push_back(level);
        leftToRight = !leftToRight;  // Đổi hướng duyệt
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;  // Số lượng test cases
    
    while (t--) {
        vector<int> values;
        int x;
        
        // Đọc các giá trị cho cây
        while (cin >> x) {
            values.push_back(x);
            if (cin.get() == '\n') break;  // Kết thúc dòng
        }
        
        // Xây dựng cây từ mảng
        TreeNode* root = buildTree(values);
        
        // Duyệt cây theo thứ tự ngoằn ngoèo
        vector<vector<int>> result = zigzagLevelOrder(root);
        
        // In kết quả
        for (const auto& level : result) {
            for (size_t i = 0; i < level.size(); i++) {
                cout << level[i];
                if (i < level.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
