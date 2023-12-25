#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
struct denominations
{
   int type;
   int numberoftype;

};

void homepage(char *user)
{
    int ext = 1;
    char choice ='e',ans ='y';
    printf("CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("WELCOME TO THE BANK ATM SERVICE\n");
    printf("a) Check Balance\n");
    printf("b) Withdraw Cash\n");
    printf("c)Deposit cash\n");
    printf("d)Change password\n");
    printf("e)quit\n");
	while(ans=='y')
	{
		printf("Enter your choice: ");
		fflush(stdin);
		scanf("%c",&choice);
		switch(choice)
		{
			case 'a':chk_bal(user);
			         break;
            case 'b':withdraw(user);
                     break;
            case 'c':deposit(user);
                     break;
            case 'd':change_passw(user);
                     break;
            case 'e':quit();
                     break;
            default:printf("Invalid Choice");
                     break;
        }
	printf("\nDo you want to enter another choice (y/n)");
    fflush(stdin);
    scanf("%c",&ans);
	}	
}

void chk_bal(char *user)
{
    FILE *fl;
	fl= fopen("data.csv","r");
    long double balance;
    struct details det;
    char a[100];
    char *p;
    int len=0;
    fgets(a,100,fl);
    while(fgets(a,100,fl))
    {
        p=strtok(a,",");
        p=strtok(NULL,",");
        if(strcmp(p,user)==0)
        {
            p=strtok(NULL,",");
            p=strtok(NULL,",");
            balance=strtold(p,&p);
            printf("Your balance is %Lf",balance);
        }
    }
    fclose(fl);
}
void withdraw(char *user)
{
    int w_cash;
    printf("ENTER THE AMOUNT TO WITHDRAW: ");
    scanf("%d",&w_cash);

    long double currentbal;
    
    FILE *fl;
	fl= fopen("data.csv","r");

    struct details det[20];
    char a[100];
    char *p;
    int len=0;
    fgets(a,100,fl);
    while(fgets(a,100,fl))
    {
        p=strtok(a,",");
        strcpy(det[len].name,p);
        p=strtok(NULL,",");
        strcpy(det[len].usern,p);
        p=strtok(NULL,",");
        strcpy(det[len].email,p);
        p=strtok(NULL,",");
        det[len].bal=strtold(p,&p);
        p=strtok(NULL,",");
        det[len].phoneno=atol(p);
        p=strtok(NULL,",");
        det[len].acc_no=atoi(p);
        p=strtok(NULL,",");
        det[len].age=atoi(p);
        p=strtok(NULL,",");
        det[len].PIN=atoi(p);
        len++;
    }
    fclose(fl);
    for(int i=0;i<len;i++)
    {
        if(strcmp(det[i].usern,user)==0)
        {
            currentbal=det[i].bal;
        }
    }
    if (w_cash%100!=0)
    {

        printf("PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100 OR 200 OR 500\n");
		withdraw(user);

    }
    else if(currentbal<500 || w_cash>(currentbal-500)){
    

        printf("INSUFFICIENT BALANCE\n");

    }
    else
    {
        int flag=denominations(w_cash);
        if (flag ==1)
        {
            fl= fopen("data.csv","w");
            for(int i=0;i<len;i++)
            {
                if(strcmp(det[i].usern,user)==0)
                {
                    currentbal=det[i].bal;
                    currentbal=currentbal-w_cash;
                    printf("PLEASE COLLECT YOUR CASH.\n");
                    printf("Your current balance is %Lf",currentbal);
                    det[i].bal=currentbal;

                }
                fprintf(fl,"\n%s,%s,%s,%Lf,%ld,%d,%d,%d",det[i].name,det[i].usern,det[i].email,det[i].bal,det[i].phoneno,det[i].acc_no,det[i].age,det[i].PIN);
            }
            fclose(fl);
        }
        else
        {
            printf("At present amount mentioned is unavailable in the atm\n");
        }
    }
       
}

void deposit(char *user)
{
    long double currentbal;
    long double d_cash;
    printf("ENTER THE AMOUNT TO DEPOSIT:\n");
    scanf(" %Lf",&d_cash);

    FILE *fl;
	fl= fopen("data.csv","r");

    struct details det[20];
    char a[100];
    char *p;
    int len=0;
    fgets(a,100,fl);
    while(fgets(a,100,fl))
    {
        p=strtok(a,",");
        strcpy(det[len].name,p);
        p=strtok(NULL,",");
        strcpy(det[len].usern,p);
        p=strtok(NULL,",");
        strcpy(det[len].email,p);
        p=strtok(NULL,",");
        det[len].bal=strtold(p,&p);
        p=strtok(NULL,",");
        det[len].phoneno=atol(p);
        p=strtok(NULL,",");
        det[len].acc_no=atoi(p);
        p=strtok(NULL,",");
        det[len].age=atoi(p);
        p=strtok(NULL,",");
        det[len].PIN=atoi(p);
        len++;
    }
    fclose(fl);
    fl= fopen("data.csv","w");
    for(int i=0;i<len;i++)
    {
        if(strcmp(det[i].usern,user)==0)
        {
            currentbal=det[i].bal;
            currentbal=currentbal+d_cash;
            printf("Your current balance is %Lf",currentbal);
            det[i].bal=currentbal;

        }
        fprintf(fl,"\n%s,%s,%s,%Lf,%ld,%d,%d,%d",det[i].name,det[i].usern,det[i].email,det[i].bal,det[i].phoneno,det[i].acc_no,det[i].age,det[i].PIN);
    }
    fclose(fl);

}

void change_passw(char *user)
{
    int opin;
    int npin;
    printf("ENTER THE NEW PIN:\n");
    scanf("%d",&npin);

    FILE *fl;
	fl= fopen("data.csv","r");

    struct details det[20];
    char a[100];
    char *p;
    int len=0;
    fgets(a,100,fl);
    while(fgets(a,100,fl))
    {
        p=strtok(a,",");
        strcpy(det[len].name,p);
        p=strtok(NULL,",");
        strcpy(det[len].usern,p);
        p=strtok(NULL,",");
        strcpy(det[len].email,p);
        p=strtok(NULL,",");
        det[len].bal=strtold(p,&p);
        p=strtok(NULL,",");
        det[len].phoneno=atol(p);
        p=strtok(NULL,",");
        det[len].acc_no=atoi(p);
        p=strtok(NULL,",");
        det[len].age=atoi(p);
        p=strtok(NULL,",");
        det[len].PIN=atoi(p);
        len++;
    }
    fclose(fl);
    fl= fopen("data.csv","w");
    for(int i=0;i<len;i++)
    {
        if(strcmp(det[i].usern,user)==0)
        {
            opin=det[i].PIN;
            det[i].PIN=npin;
            printf("YOUR NEW PIN HAS BEEN SUCCESFULLY UPDATED.\n");

        }
        fprintf(fl,"\n%s,%s,%s,%Lf,%ld,%d,%d,%d",det[i].name,det[i].usern,det[i].email,det[i].bal,det[i].phoneno,det[i].acc_no,det[i].age,det[i].PIN);
    }
    fclose(fl);
    
}

void quit()
{
    printf("THANK YOU FOR USING BANK ATM\n");
    exit(0);
    return;
}

int denominations(int n)
{
    FILE *fl;
	fl= fopen("denominations.txt","r");

    struct denominations money[5];
    char a[100];
    char *p;
    int len=0;
    while(fgets(a,100,fl))
    {
        p=strtok(a,",");
        money[len].type=atoi(p);
        p=strtok(NULL,",");
        money[len].numberoftype=atoi(p);
        len++;
    }
    fclose(fl);

    int total=0;
    for(int i=0;i<4;i++)
    {
        total+=(money[i].type) * (money[i].numberoftype);
    }

    fl= fopen("denominations.txt","w");

    int temp,i,ret; 
 

    if(total>n)
    {
        ret=1;
        temp=n;
        for(i=0;i<4;i++)
        {
            money[i].numberoftype=money[i].numberoftype-temp/money[i].type;
            temp=temp%money[i].type;
            fprintf(fl,"%d,%d\n",money[i].type,money[i].numberoftype);
        }
    }
    else
    {
        ret=0;
        for(i=0;i<4;i++)
        {
            fprintf(fl,"%d,%d\n",money[i].type,money[i].numberoftype);
        }
    }


    fclose(fl);
    return (ret);
}