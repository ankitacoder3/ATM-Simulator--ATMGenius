#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cserverfile.html"
void homepage(struct customer c)
{
    int ext = 1;
    char choice ='e',ans ='y';
    printf("CUSTMOER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("WELCOME TO THE BANK ATM SERVICE\n");
    printf("a) Check Balance\n");
    printf("b) Withdraw Cash\n");
    printf("c)Deposit cash\n");
    printf("d)quit\n");
	while(ans=='y')
	{
		printf("Enter your choice: ");
		fflush(stdin);
		scanf("%c",&choice);
		switch(choice)
		{
			case 'a':chk_bal(c);
			         break;
            case 'b':withdraw(c);
                     break;
            case 'c':deposit(c);
                     break;
            case 'd':quit();
                     ext = 0;
                     break;
            default:printf("Invalid Choice");
                     break;
        }
	printf("\nDo you want to enter another choice (y/n)");
    fflush(stdin);
    scanf("%c",ans);
	}	
    //return c.balance;
}
    
void chk_bal(struct customer c)
{
    printf("YOUR BALANCE IS: %lf\n",c.balance);
}


void withdraw(struct customer c)
{
    int w_cash;
    printf("ENTER THE AMOUNT TO WITHDRAW: ");
    scanf("%d",&w_cash);
    if (w_cash%100!=0)
    {

        printf("PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100 OR 200 OR 500");
		withdraw(c);

    }
    else if(c.balance<500 || w_cash>(c.balance-500)){
    

        printf("INSUFFICIENT BALANCE");

    }
    else
    {
       c.balance=c.balance-w_cash;
       printf("PLEASE COLLECT  CASH\n");
       printf("YOUR CURRENT BALANCE IS %lf",c.balance); 
    }
    //return c.balance;
       
}


void deposit(struct customer c)
{
    double d_cash;
    printf("ENTER THE AMOUNT TO DEPOSIT:\n");
    scanf(" %lf",&d_cash);
    c.balance=c.balance+d_cash;
    printf("YOUR BALANCE IS:%lf",c.balance);
    //return c.balance;
}


void quit()
{
    printf("THANK YOU FOR USING BANK ATM\n");
    return;
}