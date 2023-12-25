//--summary--
//"void check_denom (int cash, int max_2000, int max_500, int max_200, int max_100)" is the function --(to check how many notes r dispensed)
//main has some input values--which have to be in the text file--common for an atm



//deno1.c
#include <stdio.h>
#include <math.h>
void check_denom (int cash, int max_2000, int max_500, int max_200, int max_100);


//in main---steps-(0-1),(0-2)-- to be got from text file

int  main(void)
{


   	//step(0-1)-input (cash)
	int c;
        printf("cash (to be withdrawn) :   ");
	scanf("%d",&c); 

   	//step(0-2)-input (max no of notes present in atm)
	int m_2000 = 100;
	int m_500 = 100;
	int m_200 = 100;
	int m_100 = 100;


	//step(0-3)-- calling function
	check_denom(c,m_2000,m_500,m_200,m_100);

 
}

void check_denom (int cash, int max_2000, int max_500, int max_200, int max_100)
{

	//step1-defining the different cash available
	int rs_100 = 100;
	int rs_200 = 200;
	int rs_500 = 500;
	int rs_2000 = 2000;
	int flag;


    //step2-keeping track of no. of notes needed


    //2000
    int withdrawed_2000 = cash / rs_2000;
    flag=1;
    while (cash>= rs_2000 && flag == 1)
    {
        if ( withdrawed_2000 <= max_2000 )
	{	
		cash = cash - rs_2000 ;
        	cash = round(cash) ;
		max_2000 = max_2000 - withdrawed_2000 ;	
	}
	else
	{
		cash = cash - ( max_2000 * 2000 ) ;
        	cash = round(cash) ;
		withdrawed_2000 = max_2000 ;
		max_2000 = 0 ;	
		flag =2;
	}
    }
    //printf ("%d \n",withdrawed_2000);
    //printf ("%d --- \n",max_2000);



    //500
    int withdrawed_500 = cash/ rs_500; 
    flag=1;
    while (cash>= rs_500 && flag == 1)
    {
        if ( withdrawed_500 <= max_500 )
	{	
		cash = cash - rs_500 ;
        	cash = round(cash) ;
		max_500 = max_500 - withdrawed_500 ;	
	}
	else
	{
		cash = cash - ( max_500 * 500 ) ;
        	cash = round(cash) ;
		withdrawed_500 = max_500 ;
		max_500 = 0 ;	
		flag =2;
	}
    }
    //printf ("%d \n",withdrawed_500);
    //printf ("%d --- \n",max_500);



    //200
    int withdrawed_200 = cash / rs_200; 
    flag=1;
    while (cash>= rs_200 && flag == 1)
    {
        if ( withdrawed_200 <= max_200 )
	{	
		cash = cash - rs_200 ;
        	cash = round(cash) ;
		max_500 = max_200 - withdrawed_200 ;	
	}
	else
	{
		cash = cash - ( max_200 * 200 ) ;
        	cash = round(cash) ;
		withdrawed_200 = max_200 ;
		max_200 = 0 ;	
		flag =2;
	}
    }
    //printf ("%d \n",withdrawed_200);
    //printf ("%d --- \n",max_200);
 

    //100
    int withdrawed_100 = cash / rs_100; 
    flag=1;
    while (cash>= rs_100 && flag == 1)
    {
        if ( withdrawed_100 <= max_100 )
	{	
		cash = cash - rs_100 ;
        	cash = round(cash) ;
		max_100 = max_100 - withdrawed_100 ;	
	}
	else
	{
		cash = cash - ( max_100 * 100 ) ;
        	cash = round(cash) ;
		withdrawed_100 = max_100 ;
		max_100 = 0 ;	
		flag =2;
	}
    }
    //printf ("%d \n",withdrawed_100);
    //printf ("%d --- \n",max_100);
  

    	// step3-output
	if (cash != 0)
	{
		if( max_2000==0 && max_500==0 &&  max_200==0 &&  max_100==0 )
		printf("The ATM is out of notes! You can only get these many no. of notes:\n");
		else 
		printf("INVALID amount entered. Enter in denominations of 2000/500/200/100! Try again.\n");
		
	}
    	printf("The cash dispensed is : \n Rs 2000 - %d nos \t Rs 500 - %d nos \t Rs 200 - %d nos \t Rs 100 - %d nos \t \n",withdrawed_2000,withdrawed_500,withdrawed_200,withdrawed_100);
	//printf("Remaining no. of notes in atm: \n Rs 2000 - %d nos \t Rs 500 - %d nos \t Rs 200 - %d nos \t Rs 100 - %d nos \t \n",max_2000,max_500,max_200,max_100);    
	
   //step4-writing max values of notes remaining in atm to atm.txt
   FILE* f2= fopen("atm.txt","w");
   fprintf(f2,"\n%d,%d,%d,%d",max_2000,max_500,max_200,max_100);
   //printf("successfuly changed values\n");
   fclose(f2);

}
