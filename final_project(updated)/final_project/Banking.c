#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// #include "OnlineBanking.h"

// defining the structure and properties
struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

// create a new account
void createAcc()
{
    struct user usr;
    FILE *fp;
    char filename[50];
    int opt, isUnique;

    // enter new account details
    system("cls");
    printf("Enter your account number:\t");
    scanf("%s", usr.ac);
    printf("Enter your phone number:\t");
    scanf("%s", usr.phone);
    printf("Enter your new password:\t");
    scanf("%s", usr.password);
    usr.balance = 0;

    // copies the value to the file name
    strcpy(filename, usr.phone);

    // creates the filename
    strcat(filename, ".txt");

    // checking if the file exists with the read mode
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        isUnique = 1;
    }
    else
    {
        isUnique = 0;
    }
    fclose(fp);

    if (isUnique)
    {
        fp = fopen(filename, "w");

        fprintf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%.2f", usr.ac, usr.phone, usr.password, usr.balance);

        if (fprintf != 0)
        {
            printf("\n\nAccount succesfully registered\n");
        }
        else
        {
            printf("\n\nSomething went wrong please try again\n");
        }

        fclose(fp);
    }
    else
    {
        printf("\n\nAccount allready exists\n");
    }
    printf("Press any key to continue...");
    getch();
}

// login to exisiting account
void loginAcc()
{
    struct user usr3, usr4;
    FILE *fp;
    char filename[50], filename1[50], phone[50], pword[50];
    int opt, choice;
    char cont = 'y';
    float amount;
    int options[6] = {0, 1, 2, 3, 4, 5};

    system("cls");
    printf("Phone number:\t");
    scanf("%s", phone);
    printf("Password:\t");
    scanf("%s", pword);

    // copies the value to the file name
    strcpy(filename, phone);

    // creates the filename
    strcat(filename, ".txt");

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Account number not registered\n\n");
    }
    else
    {
        fscanf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%f", &usr3.ac, &usr3.phone, &usr3.password, &usr3.balance);

        fclose(fp);
        if (!strcmp(pword, usr3.password))
        {
            // account options
            while (cont == 'y')
            {
                system("cls");
                printf("Press %d for balance inquiry\n", options[1]);
                printf("Press %d to deposit cash\n", options[2]);
                printf("Press %d to make a withdraw\n", options[3]);
                printf("Press %d to make an online transfer\n", options[4]);
                printf("Press %d to change the password\n", options[5]);
                printf("Press %d to quit\n\n", options[0]);
                printf("Your choice?\t");
                scanf("%d", &choice);
                system("cls");

                switch (choice)
                {
                // exit
                case 0:
                    cont = 'n';
                    break;

                // check balance
                case 1:
                    printf("Your current balance is $ %.2f\n", usr3.balance);
                    break;

                // deposit money
                case 2:
                    printf("Current amount: $%.2f\n\n", usr3.balance);
                    printf("Enter the amount to deposit:\t");
                    scanf("%f", &amount);
                    usr3.balance += amount;

                    fp = fopen(filename, "w");
                    fprintf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%.2f", usr3.ac, usr3.phone, usr3.password, usr3.balance);
                    if (fprintf != NULL)
                        printf("\nSuccesfully deposited.\n\n");
                    fclose(fp);
                    break;

                // withdraw
                case 3:
                    printf("\nAvailable amount: $%.2f\n\n", usr3.balance);
                    printf("\nEnter the amount to withdraw:\t");
                    scanf("%f", &amount);
                    usr3.balance -= amount;
                    fp = fopen(filename, "w");
                    fprintf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%.2f", usr3.ac, usr3.phone, usr3.password, usr3.balance);
                    if (fwrite != NULL)
                        printf("\nYou have succesfully withdrawn $%.2f\n\n", amount);
                    fclose(fp);
                    break;

                // transfer
                case 4:
                    printf("Available balance: $%.2f\n", usr3.balance);
                    printf("Please enter the phone number you would like to tranfer balance to:\t");
                    scanf("%s", phone);
                    printf("Please enter the amount you would like to tranfer:\t");
                    scanf("%f", &amount);

                    // copies the value to the file name
                    strcpy(filename1, phone);

                    // creates the filename
                    strcat(filename1, ".txt");

                    fp = fopen(filename1, "r");
                    if (fp == NULL)
                        printf("\nInvalid account number\n");
                    else
                    {
                        fscanf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%f", &usr4.ac, &usr4.phone, &usr4.password, &usr4.balance);
                        fclose(fp);
                        // check if there are sufficient funds to transfer
                        if (amount > usr3.balance)
                            printf("\nInsufficient funds\n\n");
                        else
                        {
                            // adding the amount to the receiver
                            fp = fopen(filename1, "w");
                            usr4.balance += amount;
                            fprintf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%.2f", usr4.ac, usr4.phone, usr4.password, usr4.balance);
                            fclose(fp);

                            // deducting the amount of the sender
                            fp = fopen(filename, "w");
                            usr3.balance -= amount;
                            fprintf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%.2f", usr3.ac, usr3.phone, usr3.password, usr3.balance);
                            fclose(fp);

                            if (fprintf != NULL)
                            {
                                printf("\nYou have succesfully transfered $%.2f to account number: %s\n\n", amount, phone);
                            }
                        }
                    }
                    break;

                // change password
                case 5:
                    printf("Please enter your new password:\t");
                    scanf("%s", pword);
                    fp = fopen(filename, "w");
                    strcpy(usr3.password, pword);
                    fprintf(fp, "Account number: %s Phone number: %s Password: %s Balance: $%.2f", usr3.ac, usr3.phone, usr3.password, usr3.balance);
                    if (fprintf != NULL)
                    {
                        printf("\nPassword succesfully changed\n\n");
                    }
                    fclose(fp);

                    break;

                default:
                    printf("\nInvalid option\n\n");
                    break;
                }

                // printf("\nDo you want to continue the transaction [y/n]?\t");
                // scanf("%s", &cont);
                printf("Press any key to continue...\n");
                getch();
            }
        }
        else
        {
            printf("Invalid password\n");
            printf("Press any key to continue...");
            getch();
        }
    }
}

int main()
{
    // instance of user and defining variables
    struct user usr;
    // FILE *fp;
    // char filename[50], phone[50], pword[50];
    int opt;
    char cont = 'y';
    int isRunning = 1;

    while (isRunning)
    {
        // Front page
        system("cls");
        printf("What would you like to do?\n\n");
        printf("1. Register an account\n");
        printf("2. Login to your account\n");
        printf("0. Exit\n\n");
        printf("Your choice:\t");
        scanf("%d", &opt);

        switch (opt)
        {

        // exit
        case 0:
            isRunning = 0;
            break;

        // create an account
        case 1:
            createAcc();
            break;

        // Login to account
        case 2:
            loginAcc();
            break;

        default:
            printf("Invalid option\n");
            break;
        }

        // printf("\nWould you like to register a new account/login to another account ? [y/n]?\t");
        // scanf("%s", &cont);
    }

    return 0;
}
