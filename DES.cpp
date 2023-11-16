#include <stdio.h>
#include <stdint.h>
void des_encrypt(uint64_t *block, uint64_t *key);
void generate_subkeys(uint64_t *key, uint64_t *subkeys);
int main() {
    uint64_t plaintext_block = 0x0123456789ABCDEF; 
    uint64_t key = 0x133457799BBCDFF1; 
    uint64_t subkeys[16];
    generate_subkeys(&key, subkeys);
    des_encrypt(&plaintext_block, subkeys);
    printf("Encrypted block: %016llX\n", plaintext_block);
    return 0;
}
void des_encrypt(uint64_t *block, uint64_t *subkeys) {
}
void generate_subkeys(uint64_t *key, uint64_t *subkeys) {

}

