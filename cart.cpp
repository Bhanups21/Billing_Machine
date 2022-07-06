#include<fstream>
using namespace std;
class cart
{
public:
	void add()
	{
		this->show();
		int id,tid,quantity;
		string name;
		float price,discount;
		bool flag=true;
		cout<<endl<<"Enter item id: ";
		cin>>tid;
		fstream file;
		file.open("cart.txt",ios::in);
		while(file>>id>>name>>price>>discount>>quantity)
		{
			if(id==tid)
			{
				system("clear");
				cout<<"Item already in the cart."<<endl;
				cout<<"Please use the update qunatity option in the menu."<<endl;
				flag=false;
				sleep(2);
				break;
			}
		}
		file.close();
		if(flag)
		{
			cout<<endl<<"Enter quantity: ";
			cin>>quantity;
			if(quantity==0)
			{
				system("clear");
				cout<<"quantity cannot be 0."<<endl;
				sleep(2);
			}
			else
			{
				fstream x;
				x.open("cart.txt",ios::app);
				fstream y;
				y.open("list.txt",ios::in);
				while(y>>id>>name>>price>>discount)
				{
					if(id==tid)
					{
						x<<id<<" "<<name<<" "<<price<<" "<<discount<<" "<<quantity<<endl;
					}
				}
				system("clear");
				cout<<"Item added to cart."<<endl;
				sleep(2);
				y.close();
				x.close();
			}
		}
	}
	void remove()
	{
		if(this->count()==0)
		{
			system("clear");
			cout<<"There is nothing to remove."<<endl;
			sleep(2);
		}
		else
		{
			this->show();
			sleep(2);
			int tid,id,quantity;
			string name;
			float price,discount;
			cout<<endl<<"Enter item id: ";
			cin>>tid;
			fstream file;
			file.open("cart.txt",ios::in);
			fstream y;
			y.open("tempCart.txt",ios::out);
			while(file>>id>>name>>price>>discount>>quantity)
			{
				if(id!=tid)
				{
					y<<id<<" "<<name<<" "<<price<<" "<<discount<<" "<<quantity<<endl;
				}
			}
			file.close();
			y.close();
			this->copy();
			system("clear");
			cout<<"Item removed from cart."<<endl;
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
			cout<<endl;
			int tid,id,quantity,tquantity;
			string name;
			float price,discount;
			bool flag;
			cout<<endl<<"Enter item id: ";
			cin>>tid;
			fstream z;
			z.open("cart.txt",ios::in);
			while(z>>id>>name>>price>>discount>>quantity)
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
				cout<<endl<<"Enter updated quantity: ";
				cin>>tquantity;
				if(tquantity==0)
				{
					system("clear");
					cout<<"quantity cannot be 0."<<endl;
					sleep(2);
				}
				else
				{
					fstream file;
					file.open("cart.txt",ios::in);
					fstream y;
					y.open("tempCart.txt",ios::out);
					while(file>>id>>name>>price>>discount>>quantity)
					{
						if(id==tid)
						{
							y<<id<<" "<<name<<" "<<price<<" "<<discount<<" "<<tquantity<<endl;
						}
						else
						{
							y<<id<<" "<<name<<" "<<price<<" "<<discount<<" "<<quantity<<endl;
						}
					}
					file.close();
					y.close();
					this->copy();
					system("clear");
					cout<<"Item updated in cart."<<endl;
					sleep(2);
				}
			}
			else
			{
				system("clear");
				cout<<"Item with id not in cart."<<endl;
				sleep(2);
			}
		}
	}
	void bill()
	{
		int id,quantity;
		string name;
		float price,discount;
		double totalAmount=0;
		cout<<"Generating Bill..."<<endl<<endl;
		sleep(2);
		this->show();
		fstream file;
		file.open("cart.txt",ios::in);
		while(file>>id>>name>>price>>discount>>quantity)
		{
			price=price*quantity;
			totalAmount+=((100-discount)/100)*price;
		}
		cout<<endl<<"Total Bill Value: "<<totalAmount<<endl;
		this->clear();
	}
	void copy()
	{
		int id,quantity;
		string name;
		float price,discount;
		fstream y;
		y.open("tempCart.txt",ios::in);
		fstream file;
		file.open("cart.txt",ios::out);
		while(y>>id>>name>>price>>discount>>quantity)
		{
			file<<id<<" "<<name<<" "<<price<<" "<<discount<<" "<<quantity<<endl;
		}
		file.close();
		y.close();
	}
	void clear()
	{
		fstream file;
		file.open("cart.txt",ios::out);
		file.close();
	}
	int count()
	{
		int id,quantity,records=0;
		string name;
		float price,discount;
		fstream file;
		file.open("cart.txt",ios::in);
		while(file>>id>>name>>price>>discount>>quantity)
		{
			records++;
		}
		file.close();
		return records;
	}
	void show()
	{
		cout<<"********  CART  ********"<<endl<<endl;
		sleep(2);
		if(this->count()==0)
		{
			cout<<"No items found."<<endl;
			sleep(2);
		}
		else
		{
			int id,quantity;
			string name;
			float price,discount;
			stringstream ss;
			fstream file;
			file.open("cart.txt",ios::in);
			ss<<"id\tName\t\t\tprice\tDiscount\tQuantity"<<endl;
			while(file>>id>>name>>price>>discount>>quantity)
			{
				ss<<id<<"\t"<<name<<"\t\t\t"<<price<<"\t"<<discount<<"\t\t"<<quantity<<endl;
			}
			file.close();
			cout<<ss.str();
		}
	}
};