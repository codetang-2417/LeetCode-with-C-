#include <bits/stdc++.h>

int n, m;

const int maxn=1e6+1; // 对于ACM模式来讲，通用做法都是在函数外部开辟大数组，减少程序的运行时间，并且不需要传递参数，更方便
int diff[maxn], need[maxn];// diif即表示差分数组，need是根据差分数组计算得到的每天需要租借的教室数量
int a[maxn], d[maxn];// a表示可以租借的教室数量
int l[maxn], r[maxn];// 每个订单的左右天数边界

bool not_overflow(int index) {
    memset(diff,0,sizeof(diff));// 只有完整的定义才能使用sizeof计算数组大小
    for (int i = 1; i <= index; i++) {// 只计算固定边界中的差分数组，因此后续也只考虑固定边界中的need数组，从而完成二分查找的条件之一：有序性；当每一次都从头开始计算是否满足闲置数量大于租借数量，就能够判断这个过程中是否有不满足条件的情况，如果有不满足，说明这个区间里就有我们需要寻找的订单，因此可以通过二分法紧缩区间，直到最后找到这个订单。
        diff[l[i]] += d[i];// 根据每个订单的开始边界，计算何时增加教室数量
        diff[r[i]+1] -= d[i];// 根据每个订单的结束边界，计算何时减少教室数量，由于需要在租借的再往后一天才能结束，因此加1天
    }

    for (int i = 1; i <= n; i++) {
        need[i] = need[i - 1] + diff[i];// 逆用差分数组，相当于计算前缀和，得到数组每个元素的值，再次计算前缀和，就可以得到真正的前缀和。
        if (need[i] > a[i])//如果供小于求，则说明有订单需要修改，返回false,告知二分过程需要锁紧边界。
            return false;
    }
    return true;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= m; i++) std::cin >> d[i] >> l[i] >> r[i];

    int left = 1, right = m;
    int mid;
    if (not_overflow(n)) std::cout << "0"; // 未溢出，则所有订单都满足
    else {
        std::cout << -1 << "\n";
        while (left < right) {
            mid = (left + right) >> 1;
            if (not_overflow(mid)) {// 当订单满足，则左边界left到mid的所有订单都满足，此时收紧左边界
                left = mid+1;
            }
            else{
                right = mid;
            }
        }

        std::cout << left << "\n";
    }

    return 0;
}