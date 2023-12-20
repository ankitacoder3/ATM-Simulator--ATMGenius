#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct details
{
    int acc_no,age,PIN;
    long int phoneno;
    long double bal;
    char name[60],usern[60],email[75];
    
};
int data ()
{
   /*struct details det[20];
   FILE *fl;
   fl= fopen ("data.txt", "w");
   if (fl == NULL) 
   {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
   char ch='y';
   int cnt=0;
   while (ch=='y')
   {
       printf("enter name: ");
       scanf("%s",det[cnt].name);
       printf("\n");
       printf("enter username: ");
       scanf("%s",det[cnt].usern);
       printf("\n");
       printf("enter email: ");
       scanf("%s",det[cnt].email);
       printf("\n");
       printf("enter balance: ");
       scanf("%Lf",&det[cnt].bal);
       printf("\n");
       printf("enter phone no: ");
       scanf("%ld",&det[cnt].phoneno);
       printf("\n");
       printf("enter account number: ");
       scanf("%d",&det[cnt].acc_no);
       printf("\n");
       printf("enter age: ");
       scanf("%d",&det[cnt].age);
       printf("\n");
       printf("enter pin: ");
       scanf("%d",&det[cnt].PIN);
       printf("\n");

       printf("do you want to continue to enter details(y/n): ");
       scanf(" %c",&ch);

       if (ch=='y')
            cnt+=1;
       else
            ch='n';

   }
   for (int i=0;i<=cnt;i++)
   {
       fwrite (&det[i], sizeof(struct details), 1, fl);
   }
   if(&fwrite != 0)
      printf("Contents to file written successfully !\n");
   else
      printf("Error writing file !\n");
   fclose (fl);*/
   FILE *inf;
   struct details inp;
   inf = fopen ("data.txt", "r");
   if (inf == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
   
   while(fread(&inp, sizeof(struct details), 1, inf))
      printf ("name=%s\tusername=%s\temail=%s\tbalance=%Lf\tphone no.=%ld\taccount no.=%d\tage=%d\tpin=%d\n",
      inp.name, inp.usern,inp.email,inp.bal,inp.phoneno,inp.acc_no,inp.age,inp.PIN);
   fclose (inf);
}
