#ifndef USERMESSAGES_H
#define USERMESSAGES_H

#define STR_LENGTH_MAX 96

int set_login(char* login);
const char* get_login();

int set_password(char* password);
const char* get_password();

int set_encrypt_login(char* login);
const char* get_encrypt_login();

int set_encrypt_password(char* password);
const char* get_encrypt_password();

typedef enum enum_print_messages
{
    ER_LOGIN_MAX_LENGTH,
    ER_PASSWORD_MAX_LENGTH,
    ER_KEY_LENGTH,
    USER_LOGIN,
    USER_PASSWORD,
    ENCRYPT_LOGIN,
    ENCRYPT_PASSWORD
}enum_print_messages;

extern void (*print_messages[])();

#endif //USERMESSAGES_H
