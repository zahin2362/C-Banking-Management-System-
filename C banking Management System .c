#include <stdio.h>
#include <string.h>

struct Bank {
    int accNo;
    char name[50];
    char password[20];
    char nominee[50];
    float balance;
    float loan;
};

int main() {
    struct Bank acc[5];
    int choice, i, total = 0;
    int from, to;
    float amount;

    while (1) {
        printf("\n--- Banking Management System ---\n");
        printf("1. Create Account\n");
        printf("2. Balance Check\n");
        printf("3. Withdraw Money\n");
        printf("4. Money Transfer\n");
        printf("5. Loan System\n");
        printf("6. Add Nominee\n");
        printf("7. Mobile Money Transfer\n");
        printf("8. RTGS\n");
        printf("9. Pay Bills\n");
        printf("0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            break;

        switch (choice) {

        case 1:
            printf("Enter Account Number: ");
            scanf("%d", &acc[total].accNo);
            printf("Enter Name: ");
            scanf(" %[^\n]", acc[total].name);
            printf("Set Password: ");
            scanf("%s", acc[total].password);
            acc[total].balance = 0;
            acc[total].loan = 0;
            total++;
            printf("Account Created Successfully\n");
            break;

        case 2:
            printf("Enter Account Index: ");
            scanf("%d", &i);
            printf("Balance: %.2f\n", acc[i].balance);
            break;

        case 3:
            printf("Enter Account Index: ");
            scanf("%d", &i);
            printf("Enter Amount: ");
            scanf("%f", &amount);
            if (acc[i].balance >= amount) {
                acc[i].balance -= amount;
                printf("Withdraw Successful\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;

        case 4:
            printf("From Account Index: ");
            scanf("%d", &from);
            printf("To Account Index: ");
            scanf("%d", &to);
            printf("Enter Amount: ");
            scanf("%f", &amount);

            if (acc[from].balance >= amount) {
                acc[from].balance -= amount;
                acc[to].balance += amount;
                printf("Transfer Successful\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;

        case 5:
            printf("Enter Account Index: ");
            scanf("%d", &i);
            printf("Enter Loan Amount: ");
            scanf("%f", &amount);
            acc[i].loan += amount;
            acc[i].balance += amount;
            printf("Loan Approved\n");
            break;

        case 6:
            printf("Enter Account Index: ");
            scanf("%d", &i);
            printf("Enter Nominee Name: ");
            scanf(" %[^\n]", acc[i].nominee);
            printf("Nominee Added\n");
            break;

        case 7:
            printf("Enter Account Index: ");
            scanf("%d", &i);
            printf("Enter Amount: ");
            scanf("%f", &amount);
            if (acc[i].balance >= amount) {
                acc[i].balance -= amount;
                printf("Mobile Transfer Successful\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;

        case 8:
            printf("Enter Account Index: ");
            scanf("%d", &i);
            printf("Enter RTGS Amount: ");
            scanf("%f", &amount);
            if (acc[i].balance >= amount) {
                acc[i].balance -= amount;
                printf("RTGS Successful\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;

        case 9:
            printf("Enter Account Index: ");
            scanf("%d", &i);
            printf("Enter Bill Amount: ");
            scanf("%f", &amount);
            if (acc[i].balance >= amount) {
                acc[i].balance -= amount;
                printf("Bill Paid Successfully\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
