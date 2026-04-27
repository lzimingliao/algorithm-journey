#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
   private:
    vector<int> deque;
    int l, r, sz, limit;

   public:
    MyCircularDeque(int k) {
        limit = k;
        deque.resize(k);
        l = 0;
        r = 0;
        sz = 0;
    }

    bool insertFront(int value) {
        if (sz == limit) return false;
        l = (l - 1 + limit) % limit;
        deque[l] = value;
        sz++;
        return true;
    }

    bool insertLast(int value) {
        if (sz == limit) return false;
        deque[r] = value;
        sz++;
        r = (r + 1) % limit;
        return true;
    }

    bool deleteFront() {
        if (sz == 0) return false;
        l = (l + 1) % limit;
        sz--;
        return true;
    }

    bool deleteLast() {
        if (sz == 0) return false;
        r = (r - 1 + limit) % limit;
        sz--;
        return true;
    }

    int getFront() { return sz == 0 ? -1 : deque[l]; }

    int getRear() { return sz == 0 ? -1 : deque[(r - 1 + limit) % limit]; }

    bool isEmpty() { return sz == 0; }

    bool isFull() { return sz == limit; }
};
