#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "Source.h"

void NumberOnee();
void NumberTwo();

void HomeWork();


void main() {
    setlocale(LC_ALL, "Russian");

    //NumberOnee();
    //NumberTwo();

    HomeWork();
}

void NumberOnee()
{
    char name[50];
    char greeting[100];

    puts("Пожалуйста, введите ваше имя: ");

    scanf("%49s", name);

    for (int i = 0; name[i] != '\0'; i++) {
        name[i] = toupper(name[i]);
    }

    strcpy(greeting, "Привет, ");
    strcat(greeting, name);
    strcat(greeting, " ");

    int current_len = strlen(greeting);
    int target_len = 40;

    while (current_len < target_len) {
        if (current_len >= 99) break;

        strcat(greeting, "!");
        current_len++;
    }

    puts(greeting);
}

void NumberTwo() 
{
    char name[50];
    char modified[100];
    int len;

    printf("Пожалуйста, введите ваше имя: ");
    scanf("%49s", name);
    len = strlen(name);

    printf("\n--- Результаты модификации ---\n");

    if (len > 0) {
        strcpy(modified, name);
        modified[len] = name[len - 1];
        modified[len + 1] = '\0';
        printf("1) Удвоение последней буквы:     %s\n", modified);
    }

    strcpy(modified, name);
    if (len > 0) {
        modified[0] = tolower(modified[0]);
        for (int i = 1; i < len; i++) {
            modified[i] = toupper(modified[i]);
        }
    }
    printf("2) Первая строчная, остальные заглавные: %s\n", modified);

    strcpy(modified, name);
    if (len >= 2) {
        char temp = modified[0];
        modified[0] = modified[1];
        modified[1] = temp;
    }
    printf("3) Две первые буквы местами:     %s\n", modified);

    strcpy(modified, name);
    if (len > 0) {
        modified[len - 1] = '_';
        modified[len] = name[len - 1];
        modified[len + 1] = '\0';
    }
    printf("4) Подчеркивание перед последней: %s\n", modified);

    strcpy(modified, name);
    for (int i = 0; i < len / 2; i++) {
        char temp = modified[i];
        modified[i] = modified[len - 1 - i];
        modified[len - 1 - i] = temp;
    }
    printf("5) Имя наоборот:                 %s\n", modified);

    strcpy(modified, name);
    if (len >= 2) {
        for (int i = 1; i < len; i++) {
            modified[i] = modified[i + 1];
        }
    }
    printf("6) Исчезла вторая буква:         %s\n", modified);

    strcpy(modified, name);
    for (int i = 0; i < len; i++) {
        if (i < len / 2) {
            modified[i] = toupper(modified[i]);
        }
        else {
            modified[i] = tolower(modified[i]);
        }
    }
    printf("7) Половина заглавными:          %s\n", modified);

    strcpy(modified, name);
    if (len > 3) {
        modified[3] = '.';
        modified[4] = '.';
        modified[5] = '.';
        modified[6] = '\0';
    }
    else {
        strcat(modified, "...");
    }
    printf("8) Три точки после 3-х букв:     %s\n", modified);

    modified[0] = '\0';
    for (int i = 0; i < len; i++) {
        int cur_len = strlen(modified);
        modified[cur_len] = name[i];
        modified[cur_len + 1] = ' ';
        modified[cur_len + 2] = '\0';
    }
    printf("9) Пробел после каждой буквы:    %s\n", modified);

    strcpy(modified, name);
    for (int i = 0; i < len; i++) {
        if (modified[i] == 'a' || modified[i] == 'A') {
            modified[i] = '@';
        }
    }
    printf("10) Замена 'а' на '@':           %s\n", modified);

    strcpy(modified, name);
    if (len >= 2) {
        modified[len - 2] = '-';
    }
    printf("11) Предпоследняя буква - тире:  %s\n", modified);

    modified[0] = '\0';
    if (len > 0) {
        char first_upper = toupper(name[0]);
        modified[0] = first_upper;
        modified[1] = first_upper;
        modified[2] = first_upper;
        strcpy(&modified[3], &name[1]);
    }
    printf("12) Утроенная первая заглавная:  %s\n", modified);
}

void HomeWork() 
{
    char text[256];
    char* word;
    const char* delimiters = " ,.!?;:\n\t";

    printf("Введите строку текста: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Ошибка чтения строки.\n");
        return 1;
    }

    printf("\nСлова с удвоенными буквами:\n");

    word = strtok(text, delimiters);

    while (word != NULL) {
        int len = strlen(word);
        int found = 0;

        for (int i = 0; i < len - 1; i++) {
            if (word[i] == word[i + 1] && isalpha(word[i])) {
                if (!found) {
                    printf("- %s (буква: '%c')\n", word, word[i]);
                    found = 1;
                }
            }
        }

        word = strtok(NULL, delimiters);
    }
}