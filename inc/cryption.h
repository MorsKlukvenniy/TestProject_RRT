#ifndef CRYPTION_H
#define CRYPTION_H

#include <gcrypt.h>

typedef enum key_length
{
    KEY_128,
    KEY_192,
    KEY_256
} key_length;


void aes_init(key_length k_len);
void aes_encrypt (char * str_in, char * str_out, int len);
void aes_decrypt (char * str_in, char * str_out, int len);

#endif //CRYPTION_H
