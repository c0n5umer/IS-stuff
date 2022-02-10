#define DEBUG 0

#include <iostream>
#include <vector>
using namespace std;

bool is_heap(vector <long long>& vec, int n) {
    bool res = true;

    for (int i = n / 2; i > 0; --i)
        if (vec[2 * i] < vec[i] || vec[2 * i] < vec[i]) {
            res = false;
            break;
        }

    return res;
}

int main() {
    int n;
    bool res;
    vector <long long> vec;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#if !DEBUG
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
#endif

    cin >> n;
    vec.resize(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> vec[i];

    res = is_heap(vec, n);

    if (res)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
