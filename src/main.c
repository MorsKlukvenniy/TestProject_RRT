#include "cryption.h"
#include "usermessages.h"
#include <stdio.h>

void log (char* log, char * s)
{
    printf("%s", log);
    int i = 0;
    for (i = 0; i < STR_LENGTH_MAX; i++)
    {
        printf("%x", s[i]);
    }
    printf("\n\r");
}

int main ()
{
//	printf("Enter user name\n\r");
    aes_init(KEY_128);
    char login[STR_LENGTH_MAX] = "MorsKlukvenniy\0";
    char password[STR_LENGTH_MAX] = "91756243\0";
    char out [STR_LENGTH_MAX];
    char out2 [STR_LENGTH_MAX];
    memset(out, 0, STR_LENGTH_MAX);
    memset(out2, 0, STR_LENGTH_MAX);
    aes_encrypt(login, out, STR_LENGTH_MAX);
    aes_decrypt(out, out2, STR_LENGTH_MAX);

    log("Login: ", login);
    log("Encrypt: ", out);
    log("Decrypt: ", out2);
    memset(out, 0, STR_LENGTH_MAX);
    memset(out2, 0, STR_LENGTH_MAX);
    aes_encrypt(password, out, STR_LENGTH_MAX);
    aes_decrypt(out, out2, STR_LENGTH_MAX);
    log("Password: ", password);
    log("Encrypt: ", out);
    log("Decrypt: ", out2);
	return 0;
}
