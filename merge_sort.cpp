#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int arr[MAXN], help[MAXN];

void mergeSort(int left, int right) {
    if (left == right) return;
    int mid = left + ((right - left) >> 1);
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) help[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while (i <= mid) help[k++] = arr[i++];
    while (j <= right) help[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = help[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << (i == n - 1 ? '\n' : ' ');

    return 0;
}