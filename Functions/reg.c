#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void reg()
{
    struct Account inp;
    struct Account read;
    char password[50];
    char repassword[50];
    int foundUser = false;
    printf("\n\tEnter your name: ");
    scanf("%s", inp.name);

    FILE *acc;
    acc = fopen("Database/accounts.txt", "r");
    if (acc == NULL)
    {
        printf("error opening file!");
        exit(1);
    }

    while (fscanf(acc, "%s %s %f\n", read.name, read.password, &read.balance) != EOF)
    {
        if (strcmp(read.name, inp.name) == 0)
        {
            printf("\n\nThe username already exists!");
            foundUser = true;
            break;
        }
    }
    fclose(acc);
    if (!foundUser)
    {
        FILE *acc;
        acc = fopen("Database/accounts.txt", "a");
        if (acc == NULL)
        {
            printf("Error to open the file");
            exit(1);
        }
        printf("\tEnter starting balance in account: ");
        scanf("%f", &inp.balance);
        printf("\tEnter your password: ");
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

        printf("\n\tPlease re-enter your password: ");
        p = 0;
        do
        {
            repassword[p] = getch();
            if (repassword[p] != '\r')
            {
                printf("*");
            }
            p++;
        } while (repassword[p - 1] != '\r');
        repassword[p - 1] = '\0';
        if (strcmp(password, repassword) == 0)
        {
            strcpy(inp.password, password);
            fprintf(acc, "%s %s %.2f\n", inp.name, inp.password, inp.balance);
            printf("\n\nAccount created successfully please login.");
        }
        else
        {
            printf("\n\nBoth passwords should match!");
        }
        fclose(acc);
    }
}
