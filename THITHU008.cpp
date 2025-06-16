#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    vector<int> profit1(n, 0);
    vector<int> profit2(n, 0);

    // Tính profit1
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        profit1[i] = max(profit1[i - 1], prices[i] - minPrice);
    }

    // Tính profit2
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        profit2[i] = max(profit2[i + 1], maxPrice - prices[i]);
    }

    // Tính lợi nhuận tối đa
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, profit1[i] + profit2[i]);
    }

    return maxProfit;
}

int main() {
    int t;
    cin >> t; // Số lượng test case
    while (t--) {
        int n;
        cin >> n; // Kích thước của mảng
        vector<int> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i]; // Nhập mảng giá
        }
        cout << maxProfit(prices) << endl; // In ra lợi nhuận tối đa
    }
    return 0;
}