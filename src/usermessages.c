#include "usermessages.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>

static char user_login[STR_LENGTH_MAX];
static char user_password[STR_LENGTH_MAX];
static char user_encrypt_login[STR_LENGTH_MAX];
static char user_encrypt_password[STR_LENGTH_MAX];

int set_login(char* login)
{
    memset(user_login, 0, STR_LENGTH_MAX);
    if (strlen(login) <= STR_LENGTH_MAX)
    {
        strcpy(user_login, login);
        return 0;
    }
    else
    {
        print_messages[ER_LOGIN_MAX_LENGTH]();
        return -1;
    }
}

const char *get_login()
{
    return user_login;
}

int set_password(char* password)
{
    memset(user_password, 0, STR_LENGTH_MAX);
    if (strlen(password) <= STR_LENGTH_MAX)
    {
        strcpy(user_password, password);
        return 0;
    }
    else
    {
        print_messages[ER_PASSWORD_MAX_LENGTH]();
        return -1;
    }

}
const char *get_password()
{
    return user_password;
}

int set_encrypt_login(char* login)
{
    memset(user_encrypt_login, 0, STR_LENGTH_MAX);
    if (strlen(login) <= STR_LENGTH_MAX)
    {
        strcpy(user_encrypt_login, login);
        return 0;
    }
    else
    {
        print_messages[ER_LOGIN_MAX_LENGTH]();
        return -1;
    }
}

const char *get_encrypt_login()
{
    return user_encrypt_login;
}

int set_encrypt_password(char* password)
{
    memset(user_encrypt_password, 0, STR_LENGTH_MAX);
    if (strlen(password) <= STR_LENGTH_MAX)
    {
        strcpy(user_encrypt_password, password);
        return 0;
    }
    else
    {
        print_messages[ER_PASSWORD_MAX_LENGTH]();
        return -1;
    }

}
const char *get_encrypt_password()
{
    return user_encrypt_password;
}

void er_print_login_max()
{
    printf("Login length is too long, max length: %d\n\r", STR_LENGTH_MAX);
}


void er_print_password_max()
{
    printf("Password length is too long, max length: %d\n\r", STR_LENGTH_MAX);
}

void er_print_k_len()
{
    printf("Key length is incorrect\n\r");
}

void print_user_login()
{
    printf("User login: %s\n\r", user_login);
}

void print_user_password()
{
    printf("User password: %s\n\r", user_password);
}

void print_encrypt_login()
{
    int i = 0;
    printf("User encrypt login:\n\r");
    for (i = 0; i < STR_LENGTH_MAX; i++)
    {
        printf("%x", user_encrypt_login[i]);
    }
    printf("\n\r");
}

void print_encrypt_password()
{
    int i = 0;
    printf("User encrypt password:\n\r");
    for (i = 0; i < STR_LENGTH_MAX; i++)
    {
        printf("%x", user_encrypt_password[i]);
    }
    printf("\n\r");
}

void (*print_messages[])() =
{
        er_print_login_max,
        er_print_password_max,
        er_print_k_len,
        print_user_login,
        print_user_password,
        print_encrypt_login,
        print_encrypt_password
};
