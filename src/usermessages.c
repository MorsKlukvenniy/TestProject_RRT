#include "usermessages.h"
#include <string.h>
#include <stdint.h>

static char user_login[STR_LENGTH_MAX];
static char user_password[STR_LENGTH_MAX];

void set_login(char* login)
{
    memset(user_login, 0, STR_LENGTH_MAX);
    if (strlen(login) <= STR_LENGTH_MAX)
    {
        strcpy(user_login, login);
    }
}

void get_login(char* login)
{
    strcpy(login, user_login);
}

void set_password(char* password)
{
    memset(user_password, 0, STR_LENGTH_MAX);
    if (strlen(password) <= STR_LENGTH_MAX)
    {
        strcpy(user_password, password);
    }

}
void get_password(char* password)
{
    strcpy(password, user_password);
}
