#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int login()
{
    extern char loggedInAs[50];
    FILE *acc;
    acc = fopen("Database/accounts.txt", "r+");
    if (acc == NULL)
    {
        printf("No Account found! please register first!");
        exit(1);
    }
    struct Account read;
    bool found = false;
    char name[50], password[50];

    printf("\n\tEnter your name: ");
    scanf("%s", name);
    printf("\tEnter the password: ");
    int p = 0;
    do
    {
        password[p] = getch();
        if (password[p] != '\r')
        {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');
    password[p - 1] = '\0';

    while (fscanf(acc, "%s %s %f\n", read.name, read.password, &read.balance) != EOF)
    {
        if (strcmp(read.name, name) == 0 && strcmp(read.password, password) == 0)
        {
            printf("\n\nSign in success\n");
            found = true;
            strcpy(loggedInAs, name);
            return 1;
        }
        else if (strcmp(read.name, name) == 0)
        {
            printf("\n\nWrong Password\n");
            return 0;
        }
    }

    fclose(acc);
    if (found == false)
    {
        printf("Y\n\nou haven't created an account yet!\n");
        return 0;
    }
}
