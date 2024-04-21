#include "cryption.h"
#include "usermessages.h"
#include <stdio.h>

char login[STR_LENGTH_MAX];
char password[STR_LENGTH_MAX];
int key_len = 0;

int main ()
{
    memset(login, 0, STR_LENGTH_MAX);
    memset(password, 0, STR_LENGTH_MAX);
    //!Ввод логина
    printf("Enter user login:\n\r");
    scanf("%s", login);
    while (set_login(login)) {scanf("%s", login);}
    //!Ввод пароля
    printf("Enter user password:\n\r");
    scanf("%s", password);
    while (set_password(password)) {scanf("%s", password);}
    //!Ввод длины ключе AES
    printf("Enter AES key length:\n\r 0 - 128\n\r 1 - 192\n\r 2 - 256\n\r");
    scanf("%d", &key_len);
    while (key_len < KEY_128 || key_len > KEY_256)
    {
        print_messages[ER_KEY_LENGTH]();
        scanf("%d", &key_len);
    }
    //!Инициализация библиотеки шифрование
    aes_init(key_len);
    //!Печать введённых данных
    print_messages[USER_LOGIN]();
    print_messages[USER_PASSWORD]();

    //!Шифруем логин
    memset(login, 0, STR_LENGTH_MAX);
    aes_encrypt(get_login(), login, STR_LENGTH_MAX);
    set_encrypt_login(login);
    print_messages[ENCRYPT_LOGIN]();
    //!Дешефруем логин
    memset(login, 0, STR_LENGTH_MAX);
    aes_decrypt(get_encrypt_login(), login, STR_LENGTH_MAX);

    //!Шифруем пароль
    memset(password, 0, STR_LENGTH_MAX);
    aes_encrypt(get_password(), password, STR_LENGTH_MAX);
    set_encrypt_password(password);
    print_messages[ENCRYPT_PASSWORD]();
    //!Дешифруем пароль
    memset(password, 0, STR_LENGTH_MAX);
    aes_decrypt(get_encrypt_password(), password, STR_LENGTH_MAX);

    //!Печатаем результаты
    printf("Decrypt login: %s\n\rDecrypt password: %s\n\r", login, password);
	return 0;
}
