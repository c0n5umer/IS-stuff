#include <iostream>
#include <vector>

typedef struct tree {
    long long value;
    long long left;
    long long right;
} tree;

void check(std::vector <tree>& vec, long long root, bool* status, long long min, long long max) {
    
    if (vec[root].value <= min || vec[root].value >= max)
        *status = false;

    if (vec[root].left != 0)
        check(vec, vec[root].left, status, min, vec[root].value);
    if (vec[root].right != 0)
        check(vec, vec[root].right, status, vec[root].value, max);
}

int main(void) {
    std::vector <tree> vec;
    long long n;
    bool status = true;

    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);

    std::cin >> n;
    vec.resize(n + 1);

    if (n == 0)
        std::cout << "YES";
    else {
        for (long long i = 1; i <= n; ++i)
            std::cin >> vec[i].value >> vec[i].left >> vec[i].right;

        check(vec, 1, &status, -1000000000, 1000000000);
        if (status)
            std::cout << "YES";
        else
            std::cout << "NO";
    }
    return 0;
}