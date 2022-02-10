#include <bits/stdc++.h>

using namespace std;

vector<int> a;

mt19937 m(time(0));

int partition(int l, int r, int pivot) {
    while (l <= r) {
        while (a[l] < pivot) ++l;
        while (a[r] > pivot) --r;
        if (l >= r) break;
        swap(a[l++], a[r--]);
    }
    return r;
}

int kth(int l, int r, int k) {
    uniform_int_distribution<int> g(l, r);
    int pivot = a[g(m)];
    int pos = partition(l, r, pivot);

    if (r - l + 1 == 1) {
        return a[r];
    }
   
    if (k <= pos - l + 1) {
        return kth(l, pos, k);
    }
    else {
        return kth(pos + 1, r, k - (pos - l + 1));
    }
}

signed main() {
    int n, k, A, B, C, a1, a2;

    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);

    ios::sync_with_stdio(0);

    cin >> n >> k >> A >> B >> C >> a1 >> a2;

    a.resize(n + 1);
    a[1] = a1;
    a[2] = a2;

    for (int i = 3; i <= n; ++i) 
        a[i] = A * a[i - 2] + B * a[i - 1] + C;

    cout << kth(1, n, k);
}