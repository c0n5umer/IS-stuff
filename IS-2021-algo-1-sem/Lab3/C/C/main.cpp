#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(vector <string> &vec, int l, int m, int r, int n, int index) {
    int i = l, j = m + 1, k = l;
    vector <string> temp;

    temp.resize(n);

    while (i <= m && j <= r) {
        if (vec[i][index] <= vec[j][index]) 
            temp[k++] = vec[i++];
        else
            temp[k++] = vec[j++];
    }

    while (i <= m) 
        temp[k++] = vec[i++];

    while (j <= r) 
        temp[k++] = vec[j++];

    for (int i = l; i <= r; i++) 
        vec[i] = temp[i];
}

void merge_sort(vector <string> &vec, int l, int r, int n, int index) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(vec, l, m, n, index);
        merge_sort(vec, m + 1, r, n, index);
        merge(vec, l, m, r, n, index);
    }
}

int main() {
    int n, m, k;
    vector <string> vec;

    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);

    cin >> n >> m >> k;
    vec.resize(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    for (int i = 0; i < k; i++) {
        int index = m - i - 1;
        merge_sort(vec, 0, n - 1, n, index);
    }

    for (int k = 0; k < n; k++)
        cout << vec[k] << "\n";
}