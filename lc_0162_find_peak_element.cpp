#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        int l = 1, r = n - 2;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            if (nums[mid] < nums[mid - 1])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution obj;
    cout << obj.findPeakElement(nums) << "\n";
    return 0;
}
