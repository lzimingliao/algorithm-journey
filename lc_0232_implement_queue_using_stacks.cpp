#include <bits/stdc++.h>
using namespace std;

class MyQueue {
   private:
    static const int MAXN = 105;
    int stk_in[MAXN], stk_out[MAXN];
    int top_in, top_out;

    inline void inToOut() {
        if (top_out == 0)
            while (top_in > 0) stk_out[top_out++] = stk_in[--top_in];
    }

   public:
    MyQueue() {
        top_in = 0;
        top_out = 0;
    }

    void push(int x) {
        stk_in[top_in++] = x;
        inToOut();
    }

    int pop() {
        inToOut();
        return stk_out[--top_out];
    }

    int peek() {
        inToOut();
        return stk_out[top_out - 1];
    }

    bool empty() { return top_in == 0 && top_out == 0; }
};