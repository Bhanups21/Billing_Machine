#include<iostream>
#include<cstring>
#include"conio.h"
#include<sstream>
#include<unistd.h>
using namespace std;
class User
{
private:
	string ID="shop45";
	bool logged=false;
public:
	void login()
	{
		string shopId;
		char choice='y';
		while(choice=='y' || choice=='Y')
		{
			stringstream ss;
			cout<<endl<<"Please enter shop ID to continue : ";
			for(int i=0;i<6;i++)
			{
				char temp=getch();
				cout<<"*";
				ss<<temp;
			}
			shopId=ss.str();
			cout<<endl;
			if(shopId.compare(ID)==0)
			{
				logged=true;
				choice='n';
			}
			else
			{
				system("clear");
				cout<<"Login unsuccessful."<<endl<<endl;
				sleep(3);
				cout<<"Do you want to try again (y/n) : ";
				cin>>choice;
				if(choice!='y' && choice!='Y' && choice!='n' && choice!='N')
				{
					cout<<endl<<"Please enter a valid choice next time."<<endl;
					break;
				}
				getch();
			}
		}
	}
	bool getLogged()
	{
		return this->logged;
	}
};