#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "header.h"
void homepage(char *user)
{
    int ext = 1;
    char choice ='e',ans ='y';
    printf("\n\nCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("WELCOME TO THE BANK ATM SERVICE\n\n");
    printf("Select:\n");
    printf("a) Check Balance\n");
    printf("b) Withdraw Cash\n");
    printf("c) Deposit Cash\n");
    printf("d) Reset Password\n");
    printf("e) Quit\n");

	while(ans=='y')
	{
		printf("\nEnter your choice: ");
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
	printf("\n\nDo you want to enter another choice (y/n): ");
    	fflush(stdin);
    	scanf("%c",&ans);
	}

	if(ans=='n')
	{
		printf("THANK YOU FOR USING BANK ATM\n");
	}	
}

void chk_bal(char *user)
{
    FILE *fl;
	fl= fopen("customer.txt","r");
    double balance;
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
            balance=strtod(p,&p);
            printf("Your balance is Rs %lf",balance);
        }
    }
    fclose(fl);
}

void withdraw(char *user)
{
    int w_cash;
    printf("ENTER THE AMOUNT TO WITHDRAW: Rs");
    scanf("%d",&w_cash);

    double currentbal;
    int flag2=2;

    FILE *fl;
	fl= fopen("customer.txt","r");

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
            fl= fopen("customer.txt","w");
            for(int i=0;i<len;i++)
            {
                if(strcmp(det[i].usern,user)==0)
                {
                    currentbal=det[i].bal;
                    currentbal=currentbal-w_cash;
                    printf("PLEASE COLLECT YOUR CASH.\n");
                    printf("Your current balance is Rs %Lf",currentbal);
                    det[i].bal=currentbal;

                }
                fprintf(fl,"\n%s,%s,%s,%lf,%ld,%d,%d,%d",det[i].name,det[i].usern,det[i].email,det[i].bal,det[i].phoneno,det[i].acc_no,det[i].age,det[i].PIN);
            }
            fclose(fl);

	    flag2=1;
        }
        else
        {
            printf("At present amount mentioned is unavailable in the atm\n");
        }

    }

    //printing tracked denominations
    if (flag2 ==1)
    {
    	char select_denom;
    	printf("\n \nDo you want the receipt for the amount(in terms of denominations) that is dispensed (y/n): ");
    	fflush(stdin);
    	scanf("%c",&select_denom);
    	if (select_denom=='y')
    	{
		recpt_w (w_cash);
    	}                 		
    	else
	{
    		printf("\nYour cash is dispensed.");
	}
    }
}

void deposit(char *user)
{
    double currentbal;
    double d_cash;
    printf("ENTER THE AMOUNT TO DEPOSIT:Rs");
    scanf(" %lf",&d_cash);
    
    int flag=denominations_deposit(d_cash);

    FILE *fl;
	fl= fopen("customer.txt","r");

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
        det[len].bal=strtod(p,&p);
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
    fl= fopen("customer.txt","w");
    for(int i=0;i<len;i++)
    {
        if(strcmp(det[i].usern,user)==0)
        {
            currentbal=det[i].bal;
            currentbal=currentbal+flag;
	    if (flag == d_cash)
	    {
		printf("The number of notes you have entered are successfully deposited.\n");
            	printf("Your current balance is Rs %lf",currentbal);
            }
	    else if (flag < d_cash)
	    {
		printf("The no. of notes deposited is less than the amount entered to be deposited.\n");
		printf("The number of notes you have entered are successfully deposited.\n");
            	printf("Your current balance is Rs %lf",currentbal);
            }
	    else
	    {
                printf("The no. of notes deposited is more than the amount entered to be deposited.\n");
		printf("The number of notes you have entered are successfully deposited. \n");
            	printf("Your current balance is Rs %lf",currentbal);
            }
            det[i].bal=currentbal;

        }
        fprintf(fl,"\n%s,%s,%s,%lf,%ld,%d,%d,%d",det[i].name,det[i].usern,det[i].email,det[i].bal,det[i].phoneno,det[i].acc_no,det[i].age,det[i].PIN);
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
	fl= fopen("customer.txt","r");

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
        det[len].bal=strtod(p,&p);
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
    fl= fopen("customer.txt","w");
    for(int i=0;i<len;i++)
    {
        if(strcmp(det[i].usern,user)==0)
        {
            opin=det[i].PIN;
            det[i].PIN=npin;
            printf("YOUR NEW PIN HAS BEEN SUCCESFULLY UPDATED.\n");

        }
        fprintf(fl,"\n%s,%s,%s,%lf,%ld,%d,%d,%d",det[i].name,det[i].usern,det[i].email,det[i].bal,det[i].phoneno,det[i].acc_no,det[i].age,det[i].PIN);
    }
    fclose(fl);
    
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

int denominations_deposit(int cash)
{
	//step1- input

	int n_2000, n_500, n_200, n_100;
	printf("\nEnter the no. of notes that you are depositing, as follows:\n");

	printf("Enter no. of Rs 2000 notes:\t");
	scanf("%d",&n_2000);
	printf("Enter no. of Rs 500 notes:\t");
	scanf("%d",&n_500);
	printf("Enter no. of Rs 200 notes:\t");
	scanf("%d",&n_200);
	printf("Enter no. of Rs 100 notes:\t");
	scanf("%d",&n_100);

	//step2- writing to file
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

	money[0].numberoftype += n_2000;
	money[1].numberoftype += n_500;
	money[2].numberoftype += n_200;
	money[3].numberoftype += n_100;

	fl= fopen("denominations.txt","w");
	for(int i=0;i<4;i++)
        {
            fprintf(fl,"%d,%d\n",money[i].type,money[i].numberoftype);
        }
	fclose(fl);

	int deposited = ( (n_2000*2000) + (n_500*500) + (n_200*200) + (n_100*100) );

	return deposited;
}

void recpt_w (int cash)
{

	//step1-defining the different cash available
	int rs_100 = 100;
	int rs_200 = 200;
	int rs_500 = 500;
	int rs_2000 = 2000;
	int w_cash = cash;


    //step2-keeping track of no. of notes needed


    //2000
    int withdrawed_2000 = cash / rs_2000;
    while (cash>= rs_2000)
    {
	cash = cash - rs_2000 ;
        cash = round(cash) ; 	
    }

    //500
    int withdrawed_500 = cash/ rs_500; 
    while (cash>= rs_500)
    {	
		cash = cash - rs_500 ;
        	cash = round(cash) ;
    }

    //200
    int withdrawed_200 = cash / rs_200; 
    while (cash>= rs_200)
    {	
		cash = cash - rs_200 ;
        	cash = round(cash) ;
    }

    //100
    int withdrawed_100 = cash / rs_100; 
    while (cash>= rs_100)
    {	
		cash = cash - rs_100 ;
        	cash = round(cash) ;
    }


    	// step3-output
	printf("\n\n\n \tBANK ATM\n");
	printf("\nRECEIPT: For amount withdrawn\n\n");
	printf("Withdrawed amount: Rs %d \n",w_cash);
    	printf("\nThe amount that is dispensed,\nin terms of denominations is:\n \n Rs 2000 - %d nos \n Rs 500 - %d nos \n Rs 200 - %d nos \n Rs 100 - %d nos \n \n \n",withdrawed_2000,withdrawed_500,withdrawed_200,withdrawed_100);
	printf("THANK YOU. HAVE A NICE DAY. \n\n");    	

}
void quit()
{
    printf("THANK YOU FOR USING BANK ATM\n");
    exit(0);
    return;
}