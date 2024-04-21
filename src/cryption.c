#include "cryption.h"
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

static gcry_cipher_hd_t crypt_desc;
static gcry_error_t     gcryError;

void aes_init(key_length k_len)
{
    srand(time(NULL));
    int l;
    switch (k_len)
    {
    case KEY_128:
        l = 16;
        break;
    case KEY_192:
        l = 24;
        break;
    case KEY_256:
        l = 32;
        break;
    default:
        l = 32;
        break;
    }
    uint8_t key[l];
    int i = 0;
    for (i = 0; i < l; i++)
    {
        int r = rand();
        key[i] = ((r & 0xff) + ((r >> 8) & 0xff) + ((r >> 16) & 0xff) + ((r >> 24) & 0xff)) & 0xff;
        r = rand();
    }
    gcryError = gcry_cipher_open(&crypt_desc, GCRY_CIPHER_AES + k_len, GCRY_CIPHER_MODE_ECB, 0);

    if (gcryError) {
        printf("gcry_cipher_open failed:  %s/%s\n",
           gcry_strsource(gcryError), gcry_strerror(gcryError));
        return;
    }

    gcryError = gcry_cipher_setkey(crypt_desc, key, l);

    if (gcryError) {
        printf("gcry_cipher_setkey failed:  %s/%s\n",
           gcry_strsource(gcryError), gcry_strerror(gcryError));
        return;
    }
}

void aes_encrypt(const char * str_in, char * str_out, int len)
{
    gcryError = gcry_cipher_encrypt(crypt_desc, str_out, len, str_in, len);
    if (gcryError) {
        printf("gcry_cipher_encrypt failed:  %s/%s\n",
           gcry_strsource(gcryError), gcry_strerror(gcryError));
        return;
    }
}

void aes_decrypt(const char *str_in, char * str_out, int len)
{
    gcryError = gcry_cipher_decrypt(crypt_desc, str_out, len, str_in, len);
    if (gcryError) {
        printf("gcry_cipher_decrypt failed:  %s/%s\n",
           gcry_strsource(gcryError), gcry_strerror(gcryError));
        return;
    }
}
