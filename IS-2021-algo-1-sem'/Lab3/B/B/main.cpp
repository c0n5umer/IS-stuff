#define DEBUG 0

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector <int> &vec, int n, int i) {
    int parent = i, left = 2 * i + 1, right = 2 * i + 2; 

    if (left < n && vec[left] > vec[parent])
        parent = left;

    if (right < n && vec[right] > vec[parent])
        parent = right;

    if (parent != i) {
        swap(vec[i], vec[parent]);
        heapify(vec, n, parent);
    }
}

void heap_sort(vector <int> &vec, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(vec, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

int main() {
    int n;
    vector <int> vec;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#if !DEBUG
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
#endif

    cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    heap_sort(vec, n);

    for (int i = 0; i < n; ++i)
        cout << vec[i] << " ";

    return 0;
}