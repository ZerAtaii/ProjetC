typedef struct Account Account;
struct Account
{
    double amount;
    char lastname[50];
    char firstname[50];
    double spending[1000];
};

void initialize(Account a) {
    a.amount=0;
}
