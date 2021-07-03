#include<iostream>
using namespace std;
const int SIZE=10;
class DoubleHashing
{
private:
	int *arr;
	int current_size;
public:
	DoubleHashing()
	{
		arr=new int[SIZE];
		current_size=0;
		for(int i=0;i<SIZE;i++)
		{
			arr[i]=-1;
		}
	}
	bool isFull()
	{
		if(current_size==SIZE)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int Hash1(int key)
	{
		return (key%SIZE);
	}
	int Hash2(int key)
	{
		return (key%10);
	}
	void insert(int key)
	{
		if(isFull())
		{
			cout<<"Sorry! Hash Table is full."<<endl;
			cout<<"You can't insert anymore value."<<endl;
		}
		else
		{
			int index=Hash1(key);
			if(arr[index]!=-1)
			{
				int index2=Hash2(key);
				int i=1;
				while(1)
				{
					int newindex=(index + i *index2)%SIZE;
					if(arr[newindex]==-1)
					{
						arr[newindex]=key;
						break;
					}
					i++;
				}
			}
			else
			{
				arr[index]=key;
			}
		}
		current_size++;
	}
	void display()
	{
		cout<<"Contents in Hash Table are."<<endl;
		for(int i=0;i<SIZE;i++)
		{
			if(arr[i]!=-1)
			{
			cout<<i<<": "<<arr[i]<<endl;
			}
			else
			{
				cout<<i<<":"<<endl;
			}
		}
	}

};

int main()
{
	int a[]={19,27,36,10,64};
	int s=sizeof(a)/sizeof(a[0]);
	DoubleHashing h;
	for(int i=0;i<s;i++)
	{
		h.insert(a[i]);
	}
	h.display();
	system("pause");
}