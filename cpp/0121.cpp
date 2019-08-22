#include<vector>
#include<iostream>
#include<bitset>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty())
            return 0;

        int min_el = prices[0];
        int max_stock = 0;
        for (int i = 1; i < prices.size(); ++i) {
            max_stock = max(max_stock, prices[i] - min_el);
            min_el = min(min_el, prices[i]);
        }
        return max_stock;
    }
};

int main() {
    auto res = Solution().maxSum(3);


    return 0;
}
