#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // if a file path is provided as the first argument, read from it instead of stdin
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }

    // read input
    long long n;
    cin >> n;

    // Weird Algorithm
    while(n!=1) {
        std::cout << n << " ";
        if (n%2) {
            n = (n * 3) + 1;
        } else {
            n = n / 2;
        }
    }
    std::cout << n << std::endl;

    return 0;
}