#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1e5 + 5;

int arr[MAXN], help[MAXN];

ll merge(int l, int m, int r) {
    ll ans = 0, sum = 0;
    for (int i = l, j = m + 1; j <= r; j++) {
        while (i <= m && arr[i] <= arr[j]) sum += arr[i++];
        ans += sum;
    }
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) help[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while (i <= m) help[k++] = arr[i++];
    while (j <= r) help[k++] = arr[j++];
    for (i = l; i <= r; i++) arr[i] = help[i];
    return ans;
}

ll smallSum(int l, int r) {
    if (l == r) return 0;
    int m = (l + r) >> 1;
    return smallSum(l, m) + smallSum(m + 1, r) + merge(l, m, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << smallSum(0, n - 1) << "\n";
    return 0;
}