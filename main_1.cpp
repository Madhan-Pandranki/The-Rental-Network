#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;
//void verify();
//int menu();
//void login();
// void createaccount();
// void searchDetails();
void gotoxy(int, int);
FILE *fp;
// void addTenantsInfo(user, user);
int choice;
char fname[20], lname[20], uname[20], pss[20], C;
class start
{
    public:
    start() //constructor
    {
    }
    ~ start()   //destructor
    {
    }
    inline int menu() //inline function
    {
        int ch;
        cout << "1. Signup:  \n";
        cout << "2. Login:  \n";
        cout << "3. Exit:  \n";
        // cout<<"4. :  \n";
        cout << "Enter your choice :  ";
        cin >> ch;
        return ch;
    }
    void login();
};
class house: public start
{
public:
    char name[50];
    char ldaApp[2];
    char parkingLot[2];
    char locality[50];
    int bhk;
    int price;
    char pss[20];
};
class user: public start
{
public:
    char pass[20];
    char username[20];
    char fname[20];
    char lname[20];
    char phnum[20];
    char emailid[100];
    int age;
    char position[1];
    void createaccount();
    void addDetails(char *ptr); // function overloading
    void addDetails(user tenant, user owner);
};
class tenantInfo : public user // inheritance
{
public:
    char opass[50];
    char ousername[50];
    char tenantname[50];
    char tenantpass[50];
    char occ[20];
    int members;
    int duration;
    char isMarried[20];
    tenantInfo()    //constructor
    {
    }
    ~tenantInfo()   //destructor
    {
    }
    friend void searchDetails(user U); // friend function
    void tenantRequests(user u);
};
int main()
{
    user s;
    start st;
    while (1)
    {
        switch (st.menu())
        {
        case 1:
            s.createaccount();
            break;

        case 2:
            st.login();
            break;

        case 3:
            exit(0);
        default:
            cout << "Invalid Choice ! ";
            exit(0);
            // break;
        }
    }

    return 0;
}
void takePassword(char pwd[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13 || ch == 9)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                cout << "\b \b";
            }
        }
        else
        {
            pwd[i++] = ch;
            cout << "*";
        }
    }
    // cout<<"%s", pwd);
}
/*int menu()
{
    int ch;
    cout << "1. Signup:  \n";
    cout << "2. Login:  \n";
    cout << "3. Exit:  \n";
    // cout<<"4. :  \n";
    cout << "Enter your choice :  ";
    cin >> ch;
    return ch;
}*/
void user ::createaccount()
{
    FILE *fp, *fp2;
    int z, j;
    system("cls");
    gotoxy(45, 3);
    // gotoxy(53, 3);
    char name[50] = "CREATE ACCOUNT";
    z = strlen(name);
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        cout << "\xDB";
    }
    for (j = 0; j <= z; j++)
    {
        Sleep(60);
        cout << name[j];
    }
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        cout << "\xDB";
    }
    cout << "\n\n";
    cout << "    Enter First Name: ";
    fflush(stdin);
    cin >> fname;
    cout << "\n";
    cout << "    Enter Last Name: ";
    cin >> lname;
    cout << "\n";
    cout << "    Enter Age - ";
    cin >> age;
    if (!(age > 0 && age < 200))
    {
        cout << "\n";
        cout << "Enter a valid age";
        cout << "\n";
        Sleep(1000);
        createaccount();
    }
    cout << "\n";
    cout << "    Enter Username : (remember/ without spaces) ";
    // char temp;
    // cin>>temp;
    cin >> username;
    cout << "\n";

    cout << "    Enter Password: (remember) ";
    takePassword(pass);
    cout << "\n\n";
    cout << "    Enter emailID - ";
    cin >> emailid;
    int flag = 0;
    int k = strlen(emailid);
    for (int i = 0; i < k; i++)
    {
        if (emailid[i] == '@' || emailid[i] == '.')
        {
            flag++;
        }
    }
    if (flag < 2)
    {
        cout << "\nPlease enter a valid email id. \n";
        Sleep(1000);
        createaccount();
    }

    cout << "\n";
    cout << "    Enter Phone Num - ";
    cin >> phnum;
    cout << "\n";
    cout << "    Are you an Owner(o) or a Tenant(t) - ";
    cin >> position;
    cout << "\n";
    if (position[0] == 'o')
    {
        fp2 = fopen("owner.txt", "ab+");
        if (fp2 == NULL)
        {
            cout << "\nError opened file\n";
            exit(1);
        }
        fwrite(this, sizeof(user), 1, fp2);
        fclose(fp2);
    }
    else if (position[0] == 't')
    {
        fp2 = fopen("tenant.txt", "ab+");
        if (fp2 == NULL)
        {
            cout << "\nError opened file\n";
            exit(1);
        }
        fwrite(this, sizeof(user), 1, fp2);
        fclose(fp2);
    }
    fp = fopen("login.txt", "ab+");
    if (fp == NULL)
    {
        cout << "\nError opened file\n";
        exit(0);
    }
    fwrite(this, sizeof(user), 1, fp);
    fclose(fp);
    system("cls");
    gotoxy(55, 20);
    cout << " Account Created Successfully.";
    gotoxy(75, 25);
    cout << "Press any key to continue...";
    getch();

    system("cls");
    main();
}
void writePassword(char pss[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13 || ch == 9)
        {
            pss[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                cout << "\b \b";
            }
        }
        else
        {
            pss[i++] = ch;
            cout << "*";
        }
    }
}
void addDetails(char *ptr)
{
    start s;
    system("cls");
    gotoxy(31, 4);
    cout << "\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3";
    FILE *fptr;
    char nameofapp[100];
    char locality[100];
    int price;
    int bhk;
    char ldaApp[100];
    char parking[100];
    fptr = fopen("houses.txt", "ab+"); // ab+ gives us the ability of writing the function and add the second data in the existing one...
    if (fptr == NULL)
    {
        cout << "Failed to create the required file.";
    }
    else
    {
        house H;
        char temp;
        gotoxy(31, 6);
        cout << "Name of the Apartment:\t";
        // gotoxy(52,6);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.name);
        // cin.getline(H.name, 50);
        // fgets(nameofapp, 200, stdin);
        gotoxy(31, 7);
        cout << "Locality:\t";
        // gotoxy(52,7);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.locality);
        // fgets(locality, 200, stdin);
        // cin>>"%[^\n]", locality);
        gotoxy(31, 8);
        cout << "BHK:\t";
        // gotoxy(52,9);
        // cin >> temp; // temp statement to clear buffer
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%d", &H.bhk);
        // fgets(locality, 200, stdin);
        gotoxy(31, 9);
        printf("Is it LDA Approved(y/n):\t");
        // gotoxy(57,10);
        // scanf("%c", &temp); //temp statement to clear buffer
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.ldaApp);
        gotoxy(31, 10);
        printf("Does it have any parking area (y/n):\t");
        // gotoxy(70,11);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.parkingLot);
        gotoxy(31, 11);
        printf("Price:\t");
        // gotoxy(52,8);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%d", &H.price);
        // char *ptr = pss;
        strcpy(H.pss, ptr);
        // Sleep(3000);
        // strcpy(H.pss, *ptr);
        // cout<<"%s", H.pss);
        // Sleep(5000);

        fwrite(&H, sizeof(house), 1, fptr);
        fclose(fptr);
    }
    fclose(fptr);
    system("cls");
    char string[200] = "House details added successfully. Tenants will reach to you shortly.";
    int z = strlen(string);
    for (int i = 0; i <= z; i++)
    {
        Sleep(60);
        cout << string[i];
    }
    Sleep(1000);
    s.login();
}
void tenantInfo ::tenantRequests(user u)
{
    // cout<<"%d", u.age);
    // Sleep(5000);
    start st;
    system("cls");
    tenantInfo ti;

    FILE *fp1, *fp2;
    fp1 = fopen("tenants-info.txt", "r");

    int flag = 0;
    if (fp1 == NULL)
    {
        cout << "\"File not found\"";
        return;
    }
    while (fread(&ti, sizeof(tenantInfo), 1, fp1))
    {
        if (strcmp(u.pass, ti.opass) == 0 && strcmp(u.username, ti.ousername) == 0)
        {
            fp2 = fopen("tenant.txt", "r");
            while (fread(&ti, sizeof(user), 1, fp2))
            {
                if (strcmp(ti.pass, ti.tenantpass) == 0 && strcmp(ti.username, ti.tenantname) == 0)
                {
                    cout << "\n";
                    // gotoxy(28, 5);
                    cout << "----------------------------------------";
                    cout << "\n";
                    cout.setf(ios::left,ios::adjustfield);      //io console
                    // gotoxy(31, 6.5);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Name of the Tenant" <<": "<< ti.fname << " " << ti.lname;
                    cout << "\n";
                    // gotoxy(31, 7);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Age" <<": "<< ti.age;
                    cout << "\n";
                    // gotoxy(31, 8);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Occupation" <<": "<< ti.occ;
                    cout << "\n";
                    // gotoxy(31, 9);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Married ? (y/n)" <<": "<< ti.isMarried;
                    cout << "\n";
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Members in the family" <<": "<< ti.members;
                    cout << "\n";
                    // gotoxy(31, 10);
                    // gotoxy(31, 11);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Duration for which he/she wants your house ?" <<": "<< ti.duration;
                    cout << "\n\n";
                    cout << "CONTACT DETAILS\n";
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Phone Number" <<": "<< ti.phnum;
                    cout << "\n";
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Email-ID" <<": "<< ti.emailid;
                    cout << "\n";

                    // gotoxy(28, 5);
                    cout << "----------------------------------------";
                    cout << "\n";
                    flag++;
                }
            }
            fclose(fp2);
        }
    }
    fclose(fp1);
    if (flag == 0)
    {
        system("cls");
        gotoxy(39, 4);

        char string[200] = "No requests found :(";
        int z = strlen(string);
        for (int i = 0; i <= z; i++)
        {
            Sleep(60);
            cout << string[i];
        }
        Sleep(2000);
        st.login();
    }
    getch();
    st.login();
}
void addDetails(user tenant, user owner)
{
    FILE *fptr;
    char temp;
    tenantInfo tp;
    cout << "\nOWNER WANTS TO KNOW \n";
    // cin>>temp;
    cout << "Your Occupation:: ";
    cin >> tp.occ;
    cout << "\n";
    cout << "Are you married ? (y/n) ";
    cin >> tp.isMarried;
    cout << "\n";
    cout << "How many members will be there ? ";
    cin >> tp.members;
    cout << "\n";
    cout << "For how many months you want this place to live ? ";
    cin >> tp.duration;
    cout << "\n";
    strcpy(tp.opass, owner.pass);
    strcpy(tp.tenantpass, tenant.pass);
    strcpy(tp.tenantname, tenant.username);
    strcpy(tp.ousername, owner.username);

    fptr = fopen("tenants-info.txt", "ab+");
    if (fptr == NULL)
    {
        cout << "Failed to create the required file.";
    }
    else
    {
        fwrite(&tp, sizeof(tenantInfo), 1, fptr);
        // fclose(fptr);
    }
    fclose(fptr);
    system("cls");
    char string[200] = "Your details added successfully. Owner will reach to you shortly.";
    int z = strlen(string);
    for (int i = 0; i <= z; i++)
    {
        Sleep(60);
        cout << string[i];
    }
    Sleep(1000);
    cout << "\n";
    system("cls");
    main();
}
void searchDetails(user U)
{
    
    house h;
    user u;
    FILE *fptr, *fp;
    int flag = 0;
    int res;
    char pss[20];
    char nameofapp[100];
    char locality[100];
    int price;
    char ldaApp[100];
    char parking[100];
    int bhk;
    int bhk1;
    int ul;
    int ll;
    char name1[100];
    system("cls");
    fflush(stdin);
    // gotoxy(18, 2);
    cout << "\xDB\xDB\xDB Search city, locality, project/ society, landmarks:: ";
    scanf("%[^\n]", name1);
    // cout<<name1;
    cout << "\n";
    cout << "\xDB\xDB\xDB Price lower limit:: ";
    cin >> ll;
    cout << "\n";
    // cout<<ll;
    cout << "\xDB\xDB\xDB Price upper limit:: ";
    cin >> ul;
    cout << "\n";
    // cout<<ul;
    cout << "\xDB\xDB\xDB How many number of bedrooms you want(BHK):: ";
    cin >> bhk1;
    cout << "\n";
    // cout<<"%d", bhk1);
    fptr = fopen("houses.txt", "r");
    // fflush(stdin);
    int i = 0;
    while (fread(&h, sizeof(house), 1, fptr))
    {
        // cout<<"%s", locality);
        // Sleep(5000);
        res = strcmp(h.locality, name1);

        if (res == 0 && h.price <= ul && h.price >= ll && bhk1 == h.bhk)
        {
            // gotoxy(39, 4);
            if (i == 0)
            {
                cout << "\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record(s) Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3";
                i++;
            }

            cout << "\n";
            // gotoxy(28, 5);
            cout << "----------------------------------------";
            cout << "\n";
            cout.setf(ios::left,ios::adjustfield);              //io console
            // gotoxy(31, 6.5);
            cout << setw(30) <<"\xB3\xB2\xB2\xB2 Name of the Apartment" <<": " <<h.name;
            cout << "\n";
            // gotoxy(31, 7); 
            cout << setw(30) <<"\xB3\xB2\xB2\xB2 Locality" <<": "<< h.locality;
            cout << "\n";
            // gotoxy(31, 8);
            cout << setw(30) <<"\xB3\xB2\xB2\xB2 Price" <<": "<< h.price;
            cout << "\n";
            // gotoxy(31, 9);
            cout << setw(30) <<"\xB3\xB2\xB2\xB2 BHK" <<": "<< h.bhk;
            cout << "\n";
            // gotoxy(31, 10);
            cout << setw(30) <<"\xB3\xB2\xB2\xB2 LDA Approved (y/n) " <<": "<< h.ldaApp;
            cout << "\n";
            // gotoxy(31, 11);
            cout << setw(30) <<"\xB3\xB2\xB2\xB2 Parking Lot ? " <<": "<< h.parkingLot;
            cout << "\n\n";

            // gotoxy(31,14);
            cout << "OWNER  DETAILS";
            cout << "\n";
            // gotoxy(31,15);
            fp = fopen("owner.txt", "r");
            while (fread(&u, sizeof(user), 1, fp))
            {
                if (strcmp(h.pss, u.pass) == 0)
                {
                    // gotoxy(31,17);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Name of the Owner" <<": "<< u.fname << " " << u.lname;
                    cout << "\n";
                    // gotoxy(31,18);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Phone Number"<<": " << u.phnum;
                    cout << "\n";
                    // gotoxy(31,19);
                    cout << setw(30) <<"\xB3\xB2\xB2\xB2 Email-id"<<": " << u.emailid;
                    cout << "\n\n";
                    cout << "----------------------------------------";
                }
            }
            flag = 1;

            // gotoxy(31,21);

            // flag = 1;
            // Sleep(1000);
            fclose(fp);
            cout << "\n";
            // // gotoxy(18, 12);
            // cout<<"Enter any key for menu option.");
            // while (getch())
            // {
            // 	menu();
            // }
        }
    }
    if (flag == 0)
    {
        system("cls");
        gotoxy(39, 4);

        char string[200] = "No record found :(";
        int z = strlen(string);
        for (int i = 0; i <= z; i++)
        {
            Sleep(60);
            cout << " " << string[i];
        }
        Sleep(1000);
        h.login();
    }

    fclose(fptr);
    char firstname[50], lastname[50];
    cout << "\n Enter the name of the owner whom you want to connect with or press y to go to main menu : ";
    if (getch() == 'y')
    {
        cout << "\n";
        main();
    }
    cin >> firstname >> lastname;

    fp = fopen("owner.txt", "r");
    while (fread(&u, sizeof(user), 1, fp))
    {
        if ((strcmp(firstname, u.fname) == 0) && (strcmp(lastname, u.lname) == 0))
        {
            addDetails(U, u);
        }
    }
}

void start :: login()
{
    char uname[20], pss[20];
    int z, j;
    FILE *fp1;
    user u;
    tenantInfo tI;
    system("cls");
    gotoxy(35, 3);
    char name[50] = "LOGIN TO YOUR ACCOUNT";
    z = strlen(name);
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        cout << "\xDB";
    }
    for (j = 0; j <= z; j++)
    {
        Sleep(60);
        cout << name[j];
    }
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        cout << "\xDB";
    }
    gotoxy(35, 5);
    cout << " Enter Username: ";
    cin >> uname;
    gotoxy(35, 7);
    cout << " Enter Password: ";
    writePassword(pss);
    /// Reading from file
    fp1 = fopen("login.txt", "r");
    if (fp1 == NULL)
    {
        cout << "\"File not found\"";
        return;
    }
    int flag = 0;
    // char *ptr = str;
    while (fread(&u, sizeof(user), 1, fp1))
    {
        if (strcmp(uname, u.username) == 0 && strcmp(pss, u.pass) == 0)
        {
            flag++;
            cout << " \n Username And Password is Correct.\n";
            cout << " Press any key to continue...";
            getch();
            gotoxy(45, 12);

            if (u.position[0] == 'o')
            {
                cout << "\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME " << u.fname << " " << u.lname << ". YOU ARE LOGGED IN AS OWNER \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3";
            }
            else if (u.position[0] == 't')
            {
                cout << "\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME " << u.fname << " " << u.lname << ". YOU ARE LOGGED IN AS TENANT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3";
            }
            else
            {
                cout << "Invalid choice\n";
                exit(0);
            }

            // cout<<" Welcome %s %s. ", u.fname, u.lname;
            // cout<<"You are logged in as %s", ptr;
            getch();
            cout << "\n";
            gotoxy(45, 15);
            if (u.position[0] == 't')
            {
                int k;
                cout << "1. Search for home:  \n";
                gotoxy(45, 18);
                cout << "2. Exit:  \n";
                cout << "\n";
                // cout<<"4. :  \n";
                gotoxy(45, 21);
                cout << "Enter your choice :  ";
                cin >> k;
                switch (k)
                {
                case 2:
                    exit(0);
                    break;
                case 1:
                    searchDetails(u);
                    break;
                default:
                    cout << "Invalid choice !";
                    Sleep(1);
                    login();
                    
                    break;
                }
            }
            else
            {
                int k;
                cout << "1. Add home details:  \n";
                gotoxy(45, 17);
                cout << "2. Tenant Requests:  \n";
                gotoxy(45, 19);
                cout << "3. Exit:  \n";
                cout << "\n";
                // cout<<"4. :  \n";
                gotoxy(45, 21);
                cout << "Enter your choice :  ";
                cin >> k;
                switch (k)
                {
                case 1:
                    addDetails(u.pass);
                    break;
                case 2:
                    tI.tenantRequests(u);
                case 3:
                    exit(0);

                default:
                    cout << "Invalid choice";
                    Sleep(1);
                    login();
                }
            }
            break;
        }
    }

    int choice;

    if (flag == 0)
    {
        cout << "\n Username And Password is Incorrect.\n\n";
        cout << " Press any key to continue...";
        getch();
    }
    fclose(fp1);
    system("cls");
    login();
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}