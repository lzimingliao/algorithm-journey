#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

void stl_stack() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "stl stack's size: " << s.size() << "\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

void my_stack() {
    int s[MAXN], top = 0;
    s[top++] = 1;
    s[top++] = 2;
    s[top++] = 3;

    cout << "my stack's size: " << top << "\n";
    while (top > 0) {
        cout << s[--top] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stl_stack();
    my_stack();

    return 0;
}