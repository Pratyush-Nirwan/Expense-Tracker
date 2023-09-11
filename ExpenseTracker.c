#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// files that store diffrent parts of the code
#include "Functions/structures.c"
#include "Functions/login.c"
#include "Functions/reg.c"
#include "Functions/editBalance.c"
#include "Functions/readBalance.c"
#include "Functions/addExpense.c"
#include "Functions/showExpense.c"
#include "Functions/deleteAccount.c"

char loggedInAs[50]; // global varible that stores the current user after login

int main()
{
    printf("|-----------------------------------|\n");
    printf("|--------- EXPENSE TRACKER ---------|\n");
    printf("|-----------------------------------|\n");
    printf("Created by -\n -> Pratyush Nirwan A64\n\n");

    // get the user to register or login
    int loggedIn = 0;
    while (loggedIn == 0)
    {
        int choice;
        printf("\n");
        printf("1.Login\n2.Register\n3.Delete Account\n");
        printf("What do you want to do?: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            loggedIn = login();
        }
        else if (choice == 2)
        {
            reg();
        }
        else if (choice == 3){
            char username[50];
            printf("\n\tEnter the account you want to delete: ");
            scanf("%s",username);
            int success = deleteAccount(username);
            
            if(success == 1){
                printf("\nAccount deleted successfully!");
            }
        }
        else
        {
            printf("\nInvalid choice please try again.\n");
        }
    }
    printf("Logged in as - %s\n", loggedInAs);
    float balance = readBalance(loggedInAs);
    printf("Current Balance - Rs %.2f\n",balance);

    int using = 1;
    while (using == 1)
    {
        int choice;
        printf("\n1.Add income\n2.Add Expense\n3.Show Expense\n4.Show Balance\n5.Exit\n");
        printf("What do you want to do?: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            float amt, editedAmt;
            FILE *acc = fopen("Database/accounts.txt", "r");
            if (acc == NULL)
            {
                printf("Error opening file.\n");
            }
            struct Account read;
            while (fscanf(acc, "%s %s %f\n", read.name, read.password, &read.balance) != EOF)
            {
                if (strcmp(read.name, loggedInAs) == 0)
                {
                    editedAmt = read.balance;
                }
            }

            printf("\n\tAmount to add: ");
            scanf("%f", &amt);
            editedAmt = editedAmt + amt;
            int success = editBalance(loggedInAs, editedAmt);

            if (success == 1)
            {
                float balance = readBalance(loggedInAs);
                printf("\nIncome added successfully\nNew Balance - Rs %.2f\n\n", balance);
            }
        }
        else if (choice == 2)
        {
            int flag=0;
            while(flag==0){
                int cat;
                printf("\nCategories:\n1.Bills\n2.Food\n3.Entertainment\n4.Health\n5.Shopping\n6.Friends\n7.Transportation\n8.Exit\nSelect Category: ");
                scanf("%d",&cat);

                if(cat==1){
                int success = addExpense("Bills",loggedInAs);

                }else if(cat==2){
                    addExpense("Food",loggedInAs);
                }else if(cat==3){
                    addExpense("Entertainment",loggedInAs);
                }else if(cat==4){
                    addExpense("Health",loggedInAs);
                }else if(cat==5){
                    addExpense("Shopping",loggedInAs);
                }else if(cat==6){
                    addExpense("Friends",loggedInAs);
                }else if(cat==7){
                    addExpense("Transportation",loggedInAs);
                }else if(cat==8){
                    printf("\n");
                    break;
                }else{
                    printf("Invalid option!");
                }
            }
            

        }else if(choice==3){
            showExpense(loggedInAs);
        }else if(choice==4){
            float balance = readBalance(loggedInAs);
            printf("\nYour current balance is: Rs %.2f\n",balance);
        }else if(choice==5){
            using=0;
        }
        else
        {
            printf("Invalid choice please try again.");
        }
    }
}