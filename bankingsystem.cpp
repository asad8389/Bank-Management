#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

class bank{
    int acc;
    char fname[50];
    char lname[50];
    int bal;
public:
    void read_data();
    void show_data();
    void read_file();
    void write_file();
    void search_file();
    void update();
    };

    void bank::read_data()
    {
        cout<<endl;
        cout<<"Enter Account number: ";
        cin>>acc;
        cout<<"Enter First name: ";
        cin>>fname;
        cout<<"Enter Last name: ";
        cin>>lname;
        cout<<"Enter Balance: ";
        cin>>bal;
        cout<<endl;
    }


    void bank::show_data()
    {
        cout<<"*************************************************************************************"<<endl;
        cout<<"Account no : "<<acc<<endl;
        cout<<"First name : "<<fname<<endl;
        cout<<"Last name  : "<<lname<<endl;
        cout<<"Balance    : "<<bal<<endl;
        cout<<"*************************************************************************************"<<endl;

    }

    void bank::read_file()
    {
        int n,i;
        fstream file("bank", ios::in | ios::binary);
        if(!file){cout<<"Failed to open the file"<<endl;}

        file.seekg(0,ios::end);
        n=file.tellg()/sizeof(*this);
        for(i=1;i<=n;i++)
        {
            file.seekg((i-1)*sizeof(*this),ios::beg);
            file.read(reinterpret_cast<char*> (this), sizeof(*this));
            show_data();
            file.flush();
        }
    }

    void bank::write_file()
    {
        ofstream file("bank", ios::out | ios::binary | ios::app);
        if(!file){cout<<"Failed to open file"<<endl;}
        read_data();

        file.write(reinterpret_cast<char*> (this), sizeof(*this));
        cout<<"Successful saved the data..."<<endl;

    }

    void bank::search_file()
    {
        int len,n;
        ifstream file("bank", ios::in | ios::binary);
        if(!file){cout<<"Failed to open file"<<endl;}

        file.seekg(0, ios::end);
        len = file.tellg()/sizeof(*this);

        cout<<"Total records int the file :"<<len<<endl;
        cout<<"Enter your choice for search:";
        cin>>n;

        file.seekg((n-1)*sizeof(*this),ios::beg);
        file.read(reinterpret_cast<char*> (this), sizeof(*this));
        show_data();

    }

    void bank::update()
    {
        int len,n;
        fstream file("bank", ios::in | ios::out | ios::binary);
        if(!file){cout<<"Failed to open file"<<endl;}

        file.seekp(0,ios::end);
        len=file.tellp()/sizeof(*this);

        cout<<"Which record you want to update: ";
        cin>>n;

        file.seekp((n-1)*sizeof(*this));
        read_data();

        file.write(reinterpret_cast<char*> (this), sizeof(*this));
        cout<<"Successful updated the data..."<<endl;

    }


    int main()
    {
        bank obj;
        int x;

        for(;;)
        {
                cout<<"Welcome to the Bank management\n"<<endl;
                cout<<"1. Add new record \n2. Show all records \n3. Search record \n4. Update record \n5. Delete record \n6. Quit\n"<<endl;
                cout<<"Enter your choice: ";
                cin>>x;

                switch(x)
                {
                case 1:
                    obj.write_file();
                    break;
                case 2:
                    obj.read_file();
                    break;
                case 3:
                    obj.search_file();
                    break;
                case 4:
                    obj.update();
                    break;
                case 5:
                    break;
                case 6:
                    return 0;
                default:
                    cout<<"Wrong choice";
                }
            system("pause");
            system("cls");

        }
    }

