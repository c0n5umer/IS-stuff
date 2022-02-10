#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n;

    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);

    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
        numbers[i] = i + 1;

    for (int i = 0; i < n; i++)
        swap(numbers[i], numbers[i / 2]);

    for (int i = 0; i < n; i++)
        cout << numbers[i] << " ";

    return 0;
}