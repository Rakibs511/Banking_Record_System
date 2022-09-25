#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
using namespace std;

class Bank
{
private:
    int count = 0;
    int total;                           //count account holder
    string exittext;                    //yes or no
    string id;                         //input id
    struct person
    {
        string firstname,lastname, ID, address;
        double cash;
        int contact;
    }person[100];
public:
    Bank()
    {
        total = 0;
    }
    void choice();
    void person_Data();
    void add_money();
    void out_money();
    void search_Balence();
    void data_list();
    void close_Account();
    void Change();
    void go_back();
    HANDLE colorHandle = GetStdHandle(STD_OUTPUT_HANDLE);
};


int main()
{
    Bank object;
    object.choice();
    system("pause>NULL");
}

void Bank::choice()
{
    char ch;
    while (1)
    {
        SetConsoleTextAttribute(colorHandle, 3);
        cout << "\n______________________________";
        SetConsoleTextAttribute(colorHandle, 15);
        cout << "\n          MAIN MENU  " << endl;
        SetConsoleTextAttribute(colorHandle, 3);
        cout << "------------------------------" << endl << endl;
        SetConsoleTextAttribute(colorHandle, 6);
        cout << "  01. Create New Account" << endl;
        SetConsoleTextAttribute(colorHandle, 1);
        cout << "  02. Deposit Amount" << endl;
        SetConsoleTextAttribute(colorHandle, 7);
        cout << "  03. Withdraw Amount" << endl;
        SetConsoleTextAttribute(colorHandle, 13);
        cout << "  04. Balance Enquiry" << endl;
        SetConsoleTextAttribute(colorHandle, 9);
        cout << "  05. All Account Holder List" << endl;
        SetConsoleTextAttribute(colorHandle, 11);
        cout << "  06. Close An Account" << endl;
        SetConsoleTextAttribute(colorHandle, 8);
        cout << "  07. Modify An Account" << endl;
        SetConsoleTextAttribute(colorHandle, 4);
        cout << "  08. Exit" << endl << endl;
        if (count==0)
        {
            PlaySound(TEXT("welcome_to_our_Bank.wav"), NULL, SND_SYNC);
            count++;
            PlaySound(TEXT("this_is_Main_menu.wav"), NULL, SND_SYNC);
        }
        SetConsoleTextAttribute(colorHandle, 16);
        cout << " Select Your Option From (1 to 8)" << endl;
        SetConsoleTextAttribute(colorHandle, 2);
        ch = _getch();
        system("CLS");
        switch (ch)
        {
        case '1':
            Bank::person_Data();
            break;
        case '2':
            if (total == 0)
            {
                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n\n\n  No Data Found\n" << endl;
                PlaySound(TEXT("please_open_a_new_account_first.wav"), NULL, SND_SYNC);
                system("cls");
            }
            else
            {
                Bank::add_money();
            }
            break;
        case '3':
            if (total == 0)
            {
                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n\n\n  No Data Found\n" << endl;
                PlaySound(TEXT("please_open_a_new_account_first.wav"), NULL, SND_SYNC);
                system("cls");
            }
            else
            {
                Bank::out_money();
                PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
            }
            break;
        case '4':
            if (total == 0)
            {
                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n\n\n  No Data Found\n" << endl;
                PlaySound(TEXT("please_open_a_new_account_first.wav"), NULL, SND_SYNC);
                system("cls");
            }
            else
            {
                Bank::search_Balence();
                PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
            }
            break;
        case '5':
            if (total == 0)
            {
                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n\n\n  No Data Found\n" << endl;
                PlaySound(TEXT("please_open_a_new_account_first.wav"), NULL, SND_SYNC);
                system("cls");
            }
            else
            {
                Bank::data_list();
                PlaySound(TEXT("Account_Holder_List_loaded_successful.wav"), NULL, SND_SYNC);
                SetConsoleTextAttribute(colorHandle, 7);
                system("pause");
                system("cls");
                PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
            }
            break;
        case '6':
            if (total == 0)
            {
                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n\n\n  No Data Found\n" << endl;
                PlaySound(TEXT("please_open_a_new_account_first.wav"), NULL, SND_SYNC);
                system("cls");
            }
            else
            {
                Bank::close_Account();
            }
            break;
        case '7':
            if (total == 0)
            {
                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n\n\n  No Data Found\n" << endl;
                PlaySound(TEXT("please_open_a_new_account_first.wav"), NULL, SND_SYNC);
                system("cls");
            }
            else
            {
                Bank::Change();
            }
            break;
        case '8':
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "\n\n\n\n\n   Do you want to Exit? 'Yes or no': ";
            PlaySound(TEXT("Exit.wav"), NULL, SND_SYNC);
            cin >> exittext;
            system("cls");
            if (exittext=="YES"|| exittext == "Yes" || exittext == "yes")
            {
                PlaySound(TEXT("ok_good_bye.wav"), NULL, SND_SYNC);
                SetConsoleTextAttribute(colorHandle, 7);
                exit(0);
            }
            else { 
                PlaySound(TEXT("ok_now_you_can_access_main_menu.wav"), NULL, SND_SYNC);
                choice();
            }

            break;
        default:
        {
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "\a  Wrong Input\n" << endl;
            break;
        }

        }
    }
}

void Bank::person_Data()
{
    go_back();
    
    cout << "_______________________" << endl;
    cout << "  Create New Account ";
    SetConsoleTextAttribute(colorHandle, 5);
    cout << total + 1 << endl;
    SetConsoleTextAttribute(colorHandle, 7);
    cout << "-----------------------" << endl << endl;
    cout << "  Enter your first name: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> person[total].firstname;
    SetConsoleTextAttribute(colorHandle, 7);
    cout << "  Enter your last name: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> person[total].lastname;
    SetConsoleTextAttribute(colorHandle, 7);
    cout << "  ID: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> person[total].ID;
    SetConsoleTextAttribute(colorHandle, 7);
    for (int i = 0; i < total; i++)
    {
        if (person[total].ID == person[i].ID)
        {
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "\n\n  Sorry! Already have an account opened with this ID. Try again!\n\n";
            PlaySound(TEXT("Alrady_have_an_account.wav"), NULL, SND_SYNC);
            system("cls");
            choice();
        }

    }
    cout << "  Address: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin.ignore();
    getline(cin, person[total].address);
    SetConsoleTextAttribute(colorHandle, 7);
    cout << "  Contact: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> person[total].contact;
    SetConsoleTextAttribute(colorHandle, 7);
    cout << "  Total Cash: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> person[total].cash;
    total++;
    if (total>100)
    {
        cout << "\n\n\a  Sorry! We have reached the limit.\n";
        PlaySound(TEXT("reached_the_limit.wav"), NULL, SND_SYNC);
        choice();
    }
    SetConsoleTextAttribute(colorHandle, 2);
    cout << "\n\n  Account created successfully!\n\n";
    PlaySound(TEXT("succesful_create.wav"), NULL, SND_SYNC);
    SetConsoleTextAttribute(colorHandle, 7);
    system("cls");
    PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
}

void Bank::add_money()
{
    go_back();

    SetConsoleTextAttribute(colorHandle, 7);
    cout << "\n  Enter Your ID: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> id;
    system("cls");
    double cash;
    SetConsoleTextAttribute(colorHandle, 3);
    cout << "__________________" << endl;
    SetConsoleTextAttribute(colorHandle, 15);
    cout << "  Deposit Amount" << endl;
    SetConsoleTextAttribute(colorHandle, 3);
    cout << "------------------" << endl;
    SetConsoleTextAttribute(colorHandle, 7);
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "  Name: " << person[i].firstname<<" "<<person[i].lastname << endl;
            cout << "  Address: " << person[i].address << endl;
            cout << "  Contact: " << person[i].contact << endl;
            cout << "\n  Existing Cash: " << person[i].cash <<" $" << endl << endl;
            cout << "  Enter Your Cash: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin >> cash;
            system("cls");
            person[i].cash += cash;                      
            SetConsoleTextAttribute(colorHandle, 6);
            cout << "\n  New Cash Is: ";
            SetConsoleTextAttribute(colorHandle, 7);
            cout << person[i].cash <<" $" << endl << endl;
            PlaySound(TEXT("deposit_successful.wav"), NULL, SND_SYNC);
            system("cls");
            break;
        }
        if (i == total - 1)
        {
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "  Search Result No Found\n" << endl;
            PlaySound(TEXT("Your_id_is_incorrect.wav"), NULL, SND_SYNC);
            system("cls");
            PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
        }
    }
}

void Bank::out_money()
{
    go_back();

    SetConsoleTextAttribute(colorHandle, 7);
    cout << "\n  Enter Your ID: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> id;
    SetConsoleTextAttribute(colorHandle, 7);
    system("cls");
    double cash;
    SetConsoleTextAttribute(colorHandle, 6);
    cout << "___________________" << endl;
    cout << "  Withdraw Money" << endl;
    cout << "-------------------" << endl;
    SetConsoleTextAttribute(colorHandle, 7);
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "  Name: " << person[i].firstname<<" "<<person[i].lastname << endl;
            cout << "  Address: " << person[i].address << endl;
            cout << "  Contact: " << person[i].contact << endl;
            cout << "\n  Existing Cash " << person[i].cash <<" $" << endl << endl;
            cout << "  Enter Your Cash: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin >> cash;
            SetConsoleTextAttribute(colorHandle, 3);
            system("cls");
            if (cash>person[i].cash)
            {
                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n\n  Sorry you don't have "<<cash<<" $ in your account.\n\n";
                PlaySound(TEXT("Sorry_you_don't_have_enough_money_in_your_account.wav"), NULL, SND_SYNC);
                system("pause");
                system("cls");
            }
            else
            {
                system("cls");
                SetConsoleTextAttribute(colorHandle, 2);
                cout << "\n\n  Withdraw Successful!\n\n";
                PlaySound(TEXT("withdraw_success.wav"), NULL, SND_SYNC);
                SetConsoleTextAttribute(colorHandle, 3);
                person[i].cash -= cash;
                SetConsoleTextAttribute(colorHandle, 2);
                cout << "\n  New Cash Is: " << person[i].cash <<" $" << endl << endl;
                system("pause");
                system("cls");
                break;
            }
        }
        else if (i == total - 1)
        {
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "  Search Result No Found\n" << endl;
            PlaySound(TEXT("Your_id_is_incorrect.wav"), NULL, SND_SYNC);
            system("cls");
        }

    }
}

void Bank::search_Balence()
{
    SetConsoleTextAttribute(colorHandle, 7);
    cout << "\n  Enter Your ID: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> id;
    SetConsoleTextAttribute(colorHandle, 7);
    system("cls");

    cout << "___________________" << endl;
    cout << "  Balance Enquiry" << endl;
    cout << "-------------------" << endl;
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            PlaySound(TEXT("Your_id_is_correct_now_you_can_see_your_balance.wav"), NULL, SND_SYNC);
            cout << "  Name: " << person[i].firstname<<" "<<person[i].lastname << endl;
            cout << "  ID: " << person[i].ID << endl;
            cout << "  Address: " << person[i].address << endl;
            cout << "  Contact: " << person[i].contact << endl;
            SetConsoleTextAttribute(colorHandle, 2);
            cout << "  Cash: " << person[i].cash <<" $\n" << endl;
            SetConsoleTextAttribute(colorHandle, 7);
            system("pause");
            system("cls");
            break;
        }
        if (i == total - 1)
        {
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "  Search Result No Found.\n\n" << endl;
            PlaySound(TEXT("Your_id_is_incorrect.wav"), NULL, SND_SYNC);
            system("cls");
        }
    }
}
void Bank::data_list()
{
    SetConsoleTextAttribute(colorHandle, 7);
    cout << "____________________________" << endl;
    cout << "  All Account Holder List" << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < total; i++)
    {
        SetConsoleTextAttribute(colorHandle, 6);
        cout <<"  " << i + 1 << ": " << person[i].firstname << " " << person[i].lastname << "\n" << endl;
    }

}

void Bank::close_Account()
{
    go_back();

    SetConsoleTextAttribute(colorHandle, 7);
    cout << "\n  Enter Your ID: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> id;
    SetConsoleTextAttribute(colorHandle, 7);
    system("cls");

    cout << "_________________" << endl;
    cout << "  Close Account" << endl;
    cout << "-----------------" << endl;

    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            for (int j = i; j < total; j++)
            {
                person[j].firstname = person[j + 1].firstname;
                person[j].lastname = person[j + 1].lastname;
                person[j].ID = person[j + 1].ID;
                person[j].address = person[j + 1].address;
                person[j].contact = person[j + 1].contact;
                person[j].cash = person[j + 1].cash;
                total--;

                SetConsoleTextAttribute(colorHandle, 4);
                cout << "\n  Your Requested Data Deleted\n\n" << endl;
                PlaySound(TEXT("data_deleted.wav"), NULL, SND_SYNC);
                system("cls");
                PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
                break;

            }
        }
        //if (i == total)
        else
        {
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "  Search Result No Found.\n" << endl;
            PlaySound(TEXT("Your_id_is_incorrect.wav"), NULL, SND_SYNC);
            system("cls");
        }

    }
}

void Bank::Change()
{
    go_back();

    SetConsoleTextAttribute(colorHandle, 7);
    cout << "\n  Enter Your ID: ";
    SetConsoleTextAttribute(colorHandle, 6);
    cin >> id;
    SetConsoleTextAttribute(colorHandle, 7);
    system("cls");
    cout << "____________________" << endl;
    cout << "  Modify Your Data" << endl;
    cout << "--------------------" << endl;

    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            SetConsoleTextAttribute(colorHandle, 6);
            cout << "\n  Previous Information" << endl;
            cout << "--------------------------" << endl << endl;
            SetConsoleTextAttribute(colorHandle, 7);
            cout << "  Data of person " << i + 1 << endl;
            cout << "  Name: " << person[i].firstname<<" "<<person[i].lastname << endl;
            cout << "  ID: " << person[i].ID << endl;
            cout << "  Address: " << person[i].address << endl;
            cout << "  Contact: " << person[i].contact << endl;
            cout << "  Cash: " << person[i].cash <<" $" << endl << endl;

            SetConsoleTextAttribute(colorHandle, 6);
            cout << "\n  Enter new information" << endl;
            cout << "----------------------------" << endl << endl;

            SetConsoleTextAttribute(colorHandle, 7);
            cout << "  Enter Your first Name: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin >> person[i].firstname;
            SetConsoleTextAttribute(colorHandle, 7);
            cout << "  Enter Your last Name: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin >> person[i].lastname;
            SetConsoleTextAttribute(colorHandle, 7);
            cout << "  ID: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin >> person[i].ID;
            SetConsoleTextAttribute(colorHandle, 7);
            cout << "  Address: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin.ignore();
            getline(cin, person[i].address);
            SetConsoleTextAttribute(colorHandle, 7);
            cout << "  Contact: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin >> person[i].contact;
            SetConsoleTextAttribute(colorHandle, 7);
            cout << "  Total Cash: ";
            SetConsoleTextAttribute(colorHandle, 6);
            cin >> person[i].cash;
            system("cls");
            SetConsoleTextAttribute(colorHandle, 2);
            cout << "\n\n  Your data modification is successful!\n\n";
            PlaySound(TEXT("Modification_successful.wav"), NULL, SND_SYNC);
            SetConsoleTextAttribute(colorHandle, 5);
            system("cls");
            PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
            break;
        }
        if (i == total - 1)
        {
            SetConsoleTextAttribute(colorHandle, 4);
            cout << "  Search Result No Found.\n\n" << endl;
            PlaySound(TEXT("Your_id_is_incorrect.wav"), NULL, SND_SYNC);
            system("cls");
        }
    }

}

void Bank::go_back()
{
    char exitkey;
    SetConsoleTextAttribute(colorHandle, 23);
    cout << "= = = = = = = = = = = = = = = = = ==\n";
    cout << "= Go back to press 'B'.            =\n";
    cout << "= If you want to exit? press 'D'.  =\n";
    cout << "= press any other key to Continue! =\n";
    cout << "= = = = = = = = = = = = = = = = = ==\n";
    SetConsoleTextAttribute(colorHandle, 3);
   
    exitkey = _getch();
    system("cls");
    if (exitkey == 'B' || exitkey == 'b')
    {
        system("cls");
        PlaySound(TEXT("welcome_back_main_menu.wav"), NULL, SND_SYNC);
        choice();
    }
    else if (exitkey == 'D' || exitkey == 'd') {
        system("cls");
        PlaySound(TEXT("ok_good_bye.wav"), NULL, SND_SYNC);
        exit(0);
    }
}