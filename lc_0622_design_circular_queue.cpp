#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    int q[1005];
    int l, r, sz, limit;

   public:
    MyCircularQueue(int k) : l(0), r(0), sz(0), limit(k) {}

    bool enQueue(int value) {
        if (sz == limit) return false;
        q[r] = value;
        if (++r == limit) r = 0;
        sz++;
        return true;
    }

    bool deQueue() {
        if (sz == 0) return false;
        if (++l == limit) l = 0;
        sz--;
        return true;
    }

    int Front() { return sz == 0 ? -1 : q[l]; }

    int Rear() { return sz == 0 ? -1 : q[r == 0 ? limit - 1 : r - 1]; }

    bool isEmpty() { return sz == 0; }

    bool isFull() { return sz == limit; }
};