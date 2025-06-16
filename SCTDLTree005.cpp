#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

// Hàm tính số tiền tối đa có thể cướp được từ cây nhị phân
int robHelper(TreeNode* root, int& maxRob) {
    if (!root) return 0;
    
    // Tính tiền tối đa từ các nút con
    int left = robHelper(root->left, maxRob);
    int right = robHelper(root->right, maxRob);
    
    // Số tiền khi lấy tiền từ nút hiện tại (không lấy từ con trực tiếp)
    int withCurrent = root->val + (root->left ? robHelper(root->left->left, maxRob) + robHelper(root->left->right, maxRob) : 0)
                     + (root->right ? robHelper(root->right->left, maxRob) + robHelper(root->right->right, maxRob) : 0);
    
    // Số tiền khi không lấy tiền từ nút hiện tại (lấy tiền từ các con trực tiếp)
    int withoutCurrent = left + right;
    
    maxRob = max(maxRob, max(withCurrent, withoutCurrent));
    
    return max(withCurrent, withoutCurrent);
}

int maxRobbery(const vector<int>& values) {
    int index = 0;
    TreeNode* root = buildTree(values, index);
    int maxRob = 0;
    robHelper(root, maxRob);
    return maxRob;
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
        
        // Tính toán số tiền tối đa mà tên trộm có thể lấy
        cout << maxRobbery(values) << endl;
    }
    
    return 0;
}
