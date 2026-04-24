#include <bits/stdc++.h>
using namespace std;

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) cout << ((num >> i) & 1);
    cout << "\n";
}

bool returnTrue() {
    cout << "进入了 returnTrue 函数\n";
    return true;
}

bool returnFalse() {
    cout << "进入了 returnFalse 函数\n";
    return false;
}

void solve() {
    // 非负数
    int a = 78;
    cout << "a 的十进制表示：" << a << "\n";
    cout << "a 的二进制表示: ";
    printBinary(a);

    // 负数
    int b = -6;
    cout << "b 的十进制表示：" << b << "\n";
    cout << "b 的二进制表示: ";
    printBinary(b);

    // 直接写二进制形式
    int c = 0b1001110;
    cout << "c 的十进制表示：" << c << "\n";
    cout << "c 的二进制表示: ";
    printBinary(c);

    // 直接写十六进制形式
    int d = 0x4e;
    cout << "d 的十进制表示：" << d << "\n";
    cout << "d 的二进制表示: ";
    printBinary(d);

    // ~ 按位取反 相反数
    cout << " a 的二进制表示: ";
    printBinary(a);
    cout << "~a 的二进制表示: ";
    printBinary(~a);
    int e = ~a + 1;
    cout << "~a + 1 的十进制表示: " << e << "\n";
    cout << "~a + 1 的二进制表示: ";
    printBinary(e);

    // int 的最小值取相反数, 在二进制中还是自己
    int f = INT_MIN;
    cout << "f 的十进制表示: " << f << "\n";
    cout << "f 的二进制表示: ";
    printBinary(f);
    cout << "-f 的十进制表示: " << -f << "\n";
    cout << "-f 的二进制表示: ";
    printBinary(-f);
    cout << "~f + 1 的十进制表示: " << ~f + 1 << "\n";
    cout << "~f + 1 的二进制表示: ";
    printBinary(~f + 1);

    // | & ^
    int g = 0b0001010;
    int h = 0b0001100;
    cout << "g 的二进制表示: ";
    printBinary(g);
    cout << "h 的二进制表示: ";
    printBinary(h);
    cout << "g | h 的二进制表示: ";
    printBinary(g | h);
    cout << "g & h 的二进制表示: ";
    printBinary(g & h);
    cout << "g ^ h 的二进制表示: ";
    printBinary(g ^ h);

    // 逻辑运算 || && 具有短路特效
    // 位运算 | & ^ 没有短路特效, 会对所有操作数进行计算
    cout << "test1测试开始\n";
    bool test1 = returnTrue() | returnFalse();
    cout << "test1结果: " << test1 << "\n";

    cout << "test2测试开始\n";
    bool test2 = returnTrue() || returnFalse();
    cout << "test2结果: " << test2 << "\n";

    cout << "test3测试开始\n";
    bool test3 = returnFalse() & returnTrue();
    cout << "test3结果: " << test3 << "\n";

    cout << "test4测试开始\n";
    bool test4 = returnFalse() && returnTrue();
    cout << "test4结果: " << test4 << "\n";

    // << >> 左移和右移
    int i = 0b0011010;
    cout << "i 的二进制表示: ";
    printBinary(i);
    cout << "i << 2 的二进制表示: ";
    printBinary(i << 2);
    cout << "i >> 2 的二进制表示: ";
    printBinary(i >> 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
