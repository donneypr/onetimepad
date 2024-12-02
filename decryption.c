#include <stdio.h>
#include <stdlib.h>

void decrypt(FILE* encrypted_file, FILE* key_file, FILE* decrypted_file) {
    int enc_x;
    while ((enc_x = fgetc(encrypted_file)) != EOF) {
        int key_x = fgetc(key_file);
        if (key_x == EOF) {
            fprintf(stderr, "Error: Key file ended prematurely.\n");
            break;
        }
        int dec_x = enc_x ^ key_x; 
        fputc(dec_x, decrypted_file);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) { 
        printf("Usage: %s <encrypted_file> <key_file>\n", argv[0]);
        return 1;
    }

    FILE* encrypted_file = fopen(argv[1], "r");
    FILE* key_file = fopen(argv[2], "r");
    FILE* decrypted_file = fopen("decrypt.out", "w");

    if (!encrypted_file || !key_file || !decrypted_file) {
        perror("Error opening file");
        if (encrypted_file) fclose(encrypted_file);
        if (key_file) fclose(key_file);
        if (decrypted_file) fclose(decrypted_file);
        return 1;
    }

    decrypt(encrypted_file, key_file, decrypted_file);

    fclose(encrypted_file);
    fclose(key_file);
    fclose(decrypted_file);

    printf("Decryption complete.\n");
    return 0;
}
