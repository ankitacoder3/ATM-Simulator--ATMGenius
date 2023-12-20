struct details
{
    int acc_no, age,PIN;
    long int phoneno;
    double bal;
    char name[60],usern[60],email[75];
    
};
struct denominations
{
   int type;
   int numberoftype;

};

void homepage(char *user);
void chk_bal(char *user);
void deposit(char *user);
void withdraw(char *user);
void change_passw(char *user);
int denominations(int n);

int denominations_deposit(int cash);
void recpt_w (int cash);
void quit();
