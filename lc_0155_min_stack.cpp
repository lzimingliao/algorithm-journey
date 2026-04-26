#include <bits/stdc++.h>
using namespace std;

class MinStack {
   private:
    static const int MAXN = 3e4 + 5;
    int data[MAXN], mins[MAXN], sz;

   public:
    MinStack() { sz = 0; }

    void push(int x) {
        data[sz] = x;
        if (sz == 0)
            mins[sz] = x;
        else
            mins[sz] = std::min(x, mins[sz - 1]);
        sz++;
    }

    void pop() { sz--; }

    int top() { return data[sz - 1]; }

    int getMin() { return mins[sz - 1]; }
};