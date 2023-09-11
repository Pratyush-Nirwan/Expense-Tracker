#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int addExpense(char *category, char *username)
{
    char path[50] = "Database/Categories/";
    char extension[] = ".txt";
    strcat(path, category);
    strcat(path, extension);
    float amount;
    char note[200];
    printf("\n\tEnter Amount: ");
    float balance = readBalance(username);
    scanf("%f", &amount);
    printf("\tAdd note(no spaces): ");
    scanf("%s", note);
    FILE *cat = fopen(path, "a");
    if (cat == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    fprintf(cat, "%s %s %.2f\n", username, note, amount);
    fclose(cat);

    float newBal = balance - amount;
    int success = editBalance(username, newBal);
    if (success == 1)
    {
        float balance = readBalance(username);
        printf("\n\nExpense added successfully\nNew Balance - Rs %.2f\n\n", balance);
    }
}