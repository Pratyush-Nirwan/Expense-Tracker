#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int deleteAccount(char *username)
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
        printf("Error opening file.\n");
        return 0;
    }

    FILE *temp = fopen("Database/temp.txt", "w");
    if (acc == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }
    int found = false;
    while (fscanf(acc, "%s %s %f\n", read.name, read.password, &read.balance) != EOF)
    {
        if (strcmp(read.name, username) != 0)
        {
            fprintf(temp, "%s %s %.2f\n", read.name, read.password, read.balance);
        }
        else
        {
            found = true;
        }
    }
    fclose(temp);
    fclose(acc);

    if (found)
    {
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
    else
    {
        printf("\n\nAccount not found!");
    }
}