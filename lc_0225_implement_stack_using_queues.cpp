#include <bits/stdc++.h>
using namespace std;

class MyStack {
   private:
    static const int MAXN = 10005;
    int queue[MAXN], l, r;

   public:
    MyStack() {
        l = 0;
        r = 0;
    }

    void push(int x) {
        int sz = r - l;
        queue[r++] = x;
        for (int i = 0; i < sz; i++) queue[r++] = queue[l++];
    }

    int pop() { return queue[l++]; }

    int top() { return queue[l]; }

    bool empty() { return l == r; }
};