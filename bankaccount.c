typedef struct Account Account;
struct Account
{
    double amount=0;
    char lastname[50];
    char firstname[50];
    double spending[1000];
};


void setAmount(Account a,double val) {
    (a).amount=val;
}

double getAmount(Account a) {
    return (a).amount;
}

