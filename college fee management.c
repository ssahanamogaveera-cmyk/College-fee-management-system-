#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    char username[30], password[30];
    char studentName[50];

    int i, rollNo, choice, ch;
    int attempts = 0;
    int login = 0;
    int loginSuccess = 0;

    float tuitionFee, examFee, libraryFee;
    float totalFee, paidAmount = 0;
    float payment, balance;

    /* WELCOME PAGE */
    printf("\n====================================\n");
    printf("       WELCOME TO OUR COLLEGE\n");
    printf("   STUDENT FEE MANAGEMENT SYSTEM\n");
    printf("====================================\n");

    /* LOGIN PAGE */
    printf("\n====================================\n");
    printf("              LOGIN PAGE\n");
    printf("====================================\n");

    printf("Enter Username: ");
    scanf("%29s", username);

    while (attempts < 3)
    {
        printf("Enter Password: ");
        i = 0;

        while (1)
        {
            ch = getch();

            if (ch == '\r' || ch == '\n')
            {
                break;
            }
            else if (ch == '\b')
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (ch >= 32 && ch <= 126 && i < 29)
            {
                password[i++] = (char)ch;
                printf("*");
            }
        }

        password[i] = '\0';
        printf("\n");

        if (strcmp(username, "admin") == 0 &&
            strcmp(password, "1234") == 0)
        {
            login = 1;
            loginSuccess = 1;

            printf("\nLogin Successful!\n");
            printf("Welcome to Student Fee Management System.\n");

            break;
        }
        else
        {
            attempts++;

            printf("Invalid Username or Password!\n");

            if (attempts < 3)
            {
                printf("Attempts remaining: %d\n",
                       3 - attempts);
            }
        }
    }

    if (loginSuccess == 0)
    {
        printf("\nMaximum login attempts exceeded!\n");
        printf("Login Failed. Exiting System.\n");
        return 0;
    }

    /* STUDENT DETAILS */
    printf("\n====================================\n");
    printf("       ENTER STUDENT DETAILS\n");
    printf("====================================\n");

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", studentName);

    printf("Enter Roll Number: ");
    if (scanf("%d", &rollNo) != 1)
    {
        printf("Invalid roll number!\n");
        return 0;
    }

    printf("Enter Tuition Fee: Rs. ");
    if (scanf("%f", &tuitionFee) != 1)
    {
        printf("Invalid fee amount!\n");
        return 0;
    }

    printf("Enter Examination Fee: Rs. ");
    if (scanf("%f", &examFee) != 1)
    {
        printf("Invalid fee amount!\n");
        return 0;
    }

    printf("Enter Library Fee: Rs. ");
    if (scanf("%f", &libraryFee) != 1)
    {
        printf("Invalid fee amount!\n");
        return 0;
    }

    if (tuitionFee < 0 || examFee < 0 ||
        libraryFee < 0)
    {
        printf("Fees cannot be negative!\n");
        return 0;
    }

    totalFee = tuitionFee + examFee + libraryFee;

    /* FEE MANAGEMENT MENU */
    do
    {
        printf("\n====================================\n");
        printf("        FEE MANAGEMENT MENU\n");
        printf("====================================\n");
        printf("1. Display Student Details\n");
        printf("2. Display Total Fee\n");
        printf("3. Pay College Fee\n");
        printf("4. Display Fee Receipt\n");
        printf("5. Logout\n");
        printf("====================================\n");

        printf("Enter your option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return 0;
        }

        switch (choice)
        {
            case 1:
                printf("\n------ STUDENT DETAILS ------\n");
                printf("Student Name: %s\n", studentName);
                printf("Roll Number : %d\n", rollNo);
                break;

            case 2:
                printf("\n------ TOTAL COLLEGE FEE ------\n");
                printf("Tuition Fee     : Rs. %.2f\n",
                       tuitionFee);
                printf("Examination Fee : Rs. %.2f\n",
                       examFee);
                printf("Library Fee     : Rs. %.2f\n",
                       libraryFee);
                printf("Total Fee       : Rs. %.2f\n",
                       totalFee);
                break;

            case 3:
                balance = totalFee - paidAmount;

                printf("\n------ COLLEGE FEE PAYMENT ------\n");
                printf("Total Fee       : Rs. %.2f\n",
                       totalFee);
                printf("Previously Paid : Rs. %.2f\n",
                       paidAmount);
                printf("Balance Due     : Rs. %.2f\n",
                       balance);

                if (balance <= 0.001)
                {
                    printf("All fees have been paid!\n");
                }
                else
                {
                    printf("Enter payment amount: Rs. ");

                    if (scanf("%f", &payment) != 1)
                    {
                        printf("Invalid payment input!\n");
                        return 0;
                    }

                    if (payment <= 0 || payment > balance)
                    {
                        printf("Invalid payment amount!\n");
                    }
                    else
                    {
                        paidAmount += payment;

                        printf("Payment successful!\n");
                        printf("Total Paid: Rs. %.2f\n",
                               paidAmount);
                        printf("Remaining Balance: Rs. %.2f\n",
                               totalFee - paidAmount);
                    }
                }
                break;

            case 4:
                balance = totalFee - paidAmount;

                printf("\n========== FEE RECEIPT ==========\n");
                printf("Student Name : %s\n", studentName);
                printf("Roll Number  : %d\n", rollNo);
                printf("Tuition Fee  : Rs. %.2f\n", tuitionFee);
                printf("Exam Fee     : Rs. %.2f\n", examFee);
                printf("Library Fee  : Rs. %.2f\n", libraryFee);
                printf("Total Fee    : Rs. %.2f\n", totalFee);
                printf("Amount Paid  : Rs. %.2f\n", paidAmount);
                printf("Balance Due  : Rs. %.2f\n", balance);

                if (balance <= 0.001)
                {
                    printf("Status       : FULLY PAID\n");
                }
                else
                {
                    printf("Status       : PAYMENT PENDING\n");
                }

                printf("=================================\n");
                break;

            case 5:
                login = 0;

                printf("\n====================================\n");
                printf("              LOGOUT PAGE\n");
                printf("====================================\n");
                printf("You have logged out successfully!\n");
                printf("====================================\n");
                break;

            default:
                printf("\nInvalid option! Please choose 1 to 5.\n");
        }

    } while (choice != 5 && login == 1);

    return 0;
}
