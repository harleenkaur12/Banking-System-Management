#include <iostream>
#include <fstream>
using namespace std;

// creates a class person having attributes storing the name, account number, account type and account balance of the customer respectively.
class person
{
protected:
    string name;
    int ac_no;
    string ac_type;
    int balance;
};

// creates a child class 'bank_account' inherited from its parent 'person' class.
class bank_account : public person
{
public:
    void create_Bank_Account(); 
    void display_all_details(); 
    void display_specefic();    
    void display_last();        
    void ac_exist();            
    void delete_account();      
};

//creates a child 'transaction' class inherited from the parent 'person' class.
class transaction : public person
{
public:
    void deposit();             
    void withdraw();            
    void display_balance();     
    float interest();           
};

//creates a child 'employee' class inherited from the parent 'person' class.
class employee : public person
{
public:
    void update_name();         
};

//function to create a new account
void bank_account::create_Bank_Account()
{
    fstream file;
    system("cls"); 
    cout << "\n\n\tCreate new account\t\t\t\t\n\n";
    cout << "Please enter the name of the Bank account holder : " << endl;
    cin.ignore();       
    getline(cin, name); 
    cout << "Please enter the account number of the holder : " << endl;
    cin >> ac_no;
    cout << "Please enter the account type(C/S) : " << endl;
    cin >> ac_type;
    cout << "Please enter the starting amount : " << endl;
    cin >> balance;
    file.open("bank_File.txt", ios::out | ios::app);
    file << " " << name << " " << ac_no << " " << ac_type << " " << balance << " "
         << "\n";
    file.close();
}

//Function to display details of all the customers
void bank_account::display_all_details()
{
    system("cls");
    fstream file;

    cout << "Showing details of all customers\n\n"
         << endl;
    file.open("bank_File.txt", ios::in);
    if (!file)
        cout << "File not found";
    else
    {
        file >> name >> ac_no >> ac_type >> balance;
        while (!file.eof())
        {
            cout << "Name of the customer: " << name << endl;

            cout << "Account No is: " << ac_no << endl;

            cout << "Type of account: " << ac_type<< endl;

            cout << "Amount deposited: " << balance << endl;

            cout << endl;
            file >> name>> ac_no >> ac_type >> balance;
        }
    }
    file.close();
}

//Function to display details of a particular customer
void bank_account::display_specefic()
{
    fstream file;
    int a;
    file.open("bank_File.txt", ios::in);
    if (!file)
        cout << " File not found";
    else
    {
        cout << "Enter account number:" << endl;
        cin >> a;
        while (!file.eof())
        {
            if (a == ac_no)
            {
                cout << "\n\nCustomer details:\n\n";
                cout << "Name of the customer: " << name << endl;

                cout << "Account No is: " << ac_no << endl;

                cout << "Type of account: " << ac_type << endl;

                cout << "Amount deposited: " << balance << endl;

                cout << endl;
            }
            file >> name >> ac_no >> ac_type >> balance;
        }
    }
}
//Function to display the details of the last customer
void bank_account::display_last()
{
    fstream file;
    file.open("bank_File.txt", ios::in);
    if (!file)
        cout << " File not found";
    else
    {
        file.seekg(EOF);
    
        cout << "\n\nDetails of Last Customer :\n\n";
        cout << "Name of the customer: " << name << endl;

        cout << "Account No is: " << ac_no << endl;

        cout << "Type of account: " << ac_type << endl;

        cout << "Amount deposited: " << balance << endl;

        cout << endl;
    }
    file >> name >> ac_no >> ac_type >> balance;
}
//Function to verify whether an account exists or not in a file
void bank_account::ac_exist()
{
    fstream file;
    int a;
    file.open("bank_File.txt", ios::in);
    if (!file)
        cout << " File not found";
    else
    {
        cout << "Enter account number:" << endl;
        cin >> a;
        while (!file.eof())
        {
            if (a == ac_no)
            {
                cout << "Yes account exist" << endl;
                break;
            }
            file >> name >> ac_no >> ac_type >> balance;
        }
    }
}
//Function to carry out a deposit and update the available balance
void transaction::deposit()
{
    system("cls");
    fstream file, file1;
    int t, count = 0;
    int ac_no_, new_balance;
    cout << "\n\n\t\t\t\tUpdate Book Record";
    file1.open("bank_File_1.txt",
               ios::app | ios::out);
    file.open("bank_File.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else
    {

        cout << "\n\nAccount number: ";
        cin >> ac_no_;
        file >> name >> ac_no;
        file >> ac_type >> balance;

        while (!file.eof())
        {
            if (ac_no_ == ac_no)
            {
                system("cls");
                cout << "\t\t\t\t"
                     << "Deposit amount";
                cout << "\nEnter amount to deposit : ";
                cin >> t;
                new_balance = balance + t;
                file1 << " " << name << " "
                      << ac_no << " "
                      << ac_type << " " << new_balance
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << name
                      << " " << ac_no
                      << " " << ac_type
                      << " " << balance
                      << "\n\n";
            file >> name >> ac_no;
            file >> ac_type >> balance;
        }
        if (count == 0)
            cout << "\n\nAccount"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("bank_File.txt");
    rename("bank_File_1.txt",
           "bank_File.txt");
}

//Function to carry out a withdraw process and update the available balance
void transaction::withdraw()
{
    system("cls");
    fstream file, file1;
    int t, count = 0;
    int ac_no_, new_balance;
    cout << "\n\n\t\t\t\tWithdraw amount";
    file1.open("bank_File_1.txt",
               ios::app | ios::out);
    file.open("bank_File.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else
    {

        cout << "\n\nAccount number: ";
        cin >> ac_no_;
        file >> name >> ac_no;
        file >> ac_type >> balance;

        // Till end of file is reached
        while (!file.eof())
        {
            if (ac_no_ == ac_no)
            {
                system("cls");
                cout << "\t\t\t\t"
                     << "Withdraw amount";
                cout << "\nEnter amount to withdraw: ";
                cin >> t;
                new_balance = balance - t;
                file1 << " " << name << " "
                      << ac_no << " "
                      << ac_type << " " << new_balance
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << name
                      << " " << ac_no
                      << " " << ac_type
                      << " " << balance
                      << "\n\n";
            file >> name >> ac_no;
            file >> ac_type >> balance;
        }
        if (count == 0)
            cout << "\n\nAccount"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    file.close();
    file1.close();
    remove("bank_File.txt");
    rename("bank_File_1.txt",
           "bank_File.txt");
}

//Function to delete an account
void bank_account::delete_account()
{
    string name_;
    int ac_no_;
    string ac_type_;
    int balance_;

    fstream file, file1;
    int count = 0;
    int accno;
    // Append file in output mode
    file1.open("bank_File_1.txt",
               ios::app | ios::out);
    file.open("bank_File.txt",
              ios::in);

    if (!file)
        cout << "File Opening Error...";
    else
    {

        cout << "Account No: : ";
        cin >> accno;
        file >> name_ >> ac_no_ >> ac_type_ >> balance_;
        while (!file.eof())
        {

            if (accno == ac_no_)
            {
                cout << "Delete  Account";
                cout << "Account is Deleted "
                        "Successfully...";
                count++;
            }
            else
                file1 << " " << name_
                      << " " << accno
                      << " " << ac_type_
                      << " " << balance_
                      << "\n\n";
            file >> name_ >> accno >> ac_type_ >> balance_;
        }
        if (count == 0)
            cout << "\n\nAccount"
                 << "Not Found...";
    }
    system("pause");

    // Close the file
    file.close();
    file1.close();
    remove("bank_File.txt");
    rename("bank_File_1.txt",
           "bank_File.txt");
}
//Function to display the updated available balance of a customer
void transaction::display_balance()
{
    fstream file;
    int a;
    file.open("bank_File.txt", ios::in);
    if (!file)
        cout << " File not found";
    else
    {
        cout << "Enter account number:" << endl;
        cin >> a;
        while (!file.eof())
        {
            if (a == ac_no)
            {
                cout << "\n\nCheck Balance:\n\n";

                cout << "Available Balance: " << balance << endl;

                cout << endl;
            }
            file >> name >> ac_no >> ac_type >> balance;
        }
    }
}

//Function to display the interest a customer has to pay
float transaction::interest()
{
}

//Function to update customer name
void employee ::update_name()
{
    system("cls");
    fstream file, file1;
    int t, count = 0;
    int ac_no_;
    string new_name;
    cout << "\n\n\t\t\t\tUpdate ";
    file1.open("bank_File_1.txt",
               ios::app | ios::out);
    file.open("bank_File.txt", ios::in);

    if (!file)
        cout << "\n\nFile Opening Error!";
    else
    {

        cout << "\n\nAccount number: ";
        cin >> ac_no_;
        file >> name >> ac_no;
        file >> ac_type >> balance;

        while (!file.eof())
        {
            if (ac_no_ == ac_no)
            {
                system("cls");
                cout << "Please enter the name of the Bank account holder : " << endl;
                cin.ignore(); // used so that input is done into the desired container
                getline(cin, new_name);
                name = new_name;

                ;
                file1 << " " << new_name << " "
                      << ac_no << " "
                      << ac_type << " " << balance
                      << "\n\n";
                count++;
            }
            else
                file1 << " " << name
                      << " " << ac_no
                      << " " << ac_type
                      << " " << balance
                      << "\n\n";
            file >> name >> ac_no;
            file >> ac_type >> balance;
        }
        if (count == 0)
            cout << "\n\nAccount"
                 << " Not Found...";
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("bank_File.txt");
    rename("bank_File_1.txt",
           "bank_File.txt");
}

int main()
{
    bank_account b;
    transaction t;
    employee e;

    int option;
    do
    {
        cout << endl;
        cout << "1.Add New Customer" << endl;
        cout << "2.Show data of All Customers" << endl;
        cout << "3.Deposit more money" << endl;
        cout << "4.Withdraw money" << endl;
        cout << "5.Check whether account exits or not" << endl;
        cout << "6.Update Name" << endl;
        cout << "7.Show data of a particular customer" << endl;
        cout << "8.Check Balance" << endl;
        cout << "9.Delete An Account" << endl;
        cout << "10.Show data of last customer " << endl;
        cout << "11.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            b.create_Bank_Account();
            break;
        case 2:
            b.display_all_details();
            break;
        case 3:
            t.deposit();
            break;
        case 4:
            t.withdraw();
            break;
        case 5:
            b.ac_exist();
        case 6:
            e.update_name();
            break;
        case 7:
            b.display_specefic();
            break;
        case 8:
            t.display_balance();
            break;
        case 9:
            b.delete_account();
            exit(0);
        case 10:
            b.display_last();
            break;
        case 11:
            exit(0);
        default:
            cout << "enter correct option" << endl;
            exit(0);
        }
    } while (option != 7);

    return 0;
}
