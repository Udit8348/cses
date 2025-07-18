#include <bits/stdc++.h>

/**
 * 
 *  Basic program that shows different techniques for getting input to solve competitive programming problems.
 *  `cin` cpp style for input (assumes each "buffer" is delimited with whitespaces)
 *  `cout` cpp style for output
 */

int main(int argc, char* argv[]) {

    UNUSED(argc);
    UNUSED(argv);

    // you can cin once, which will block the cmd line and wait for an input
    // std::string name;
    // std::cin >> name;
    // std::cout << name << std::endl;

    // you can get a whole line (skips the cin delimiting)
    // std::string other;
    // getline(std::cin, other);
    // std::cout << other << std::endl;

    // if the number of buffers is unknown
    // std::string other;
    // while(std::cin >> other) {
    //     std::cout << other << std::endl;
    // }
    // hint: need to press ctrl+D to signal EOF
    // std::cout << "Done: no more input or error encountered.\n";

    // c style input, with formatting
    // int a, b;
    // scanf("%d %d", &a, &b);
    // printf("the sum of of a and b is: %d\n", a + b);

    // reading from an input file
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    freopen("./src/io/hello.in", "r", stdin);

    for (int i = 0; i < 3; i++) {
        std::string temp;
        std::cin >> temp;
        std::cout << temp << " ";
    }
    std::cout << std::endl;

    // todo: if you want to learn more about ostreams, ifstreams, streambuf -- those are more cpp styled
}