#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int wealth[MAXN];
bool hasMoney[MAXN];

double calculateGini(int n) {
    int sumOfAbsoluteDifferences = 0;
    int sumOfWealth = 0;
    for (int i = 0; i < n; i++) {
        sumOfWealth += wealth[i];
        for (int j = 0; j < n; j++) sumOfAbsoluteDifferences += abs(wealth[i] - wealth[j]);
    }
    return (double)sumOfAbsoluteDifferences / (2 * n * sumOfWealth);
}

void experiment(int n, int t) {
    fill(wealth, wealth + n, 100);
    while (t--) {
        for (int i = 0; i < n; i++) hasMoney[i] = wealth[i] > 0;
        for (int i = 0; i < n; i++) {
            if (!hasMoney[i]) continue;
            int other;
            do {
                other = rand() % n;
            } while (other == i);
            wealth[other]++;
            wealth[i]--;
        }
    }

    sort(wealth, wealth + n);
    cout << "列出每个人的财富 (贫穷到富有): \n";
    for (int i = 0; i < n; i++) cout << wealth[i] << (i % 10 == 9 ? "\n" : " ");
    cout << "这个社会的基尼系数为: " << fixed << setprecision(4) << calculateGini(n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << "一个社会的基尼系数是一个在 0 ~ 1 之间的小数\n";
    cout << "基尼系数为 0 代表所有人的财富完全一样\n";
    cout << "基尼系数为 1 代表有 1 个人掌握了全社会的财富\n";
    cout << "基尼系数越小, 代表社会财富分布越均衡; 越大则代表财富分布越不均衡\n";
    cout << "在 2022 年, 世界各国的平均基尼系数为 0.44\n";
    cout << "目前普遍认为, 当基尼系数到达 0.5 时\n";
    cout << "就意味着社会贫富差距非常大, 分布非常不均匀\n";
    cout << "社会可能因此陷入危机, 比如大量的犯罪或者经历社会动荡\n";
    cout << "测试开始\n";

    int n = 100, t = 1000000;

    cout << "人数: " << n << "\n轮数: " << t << "\n";
    experiment(n, t);
    cout << "测试结束\n";

    return 0;
}
