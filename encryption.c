#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 1) {
        printf("Add the file to be encrypted");
    } else {
        char* secret_file_name = argv[1];
        FILE* secret_file_name = fopen(secret_file_name,"r");
    }
}
