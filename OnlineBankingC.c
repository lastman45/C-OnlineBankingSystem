#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    char name[50];
    char password[50];
    char email[20];
    int phone_number;
    float balance;
}; // Define the user structure

void display_menu()
{
    printf("\n1. Deposit Funds\n");
    printf("2. Withdraw Funds\n");
    printf("3. Transfer Funds\n");
    printf("4. Change Password\n");
    printf("5. Check Balance\n");
    printf("6. Logout\n");
}

int main()
{
    struct user current_user; // File pointer for the current user
    int choice;

    printf("WELCOME TO ONLINE BANKING SYSTEMS\n");
    printf("\nHello, How can I assist you today?\n");
    printf("\n1. Create Account\n");
    printf("2. Login to an Account\n");

    printf("\nPlease enter your choice:\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("CREATING A NEW ACCOUNT!!!\n");
        printf("\nEnter your name: \n");
        scanf("%s", current_user.name);
        printf("\nEnter your New password: \n");
        scanf("%s", current_user.password);
        printf("\nConfirm your New password: \n");
        scanf("%s", current_user.password); // This should ideally check for confirmation
        printf("\nEnter your Email Address: \n");
        scanf("%s", current_user.email);
        printf("\nEnter your phone number: \n");
        scanf("%d", &current_user.phone_number);
        current_user.balance = 0.0; // Initialize balance to zeros
        printf("\nACCOUNT CREATED SUCCESSFULLY!!\n");
        printf("ACCOUNT BALANCE = 0.0:\n");
    }
    else if (choice == 2)
    {
        system("cls");
        char password[50];
        printf("Enter your name to login: \n");
        scanf("%s", current_user.name);
        printf("\nEnter your password to login: \n");
        scanf("%s", password);
        strcpy(current_user.password, password); // Simulating login
        int logged_in = 1;
        while (logged_in)
        {
            display_menu();
            printf("\nPlease enter your choice:\n");
            int action;
            scanf("%d", &action);

            switch (action)
            {
            case 1:
            {
                float deposit_amount;
                printf("\nEnter amount to deposit: \n");
                scanf("%f", &deposit_amount);
                current_user.balance += deposit_amount;
                printf("\nSuccessfully deposited %.2f. New balance: %.2f\n", deposit_amount, current_user.balance);
            }
            break;
            case 2:
            {
                float withdraw_amount;
                printf("\nEnter amount to withdraw: \n");
                scanf("%f", &withdraw_amount);
                if (withdraw_amount > current_user.balance)
                {
                    printf("\nInsufficient balance!\n");
                }
                else
                {
                    current_user.balance -= withdraw_amount;
                    printf("\nSuccessfully withdrew %.2f. New balance: %.2f\n", withdraw_amount, current_user.balance);
                }
            }
            break;
            case 3:
            {
                float transfer_amount;
                char recipient[50];
                printf("\nEnter recipient's name: \n");
                scanf("%s", recipient);
                printf("\nEnter amount to transfer: \n");
                scanf("%f", &transfer_amount);
                if (transfer_amount > current_user.balance)
                {
                    printf("\nInsufficient balance!\n");
                }
                else
                {
                    current_user.balance -= transfer_amount;
                    printf("\nSuccessfully transferred %.2f to %s. New balance: %.2f\n", transfer_amount, recipient, current_user.balance);
                }
            }
            break;
            case 4:
            {
                char new_password[50];
                printf("\nEnter new password: \n");
                scanf("%s", new_password);
                strcpy(current_user.password, new_password);
                printf("\nPassword changed successfully!\n");
            }
            break;
            case 5:
                printf("\nYour current balance is: %.2f\n", current_user.balance);
                break;
            case 6:
                logged_in = 0;
                printf("\nYou have logged out successfully.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }
    else
    {
        printf("\nInvalid choice. Please restart the program.\n");
    }
    return 0;
}
