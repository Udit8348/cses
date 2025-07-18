#include <bits/stdc++.h>
using namespace std;

void guass_trick(long n, std::vector<long> &nums) {
    long long sum = 0;
    for (auto &n : nums) {
        sum += n;
    }

    // guass's trick determines the sum of the first n numbers in constant time
    long long expected = ((n+1) * n)/2;
    
    // use the difference to determine the sum
    std::cout << expected - sum << std::endl;
}

void xor_identity(long n, std::vector<long> &nums) {
    // xor "undoes" itself resulting in an identity
    int xum = 0;
    for (int i = 1; i <= n; i++) {
        xum ^= i;
    }

    // the missing number will be the xum
    for (auto &ni : nums) {
        xum ^= ni;
    }

    std::cout << xum << std::endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // if a file path is provided as the first argument, read from it instead of stdin
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }

    // read input
    long n;
    cin >> n;
    
    std::vector<long> nums;
    for (int i = 0; i < n - 1; i++) {
        long temp;
        cin >> temp;
        nums.push_back(temp);
    }

    // Missing Number: You are given all numbers between 1,2,...,n except one. Your task is to find the missing number.
    xor_identity(n, nums);

    return 0;
}