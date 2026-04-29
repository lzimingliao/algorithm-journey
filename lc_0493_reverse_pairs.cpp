#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> help(nums.size());
        return process(nums, help, 0, nums.size() - 1);
    }

   private:
    int process(vector<int>& nums, vector<int>& help, int l, int r) {
        if (l >= r) return 0;
        int m = l + ((r - l) >> 1);

        int leftCount = process(nums, help, l, m);
        int rightCount = process(nums, help, m + 1, r);
        int mergeCount = mergeAndCount(nums, help, l, m, r);

        return leftCount + rightCount + mergeCount;
    }

    int mergeAndCount(vector<int>& nums, vector<int>& help, int l, int m, int r) {
        int ans = 0;

        for (int i = l, j = m + 1; i <= m; i++) {
            while (j <= r && (long long)nums[i] > (long long)nums[j] * 2) j++;
            ans += j - m - 1;
        }

        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r) help[k++] = (nums[i] <= nums[j]) ? nums[i++] : nums[j++];

        while (i <= m) help[k++] = nums[i++];
        while (j <= r) help[k++] = nums[j++];

        for (i = l; i <= r; i++) nums[i] = help[i];

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        int result = sol.reversePairs(nums);
        cout << result << "\n";
    }

    return 0;
}