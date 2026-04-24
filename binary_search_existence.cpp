#include <bits/stdc++.h>
using namespace std;

bool right(vector<int> arr, int num) {
    for (int i = 0; i < (int)arr.size(); i++)
        if (arr[i] == num) return true;
    return false;
}

bool exist(vector<int> arr, int num) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (arr[mid] == num) return true;
        if (arr[mid] > num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N = 100;
    int V = 1000;
    int testTime = 500000;
    cout << "测试开始\n";
    while (testTime--) {
        int n = rand() % N + 1;
        int v = rand() % V + 1;
        vector<int> arr;
        for (int i = 0; i < n; i++) arr.push_back(rand() % v + 1);
        sort(arr.begin(), arr.end());
        int num = rand() % v + 1;
        if (right(arr, num) != exist(arr, num)) cout << "出错了！\n";
    }
    cout << "测试结束\n";
    return 0;
}
