#include<bits/stdc++.h>
using namespace std;
class ATM
{
    string name;
    string mobile;
    string debitCardNo;
    string accountNo;
    int pin;
    int balance ;
    void goHome();
    public:
    ATM(string name,string mobile,string debitCardNo,string accountNo,int balance )
    {
        this->name=name;
        this->mobile=mobile;
        this->debitCardNo=debitCardNo;
        this->accountNo=accountNo;
        this->pin=pin;
        this->balance=balance;
    }
    void home();
    void input();
    void banking ();
    void pingeneration();
    int convetInt(string str );
    void pinchange();
    void pincheck();
    void menu();
    void equiry();
    void details();
    void withdrawal(){
        pincheck();
        cout<<"ENTER AMOUNT : "<<flush;
        int amount;
        cin>>amount;
        if(amount<this->balance>amount)
        {
            balance=balance-amount;
            cout<<"congratulation "<<endl<<"SUCCEEFULLY COMPLEATED TRANSACTION"<<endl<<"Pleass Collect Your Cash"<<endl;
             goHome();//go to home or exit
        }else {
            cout<<"Sufficent balance not Avilable "<<endl;
             goHome();  
        }
    }

    string getmobile()
    {
        return mobile;
    }
    string getaccount()
    {
        return accountNo;
    }

};
void ATM::home()
{
    system("cls");
    cout<<"------SBI ATM-------"<<endl;
    cout<<"1. BANKING"<<endl;
    cout<<"2. PIN GENENRATION "<<endl;
    cout<<"3. FAST CASH"<<endl;
    cout<<"4. WITHDRAWAL "<<endl;
    cout<<"5. QUICK CHASH"<<endl;
    cout<<"6. More... OPTION"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"ENTER OPTION : "<<flush;
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1: banking();
                break;
        case 2: pingeneration();
                break;
        case 3: withdrawal();
                break;
        case 4: withdrawal();
                break;
        case 5: withdrawal();
                break;
        case 6: menu();
        case 0: exit(0);
                break;
    }
}

void ATM::input()
{
    system("cls");
    int count=0;
   do{
     cout<<"ENTER YOUR DEBIT CARD NO : "<<flush;
    string  debit;
    cin>>debit;
    if(this->debitCardNo==debit)
    {
        home();
    }else {
        cout<<"ENTERED DEBIT CARD NO IS IN VALID "<<endl<<"TRY AGAIN "<<endl;
    }
    count ++;
   }while(count<3);
}
void ATM::banking()
{
    system("cls");
    cout<<"1. PIN GENERATION"<<endl;
    cout<<"2. PIN CHANDGE"<<endl;
    cout<<"0. EXIT..."<<endl;
    int choice;
    cout<<"ENTER OPTION : "<<flush;
    cin>>choice ;
    switch(choice )
    {
        case 1: pingeneration();
                break;
        case 2:pinchange();
              break;
        case 0: exit(0);
                break;

    }
}
void ATM ::pingeneration()
{
    cout<<"ENTER YOUR ACCOUNT NO: "<<flush;
    string account ;
    cin>>account;
    string mobile;
    cout<<"ENTER REGISTER MOBILE NO: "<<flush;
    cin>>mobile ;
    if(getmobile() == mobile && getaccount()==account)
    {
        system("cls");
        int tempin=convetInt(mobile);
        this->pin=tempin;
        cout<<"congratulation"<<endl<<"SUCCEEFULLY GENERATED YOUR PIN "<<endl;
        cout<<"TEMPRORARY PIN : "<<tempin<<endl;
        goHome();
    }else {
        system("cls");
        cout<<"SORRY! "<<endl<<"UNSUCCEEFULLY GENERATED YOUR PIN BECAUSE EITHER ACCOUNT NUMBER OR MOBILE NUMBER IS INVALID"<<endl;
        goHome();
    }
}
int ATM::convetInt(string str)
{
    int p=0;
    for(int i=0; i<4; i++)
    {
        int last=str[i]-'0';
        p=p*10+last;
    }
    return p;
}
void ATM::pinchange()
{
    pincheck();
    int inpin;
    int cpin;
    cout<<"ENTER NEW PIN : "<<flush;
    cin>>inpin;

    cout<<"RE-ENTER NEW PIN: "<<flush;
    cin>>cpin;
    if(inpin==cpin)
    {
        this->pin=cpin;
        cout<<"Congratulation!"<<endl<<"Succeefully Changed Your PIN "<<endl;
        goHome();
    }else {
        cout<<"TRY AGAIN"<<endl;
         goHome();
    }
    
}
void ATM::pincheck()
{
    cout<<"ENTER YOUR PIN : "<<flush;
    int epin;
    cin>>epin;
    if(this->pin!=epin)
    {
        cout<<"SORRY ! "<<endl<<"ENTERED PIN INVALID "<<endl;
         goHome();
    }
}


void ATM ::menu()
{
    system("cls");
    cout<<"1. Balance Enquiry"<<endl;
    cout<<"2. View Details "<<endl;
    cout<<"0. Return Home Page.."<<endl;
    int choice ;
    cout<<"ENTER OPTION: "<<flush;
    cin>>choice;
    switch(choice)
    {
        case 1: equiry();
                break;
        case 2: details();
                break;
        case 0: home();
                break;
    }
}
void ATM::equiry()
{
    pincheck();
    cout<<"Now Avilable Balance : "<<this->balance<<endl;
    goHome();
}
void ATM::details()
{
    system("cls");
    cout<<"------Details---------"<<endl;
    cout<<"Name : "<<this->name<<endl;
    cout<<"Mobile No: "<<this->mobile<<endl;
    cout<<"Account No: "<<this->accountNo<<endl;
}

void ATM ::goHome()
{
    int Home;
    cout<<"Press 1 to Home Else Exit. : "<<flush;
    cin>>Home;
    if(Home==1)
    home();
    else
    exit(0);
}
///////////////////////////
int main()
{
    ATM A1("Md Jehid Alam","8100000000","0987654321","1234567890",123);
    A1.input();
    //debit card No : 0987654321
    //mobile NO : 8100000000
    //account No: 1234567890
    // balance : 123
}
