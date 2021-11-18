#include <stdio.h>
#include <stdlib.h>

          // function prototypes



void printMainMenu();

void printIntroMenu();

void start();

void login();

void createAccount();

void printIntroMenu();

 

// global variable (use this variable to store the user’s menu selection)

char menuInput;
int id, pass, id_edited = 0, pass_edited = 0;
float deposit_money = 20, withdraw_money = 2.5, balance = 0;

 

// the main function

int main()

{

          // TO WRITE A WELCOME MESSAGE HERE
    printf("Hi! Welcome to Mr. Zamar's ATM Machine!\n\n\n");
 

                    // call the function start
    start();   
    
        
    return 0;

}

 

void printIntroMenu()

{

          // WRITE CODE HERE
    do
    {
        printf("l  -> Login\n");
        printf("c  -> Create New Account\n");
        printf("q  -> Quit\n");
        fflush(stdin);
        scanf("%c", &menuInput);
        switch (menuInput)
        {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                exit(0);
                break;
            // default:
            //     printf("Wrong syntax\n");
        }
    }while (1);
}

 

void printMainMenu()

{

          // WRITE CODE HERE
    do
    {
        printf("d -> Deposit Money\n");
        printf("w -> Withdraw Money\n");
        printf("r -> Request Balance\n");
        fflush(stdin);
        scanf("%c", &menuInput);
        switch (menuInput)
        {
            case 'd':
                printf("Amount of deposit: $%.2f\n", deposit_money);
                break;
            case 'w':
                printf("Amount of withdrawal: $%.2f\n", withdraw_money);
                break;
            case 'r':
                balance = deposit_money - withdraw_money;
                printf("Your balance is $%.2f\n", balance);
                break;
            case 'q':
                printf("Thanks for stopping by!");
                exit(0);
                break;
        }
    }while (1);

}

 

void start()

{

          // EXPLANATION OF CODE THAT GOES HERE IS BELOW
    printf("        Please select an option from the menu below:\n\n\n");
    printIntroMenu();

}

 

void createAccount()

{

          // PHASE 2
    printf("Please enter your user id: ");
    scanf("%d", &id_edited);
    printf("Please enter your user password: ");
    scanf("%d", &pass_edited);
    printf("Thank You! Your account has been created!\n");
    start();

}

 

void login()

{

          // PHASE 2
    printf("Please enter your user id: ");
    scanf("%d", &id);
    printf("Please enter your user password: ");
    scanf("%d", &pass);
    if(id == id_edited && pass == pass_edited)   
    {
        printf("Access Granted!\n");
        printMainMenu();
    }    
    else
    {
         printf("******** LOGIN FAILED! ********\n");
         start();
    }
}

 
