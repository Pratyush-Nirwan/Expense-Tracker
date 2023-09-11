#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int editBalance(char *username, float amount)
{
    struct Account
    {
        char name[50];
        char password[50];
        float balance;
    };
    struct Account read;
    

    FILE *acc = fopen("Database/accounts.txt", "r");
    if (acc == NULL)
    {
        printf("Error opening file0.\n");
        return 0;
    }

    FILE *temp = fopen("Database/temp.txt", "w");
    if (temp == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(acc);
        return 0;
    }
    while (fscanf(acc, "%s %s %f\n", read.name, read.password, &read.balance) != EOF)
    {
        if (strcmp(read.name, username) == 0)
        {
            // Update the balance for this account
            read.balance = amount;
        }

        fprintf(temp, "%s %s %.2f\n", read.name, read.password, read.balance);
    }

    fclose(temp);
    fclose(acc);

    FILE *src = fopen("Database/temp.txt", "r");
    if (acc == NULL)
    {
        perror("Could not open source file");
        return 0;
    }

    FILE *dst = fopen("Database/accounts.txt", "w");
    if (acc == NULL)
    {
        perror("Could not open source file");
        return 0;
    }

    char c;
    while ((c = fgetc(src)) != EOF)
    {
        fputc(c, dst);
    }

    fclose(acc);
    fclose(temp);
    return 1;
}