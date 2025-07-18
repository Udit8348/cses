#include <bits/stdc++.h>

/**
 * 
 *  Basic program that shows how to parse command line arguments to a cpp program.
 *  The output of this program is each arg printed on its own line.
 *  Remember the first argument is always the executable.
 *  `argc` is the number of arguments since c arrays do not store length
 *  `argv` is the array of char*'s (strings) that hold the actual args
 */

int main(int argc, char* argv[]) {

    // basic command line arg parsing
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

}