#include<unistd.h>
#include<stdlib.h>
#include"list.cpp"
#include"cart.cpp"
#include"user.cpp"
using namespace std;
int main()
{
	system("clear");
	cout<<"****************"<<endl;
	cout<<"*    Welcome   *"<<endl;
	cout<<"****************"<<endl;
	sleep(2);
	User Admin;
	Admin.login();
	if(Admin.getLogged())
	{
		int choiceMainMenu;
		system("clear");
		cout<<"Login successful, please wait..."<<endl;
		sleep(2);
		do
		{
			system("clear");
			cout<<"***********************"<<endl;
			cout<<"*    Hello, Admin!!   *"<<endl;
			cout<<"***********************"<<endl<<endl;
			sleep(2);
			cout<<"1.Billing"<<endl;
			cout<<"2.Managing"<<endl;
			cout<<"3.Exit"<<endl<<endl;
			cout<<"Please enter your choice: ";
			cin>>choiceMainMenu;
			switch(choiceMainMenu)
			{
				case 1:
				cart Cart;
				list List;
				int choiceCartMenu;
				do
				{
					system("clear");
					cout<<"******** Billing *********"<<endl<<endl;
					sleep(2);
					cout<<"1.Add to cart"<<endl;
					cout<<"2.Remove from cart"<<endl;
					cout<<"3.Update quantity of certain item"<<endl;
					cout<<"4.Calculate bill"<<endl;
					cout<<"5.View cart"<<endl;
					cout<<"6.Back"<<endl<<endl;
					cout<<"Please enter your choice: ";
					cin>>choiceCartMenu;
					switch(choiceCartMenu)
					{
						case 1:
						system("clear");
						cout<<"******** Adding item to cart ********"<<endl<<endl;
						sleep(2);
						List.show();
						sleep(2);
						Cart.add();
						break;
						case 2:
						system("clear");
						cout<<"******** Removing item in cart ********"<<endl<<endl;
						sleep(2);
						Cart.remove();
						break;
						case 3:
						system("clear");
						cout<<"******** updating item quantity in cart ********"<<endl<<endl;
						sleep(2);
						Cart.update();
						sleep(2);
						break;
						case 4:
						system("clear");
						Cart.bill();
						cout<<endl<<"Please press enter to continue.";
						getch();
						getch();
						break;
						case 5:
						system("clear");
						Cart.show();
						sleep(2);
						cout<<endl<<"Please press enter to continue.";
						getch();
						getch();						
						break;
						case 6:
						system("clear");
						break;
						default:
						system("clear");
						cout<<"Please enter a Valid Option."<<endl;
						sleep(2);
					}
				}while(choiceCartMenu!=6);
				break;
				case 2:
				int choiceListMenu;
				do
				{
					system("clear");
					cout<<"******** Managing *********"<<endl<<endl;
					sleep(2);
					cout<<"1.Add item to List"<<endl;
					cout<<"2.Remove item from List"<<endl;
					cout<<"3.Update items in List"<<endl;
					cout<<"4.View items in List"<<endl;
					cout<<"5.Back"<<endl<<endl;
					cout<<"Please enter your choice: ";
					cin>>choiceListMenu;
					switch(choiceListMenu)
					{
						case 1:
						system("clear");
						cout<<"********* Adding item into list ********"<<endl<<endl;
						sleep(2);
						List.add();
						break;
						case 2:
						system("clear");
						cout<<"******** Removing item in cart ********"<<endl<<endl;
						sleep(2);
						List.remove();
						break;
						case 3:
						system("clear");
						cout<<"******** updating item in cart ********"<<endl<<endl;
						sleep(2);
						List.update();
						break;
						case 4:
						system("clear");
						List.show();
						sleep(2);
						cout<<endl<<"Please press enter to continue.";
						getch();
						getch();
						break;
						case 5:
						system("clear");
						break;
						default:
						system("clear");
						cout<<"Please enter a Valid Option."<<endl;
						sleep(2);
					}
				}while(choiceListMenu!=5);
				break;
				case 3:
				system("clear");
				cout<<"Bye.......!!!"<<endl;
				sleep(2);
				exit(0);
				break;
				default:
				system("clear");
				cout<<"Please enter a Valid Option."<<endl;
				sleep(2);
			}
		}while(choiceMainMenu!=3);
	}
	else
	{
		system("clear");
		cout<<"Bye........!!!"<<endl;
		sleep(2);
	}
	return 0;
}