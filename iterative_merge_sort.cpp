#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int arr[MAXN], help[MAXN];

void mergeSort(int length) {
    for (int left, mid, right, step = 1; step < length; step <<= 1) {
        left = 0;
        while (left < length) {
            mid = left + step - 1;
            if (mid + 1 >= length) break;
            right = min(mid + step, length - 1);
            int i = left, j = mid + 1, k = left;
            while (i <= mid && j <= right) help[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
            while (i <= mid) help[k++] = arr[i++];
            while (j <= right) help[k++] = arr[j++];
            for (i = left; i <= right; i++) arr[i] = help[i];
            left = right + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(n);
    for (int i = 0; i < n; i++) cout << arr[i] << (i == n - 1 ? '\n' : ' ');

    return 0;
}