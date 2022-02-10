#include <iostream>
#include <vector>
using namespace std;

void heapify(vector <int>& vec, int n, int i) {
    int parent = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && vec[left] < vec[parent])
        parent = left;

    if (right < n && vec[right] < vec[parent])
        parent = right;

    if (parent != i) {
        swap(vec[i], vec[parent]);
        heapify(vec, n, parent);
    }
}

void sift_up(vector <int>& vec, int i) {
    while (vec[i] < vec[(i - 1) / 2] && i != 0) {
        swap(vec[i], vec[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extract_min(vector<int>& numbers) {
    int min;

    min = numbers[0];
    numbers[0] = numbers[numbers.size() - 1];
    numbers.pop_back();
    heapify(numbers, numbers.size(), 0);
    return min;
}

void decreasekey(vector<int>& numbers, int value, int new_value) {
    int i;

    for (i = 0; i < numbers.size(); i++)
        if (numbers[i] == value) {
            numbers[i] = new_value;
            break;
        }

    sift_up(numbers, i);
}

int main() {
    vector <int> numbers;
    vector <int> vec;
    string str;

    freopen("priorityqueue.in", "r", stdin);
    freopen("priorityqueue.out", "w", stdout);

    while (cin >> str) {
        if (str == "push") {
            int temp;
            cin >> temp;
            numbers.push_back(temp);
            vec.push_back(temp);
            sift_up(numbers, numbers.size() - 1);
        }
        else vec.push_back(0);

        if (str == "extract-min") {
            if (numbers.size() == 0)
                cout << "*" << "\n";
            else
                cout << extract_min(numbers) << "\n";
        }

        if (str == "decrease-key") {
            int key, value, old_value;

            cin >> key >> value;
            old_value = vec[key - 1];
            vec[key - 1] = value;
            decreasekey(numbers, old_value, value);
        }
    }
    return 0;
}