#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll currentTimeMillis() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

void bubbleSort(vector<int>& arr) {
    int n = (int)arr.size();
    int end = n - 1, i = 0;
    while (end > 0) {
        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        if (i < end - 1)
            i++;
        else {
            end--;
            i = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 1. 生成一个长度为 n 的数组, 元素值在 1 到 v 之间, 且相邻元素不相等
    int n = 10, v = 4;
    vector<int> arr1(n);
    arr1[0] = rand() % v + 1;
    for (int i = 1; i < n; i++) {
        do {
            arr1[i] = rand() % v + 1;
        } while (arr1[i] == arr1[i - 1]);
    }
    for (int num : arr1) cout << num << " ";
    cout << "\n=========\n";

    // 2. C++ 动态数组
    vector<int> arr2;
    arr2.push_back(5);
    arr2.push_back(4);
    arr2.push_back(9);
    arr2[1] = 6;
    cout << arr2[1] << "\n=========\n";

    // 3. 冒泡排序测试
    vector<int> arr = {64, 31, 78, 0, 5, 7, 103};
    bubbleSort(arr);
    for (int num : arr) cout << num << " ";
    cout << "\n==========\n";

    // 4. 复杂度测试
    int N = 200000;
    ll start_time, end_time;

    volatile ll sum1 = 0;
    cout << "测试开始\n";
    start_time = currentTimeMillis();
    // 调和级数, 时间复杂度 O(N * log N)
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            sum1++;
        }
    }
    end_time = currentTimeMillis();
    cout << "测试结束, 运行时间: " << end_time - start_time << " ms\n";

    volatile ll sum2 = 0;
    cout << "测试开始\n";
    start_time = currentTimeMillis();
    // 等差数列, 时间复杂度 O(N^2)
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            sum2++;
        }
    }
    end_time = currentTimeMillis();
    cout << "测试结束, 运行时间: " << end_time - start_time << " ms\n";

    return 0;
}