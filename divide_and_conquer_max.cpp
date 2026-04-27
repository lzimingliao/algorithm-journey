#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int arr[MAXN];

int f(int l, int r) {
    if (l == r) return arr[l];
    int mid = (l + r) >> 1;
    return max(f(l, mid), f(mid + 1, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << f(0, n - 1) << "\n";

    return 0;
}