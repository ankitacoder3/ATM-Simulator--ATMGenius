#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
int main()
{
    char cust_nm[50];
	int passw;
    char ch;
	printf("\nEnter Username:");
	scanf("%s",cust_nm);
	printf("\nEnter PIN:");
	scanf("%d",&passw);
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
    for(int i=0;i<len;i++)
    {
        char u[20];
        int p;
        strcpy(u,det[i].usern);
        p=det[i].PIN;
        if(strcmp(u,cust_nm)==0 && passw==p)
        {
            printf("succesfully logged in\n");
            homepage(u);
            break;
        }
        /*else  //error in this part so dont uncomment
        {
            int try=1;
            char ch;
            printf("Login failed.Either username or password is incorrect.You have 3 tries left.\n");
            while(try<=3)
            {
                printf("\nEnter Username:");
	            scanf("%s",cust_nm);
	            printf("\nEnter PIN:");
	            scanf("%d",&passw);
                if(strcmp(u,cust_nm)==0 && passw==p)
                {
                    printf("succesfully logged in\n");
                    homepage(u);
                    break;
                }

                else
                {
                    printf("Login failed.Either username or password is incorrect.You have %d tries left.\n",3-try);
                    try+=1;
                    
                }
            }
            if(try==4)
            {
                printf("sorry contact branch manager.");
                break;
            }
            
            
        }
        break;*/
    }
}
    