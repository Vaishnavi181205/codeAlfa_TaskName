//TASK 4: High – Banking System (Mini Project)

/*Objective:
Build a simple Bank Account Management System in C.
Functions:

Deposit

Withdraw

Balance Enquiry

Exit
Use file handling to store customer data permanently.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayAllAccounts();

int main() {
    int choice;

    while (1) {
        printf("\n===== Bank Account Management System =====\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("\nExiting the program. Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

void createAccount() {
    FILE *fp;
    struct Account acc;
    fp = fopen("bank.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &acc.accNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("\nAccount created successfully!\n");
}

void depositMoney() {
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;
    long pos;

    fp = fopen("bank.dat", "rb+");
    if (!fp) {
        printf("\nNo account records found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;

            pos = -1L * sizeof(acc);
            fseek(fp, pos, SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);

            printf("\nAmount deposited successfully!\n");
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("\nAccount not found!\n");
}

void withdrawMoney() {
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;
    long pos;

    fp = fopen("bank.dat", "rb+");
    if (!fp) {
        printf("\nNo account records found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount > acc.balance) {
                printf("\nInsufficient balance!\n");
            } else {
                acc.balance -= amount;
                pos = -1L * sizeof(acc);
                fseek(fp, pos, SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("\nWithdrawal successful!\n");
            }
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("\nAccount not found!\n");
}

void checkBalance() {
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;

    fp = fopen("bank.dat", "rb");
    if (!fp) {
        printf("\nNo account records found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("\nAccount Number: %d\nName: %s\nCurrent Balance: %.2f\n", acc.accNo, acc.name, acc.balance);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("\nAccount not found!\n");
}

void displayAllAccounts() {
    FILE *fp;
    struct Account acc;

    fp = fopen("bank.dat", "rb");
    if (!fp) {
        printf("\nNo accounts available!\n");
        return;
    }

    printf("\n%-10s %-20s %-10s\n", "Acc No", "Name", "Balance");
    printf("-------------------------------------------\n");

    while (fread(&acc, sizeof(acc), 1, fp)) {
        printf("%-10d %-20s %-10.2f\n", acc.accNo, acc.name, acc.balance);
    }
    fclose(fp);
}




