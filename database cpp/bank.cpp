#include <iostream>
using namespace std;

class Bank {
    int accno;
    char name[30];
    long balance;

public:
    void OpenAccount()
    {
        cout << "Enter Name: ";
        cin >> name;
		cout << "Enter Account Number: ";
        cin >> accno;
        cout << "Enter  Balance: ";
        cin >> balance;
    }
    void ShowAccount()
    {
        cout << "Account Number: " << accno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit()
    {
        long amt;
        cout << "Enter Amount to be deposited : ";
        cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()
    {
        long amt;
        cout << "Enter Amount to be withdraw : ";
        cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            cout << "Insuffiecient balance" << endl;
    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (accno == a) {
        ShowAccount();
        return (1);
    }
    return (0);
}

// main code
int main()
{
    cout << "Vivek Dharewa - 20BAI10032\n";
	Bank C;
    int ch , found;
    long a;
    char repeat = 'y';

    while(repeat == 'y' || repeat == 'Y')
        {
        cout << "\n1. Open Account\n2. By Account No\n3. Deposit\n4. Withdraw\n" << endl;
        cout << "Please input your choice: ";
        cin >> ch;

        switch (ch) 
		 {
        
		 case 1: C.OpenAccount();
				break;
				                
         case 2:
            	cout << "Account Number : ";
            	cin >> a;
                found = C.Search(a);
                if (found)
                    break;
                else
                cout << "Record Not Found" << endl;
                break;
        
		 case 3: 
            	cout << "Account Number To Deposit Amount : ";
            	cin >> a;
                found = C.Search(a);
                if (found) 
                    C.Deposit();
                else
                	cout << "Record Not Found" << endl;
            	break;
        
		 case 4: 
         		cout << "Account Number To Withdraw Amount : ";
            	cin >> a;
            	found = C.Search(a);
            	if (found) 
                	C.Withdrawal();
            	else
                	cout << "\nRecord Not Found" << endl;
            	break;
            
         default: cout << "Wrong Option !";
                  break;
}
        cout << "\nDo you wish to continue(y/n) : " ;
        cin  >> repeat;
       }

    return 0;
}

