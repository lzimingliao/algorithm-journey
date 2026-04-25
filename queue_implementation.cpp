#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

void stl_queue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "stl queue's size: " << q.size() << "\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

void my_queue() {
    int q[MAXN], l = 0, r = 0;
    q[r++] = 1;
    q[r++] = 2;
    q[r++] = 3;

    cout << "my queue's size: " << r - l << "\n";
    while (l < r) {
        cout << q[l++] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stl_queue();
    my_queue();

    return 0;
}