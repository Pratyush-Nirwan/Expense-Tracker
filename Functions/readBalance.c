#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

float readBalance(char *username)
{
    struct Account
    {
        char name[50];
        char password[50];
        float balance;
    }read;
    int balance;
    FILE *acc = fopen("Database/accounts.txt", "r");
    if (acc == NULL)
    {
        printf("Error opening file.\n");
    }
    while (fscanf(acc, "%s %s %f\n", read.name, read.password, &read.balance) != EOF)
    {
        if (strcmp(read.name, username) == 0)
        {
            return read.balance;
        }
    }
    fclose(acc);
}
