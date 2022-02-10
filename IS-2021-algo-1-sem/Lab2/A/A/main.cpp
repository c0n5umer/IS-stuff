#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void merge_sort(vector <int>& vec, int left, int right);

int main(void)
{
    int n;
    
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> n;

    vector <int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    merge_sort(vec, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";

    return 0;
}

void merge(vector <int> &vec, int left, int mid, int right)
{
    int it1 = 0, it2 = 0, len1 = mid - left + 1, len2 = right - mid, res_counter = 0;
    vector <int> result(len1 + len2);

    while (it1 < len1 && it2 < len2)
    {
        if (vec[left + it1] < vec[mid + 1 + it2])
            result[res_counter++] = vec[left + it1++];
        else
            result[res_counter++] = vec[mid + 1 + it2++];
    }

    while (it1 < len1)
        result[res_counter++] = vec[left + it1++];

    while (it2 < len2)
        result[res_counter++] = vec[mid + 1 + it2++];

    for (int i = 0; i < len1 + len2; i++)
        vec[left + i] = result[i];
}

void merge_sort(vector <int> &vec, int left, int right)
{
    int mid = floor((left + right) * 0.5);

    if (left >= right)
        return;

    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}