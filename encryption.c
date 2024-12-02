#include <stdio.h>
#include <stdlib.h>

void encrypt(FILE* secret_file, FILE* encrypted_file, FILE* key_file) {
    int x;
    while ((x = fgetc(secret_file)) != EOF) {
        int key = rand();
        int encrypted_x = x ^ key;

        fputc(key, key_file);
        fputc(encrypted_x, encrypted_file);

    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Add the file to be encrypted");
    } else {
        char* secret_file_name = argv[1];
        FILE* secret_file = fopen(secret_file_name,"r");
        FILE* encrypted_file  = fopen("encrypted.out", "w");
        FILE* key_file = fopen("key.out", "w");

        encrypt(secret_file, encrypted_file, key_file);
        fclose(secret_file);
        fclose(encrypted_file);
        fclose(key_file);
    }
}
