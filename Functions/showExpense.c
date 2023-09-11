#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void showExpense(char *username)
{
    char name[50];
    char note[200];
    float amount;
    float total =0;
    printf("\nBILLS\n");
    printf("*****************************************\n");
    FILE *catFile = fopen("Database/Categories/Bills.txt","r");
    while (fscanf(catFile, "%s %s %f\n", name, note, &amount) != EOF)
    {
        if (strcmp(name, username) == 0)
        {
            printf("%-12s\t\t\t%8.2f\n",note,amount);
            total = total+amount;
        }
    }
    printf("\nTotal - Rs %.2f\n",total);
    fclose(catFile);
    total = 0;

    printf("\nFOOD\n");
    printf("*****************************************\n");
    catFile = fopen("Database/Categories/Food.txt","r");
    while (fscanf(catFile, "%s %s %f\n", name, note, &amount) != EOF)
    {
        if (strcmp(name, username) == 0)
        {
            printf("%-12s\t\t\t%8.2f\n",note,amount);
            total = total+amount;
        }
    }
    printf("\nTotal - Rs %.2f\n",total);
    fclose(catFile);
    total = 0;

    printf("\nENTERTAINMENT\n");
    printf("*****************************************\n");
    catFile = fopen("Database/Categories/Entertainment.txt","r");
    while (fscanf(catFile, "%s %s %f\n", name, note, &amount) != EOF)
    {
        if (strcmp(name, username) == 0)
        {
            printf("%-12s\t\t\t%8.2f\n",note,amount);
            total = total+amount;
        }
    }
    printf("\nTotal - Rs %.2f\n",total);
    fclose(catFile);
    total = 0;

    printf("\nHEALTH\n");
    printf("*****************************************\n");
    catFile = fopen("Database/Categories/Health.txt","r");
    while (fscanf(catFile, "%s %s %f\n", name, note, &amount) != EOF)
    {
        if (strcmp(name, username) == 0)
        {
            printf("%-12s\t\t\t%8.2f\n",note,amount);
            total = total+amount;
        }
    }
    printf("\nTotal - Rs %.2f\n",total);
    fclose(catFile);
    total = 0;


    printf("\nSHOPPING\n");
    printf("*****************************************\n");
    catFile = fopen("Database/Categories/Shopping.txt","r");
    while (fscanf(catFile, "%s %s %f\n", name, note, &amount) != EOF)
    {
        if (strcmp(name, username) == 0)
        {
            printf("%-12s\t\t\t%8.2f\n",note,amount);
            total = total+amount;
        }
    }
    printf("\nTotal - Rs %.2f\n",total);
    fclose(catFile);
    total = 0;


    printf("\nFRIENDS\n");
    printf("*****************************************\n");
    catFile = fopen("Database/Categories/Friends.txt","r");
    while (fscanf(catFile, "%s %s %f\n", name, note, &amount) != EOF)
    {
        if (strcmp(name, username) == 0)
        {
            printf("%-12s\t\t\t%8.2f\n",note,amount);
            total = total+amount;
        }
    }
    printf("\nTotal - Rs %.2f\n",total);
    fclose(catFile);
    total = 0;


    printf("\nTRANSPORTATION\n");
    printf("*****************************************\n");
    catFile = fopen("Database/Categories/Transportation.txt","r");
    while (fscanf(catFile, "%s %s %f\n", name, note, &amount) != EOF)
    {
        if (strcmp(name, username) == 0)
        {
            printf("%-12s\t\t\t%8.2f\n",note,amount);
            total = total+amount;
        }
    }
    printf("\nTotal - Rs %.2f\n",total);
    fclose(catFile);
    total = 0;

}