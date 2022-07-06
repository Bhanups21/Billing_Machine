#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;
class list
{
public:
	void add()
	{
		show();
		sleep(2);
		int id,tid;
		string name,tname;
		float price,tprice,discount,tdiscount;
		bool idFlag=true;
		cout<<endl<<"Enter item id: ";
		cin>>id;
		fstream file;
		file.open("list.txt",ios::in);
		while(file>>tid>>tname>>tprice>>tdiscount)
		{
			if(id==tid)
			{
				system("clear");
				cout<<"Id already present."<<endl;
				sleep(2);
				idFlag=false;
			}
		}
		file.close();
		if(idFlag)
		{
			cout<<endl<<"Enter item name: ";
			cin>>name;
			cout<<endl<<"Enter item price: ";
			cin>>price;
			cout<<endl<<"Enter item discount: ";
			cin>>discount;
			fstream file;
			file.open("list.txt",ios::app);
			file<<id<<" "<<name<<" "<<price<<" "<<discount<<endl;
			file.close();
			system("clear");
			cout<<"Item added successfully."<<endl;
			sleep(2);
		}
	}
	void remove()
	{
		if(count()==0)
		{
			system("clear");
			cout<<"There is nothing to remove."<<endl;
			sleep(2);
		}
		else
		{
			this->show();
			sleep(2);
			int tid,id;
			string name;
			float price,discount;
			cout<<"Enter item id: ";
			cin>>tid;
			fstream file;
			file.open("list.txt",ios::in);
			fstream y;
			y.open("tempList.txt",ios::out);
			while(file>>id>>name>>price>>discount)
			{
				if(id!=tid)
				{
					y<<id<<" "<<name<<" "<<price<<" "<<discount<<endl;
				}
			}
			file.close();
			y.close();
			copy();
			system("clear");
			cout<<"Item removed successfully."<<endl;
			sleep(2);
		}
	}
	void update()
	{
		if(this->count()==0)
		{
			system("clear");
			cout<<"There is nothing to update."<<endl;
			sleep(2);
		}
		else
		{
			this->show();
			sleep(2);
			int tid,id,nid;
			string name,nname;
			float price,nprice,discount,ndiscount;
			bool flag;
			cout<<"Enter item id:";
			cin>>tid;
			fstream z;
			z.open("list.txt",ios::in);
			while(z>>id>>name>>price>>discount)
			{
				if(id==tid)
				{
					flag=true;
					break;
				}
			}
			z.close();
			if(flag)
			{
				cout<<endl<<"Enter new item id: ";
				cin>>nid;
				cout<<endl<<"Enter new item name: ";
				cin>>nname;
				cout<<endl<<"Enter new item price: ";
				cin>>nprice;
				cout<<endl<<"Enter new item discount: ";
				cin>>ndiscount;
				fstream file;
				file.open("list.txt",ios::in);
				fstream y;
				y.open("tempList.txt",ios::out);
				while(file>>id>>name>>price>>discount)
				{
					if(id==tid)
					{
						y<<nid<<" "<<nname<<" "<<nprice<<" "<<ndiscount<<endl;
					}
					else
					{
						y<<id<<" "<<name<<" "<<price<<" "<<discount<<endl;
					}
				}
				file.close();
				y.close();
				copy();
				system("clear");
				cout<<"Item updated successfully."<<endl;
				sleep(2);
			}
			else
			{
				system("clear");
				cout<<"Item with id not in list."<<endl;
				sleep(2);
			}
		}
	}
	void copy()
	{
		int id;
		string name;
		float price,discount;
		char ch;
		fstream y;
		y.open("tempList.txt",ios::in);
		fstream file;
		file.open("list.txt",ios::out);
		while(y>>id>>name>>price>>discount)
		{
			file<<id<<" "<<name<<" "<<price<<" "<<discount<<endl;
		}
		file.close();
		y.close();
	}
	int count()
	{
		int id,quantity,records=0;
		string name;
		float price,discount;
		fstream file;
		file.open("list.txt",ios::in);
		while(file>>id>>name>>price>>discount)
		{
			records++;
		}
		file.close();
		return records;
	}
	void show()
	{
		cout<<"********** LIST **********"<<endl<<endl;
		sleep(2);
		if(count()==0)
		{
			cout<<"No items found."<<endl<<endl;
			sleep(2);
		}
		else
		{
			int id;
			string name;
			float price,discount;
			stringstream ss;
			fstream file;
			file.open("list.txt",ios::in);
			ss<<"id\tName\t\t\tprice\tDiscount"<<endl;
			while(file>>id>>name>>price>>discount)
			{
				ss<<id<<"\t"<<name<<"\t\t\t"<<price<<"\t"<<discount<<endl;
			}
			file.close();
			cout<<ss.str()<<endl;
		}
	}
};