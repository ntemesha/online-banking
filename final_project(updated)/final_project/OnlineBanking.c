#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "OnlineBanking.h"

// defining the structure and properties
struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main()
{
    // instance of user and defining variables
    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    int opt, choice;
    char cont = 'y';
    float amount;

    while (cont == 'y')
    {
        // Front page
        printf("\nWhat would you like to do?");
        printf("\n\n1. Regester an account");
        printf("\n2. Login to your account");
        printf("\n\nYour choice:\t");
        scanf("%d", &opt);
        // create an account
        if (opt == 1)
        {
            createAcc();
        }
        // Login to account
        if (opt == 2)
        {
            loginAcc();
        }
        printf("\nWould you like to register a new account/login to another account ? [y/n]?\t");
        scanf("%s", &cont);
    }

    return 0;
}
