//it has a small error in the phoneno. part
//20 entries r done
//stored in file2.txt

//data part2
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//customerid -6 , acc no-7
struct customer_account
{
	char name[60],email_id[75],usern[60];
	long int acc_no,phoneno;
	long double bal;
	int age,PIN;
	
};


int main(void)
{

	//input-no. of customers
	int n;
	printf("enter the no. of customer-details u want to enter:\t");
	scanf("%d",&n);


	//inputing customer details

	for(int i = 0; i<n; i++)
	{
		struct customer_account ci;
 		printf("for customer:%d: \n",i);

		printf("enter name: \t");
		scanf("%s",&ci.name);	

		printf("enter usern:\t");
		scanf("%s",&ci.usern);

		printf("enter email_id:\t");
		scanf("%s",&ci.email_id);

		printf("enter balance:\t");
		scanf("%Lf",&ci.bal);

		printf("enter phoneno:\t");
		scanf("%ld",&ci.phoneno);

		printf("enter acc_no:\t");
		scanf("%ld",&ci.acc_no);

		printf("enter age:\t");
		scanf("%d",&ci.age);

		printf("enter PIN:\t");
		scanf("%d",&ci.PIN);

		//open file datafile2.txt in append mode
    		FILE *fptr = fopen("file2.txt", "a");
    		if (fptr == NULL)
    		{
        	printf("Could not open file");
    		}

		//printing into file
		fprintf(fptr,"name=%s \t username=%s \t email=%s \t balance=%Lf \t phone no.=%ld \t account no.=%ld \t age=%d \t pin=%d \n",ci.name,ci.usern,ci.email_id,ci.bal,ci.phoneno,ci.acc_no,ci.age,ci.PIN);
		
		//closing file
		printf("Succesfully printed details to the file \n");
		fclose(fptr);
	}


}
