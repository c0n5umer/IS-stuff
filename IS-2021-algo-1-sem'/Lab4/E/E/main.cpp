#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

vector<int> a;
int n;
int leftSearch(int x) {
    int L = -1, R = n - 1;
    while (R - L > 1) {
        int M = R + L >> 1;
        if (a[M] >= x) {
            R = M;
        }
        else {
            L = M;
        }
    }
    if (a[R] != x) return -1;
    return R + 1;
}

int rightSearch(int x) {
    int L = 0, R = n;
    while (R - L > 1) {
        int M = R + L >> 1;
        if (a[M] > x) {
            R = M;
        }
        else {
            L = M;
        }
    }
    if (a[L] != x) return -1;
    return L + 1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int query;
        cin >> query;
        cout << leftSearch(query) << " " << rightSearch(query) << '\n';
    }

    return 0;
}