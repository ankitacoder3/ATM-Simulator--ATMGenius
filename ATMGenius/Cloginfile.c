#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cserverfile.html"
void login(struct customer c)
{
	char cust_nm[50],ch='y';
	int PIN,try=1;
	printf("\nUsername:");
	scanf("%s",&cust_nm);
	printf("\nPIN:");
	scanf("%d",&PIN);
	FILE *F;
	F = fopen("data.txt","r");
	
	while(fread(&c, sizeof(c), 1, F))
	{
		if((strcmp(cust_nm,c.usern)==0) && PIN==c.PIN)
			{
				printf("\nSuccessfully logged in!");
				break;
			}
		else
			{
				printf("\nWrong username/PIN Do you want to enter again ? ");
				fflush(stdin);
				scanf("%c",ch);
				if(ch=='y' && try<=3)
					{
						printf("\nUsername:");
						scanf("%s",&cust_nm);
						printf("\nPIN:");
						scanf("%d",&PIN);
						if((strcmp(cust_nm,c.usern)==0) && PIN==c.PIN)
							printf("\nSuccessfully logged in!");
						else
							{
								printf("\nWrong username/PIN Do you want to enter again(y/n)? This is your %d try",try);
								fflush(stdin);
								scanf("%c",ch);
							}
						try+=1;
					}
				else
					printf("You have been locked out of your account , contact your branch manager\n");
					
		}
		
	}
				fflush(stdin);
				
				
}
