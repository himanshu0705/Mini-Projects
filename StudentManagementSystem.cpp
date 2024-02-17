#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
	private:
		struct node
		{
			string name;
            string cls;
            string div;
            int attendance;
            int roll;
			node*next;
		}*start;
	public:
		Student()
		{
			start=NULL;
		}
        void swap(int &x, int &y)
        {
            int temp;
            temp=x;
            x=y;
            y=temp;
        }
		void create();
		void display();
		void insert();
		void del_begin();
		void del_end();
		void del_pos();
		void search();
		void sort();
};

void Student::create()
{
	node *temp, *curr;
	int ans;
	do
	{
		temp=new node;
		temp->next=NULL;
		cout<<"Enter Name : ";
		cin.ignore();
		getline(cin, temp->name);
        cout<<"Enter Roll No : ";
        cin>>temp->roll;
        cout<<"Enter Class : ";
        cin>>temp->cls;
        cout<<"Enter Division : ";
        cin>>temp->div;
        cout<<"Enter Attendance : ";
        cin>>temp->attendance;
		if(start==NULL)
		{
			start=temp;
			curr=temp;
		}
		else
		{
			curr->next=temp;
			curr=curr->next;
		}
		cout<<"To add more press 1"<<endl;
		cin>>ans;
	}
	while(ans==1);
}

void Student::display()
{
	node *t;
	t=start;
    cout<<left<<setw(15)<<"Roll No"<<left<<setw(30)<<"Name"<<left<<setw(20)<<"Class"<<left<<setw(20)<<"Division"<<left<<setw(20)<<"Attendance"<<endl;
	while(t!=NULL)
	{
		cout<<left<<setw(15)<<t->roll<<left<<setw(30)<<t->name<<left<<setw(20)<<t->cls<<left<<setw(20)<<t->div<<left<<setw(20)<<t->attendance<<endl;
		t=t->next;
	}
}

void Student::insert()
{
	node*temp;
	temp=new node;
	temp->next=NULL;
	cout<<"Enter Name : ";
	cin>>temp->name;
    cout<<"Enter Roll No : ";
    cin>>temp->roll;
    cout<<"Enter Class : ";
    cin>>temp->cls;
    cout<<"Enter Division : ";
    cin>>temp->div;
    cout<<"Enter Attendance : ";
    cin>>temp->attendance;
	node*t=start;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=temp;
}

void Student::del_begin()
{
	node*t=start;
	start=start->next;
	cout<<t->name<<"'s data has been deleted"<<endl;
	delete t;
}

void Student::del_end()
{
	node*t=start;
	node*back=start;
	while(t->next!=NULL)
	{
		back=t;
		t=t->next;
	}
	cout<<t->name<<"'s data has been deleted"<<endl;
	delete t;
	back->next=NULL;
}

void Student::del_pos()
{
	int pos;
	cout<<"Enter the position of member to be deleted : ";
	cin>>pos;
	node*t=start;
	node*back=start;
	for(int i=1; i<=pos-1; i++)
	{
		back=t;
		t=t->next;
	}
	back->next=t->next;
	cout<<t->name<<"'s data has been deleted"<<endl;
	delete t;
}

void Student::search()
{
	int key;
	int flag=0;
	node*t=start;
	cout<<"Enter the Roll No. to be Searched : ";
	cin>>key;
	while(t!=NULL)
	{
		if(t->roll==key)
		{
			flag=1;
			break;
		}
		t=t->next;
	}
	if (flag==1)
	{
		cout<<"Roll No : "<<t->roll<<endl;
		cout<<"Name : "<<t->name<<endl;
		cout<<"Class : "<<t->cls<<endl;
		cout<<"Division : "<<t->div<<endl;
		cout<<"Attendance : "<<t->attendance<<endl;
	}
	else
	{
		cout<<"Key is Absent"<<endl;
	}
}

void Student::sort()
{
	node*curr=start;
	node*t;
	int temp;
	while(curr!=NULL)
	{
		t=curr->next;
		while(t!=NULL)
		{
			if((curr->roll)>(t->roll))
			{
                swap(curr->roll, t->roll);
                curr->name.swap(t->name);
                curr->cls.swap(t->cls);
                curr->div.swap(t->div);
                swap(curr->attendance, t->attendance);
			}
			t=t->next;
		}
		curr=curr->next;
	}
}

int main()
{
	Student obj;
	int ch;
	do
	{
		cout<<endl;
		cout<<"********* STUDENT DATA BASE *********"<<endl;
		cout<<"1 : To Create Data"<<endl;
		cout<<"2 : To Display Data"<<endl;
		cout<<"3 : To Insert member"<<endl;
		cout<<"4 : To Delete member at beginning"<<endl;
		cout<<"5 : To Delete member at end"<<endl;
		cout<<"6 : To Delete member at desired positon"<<endl;
		cout<<"7 : To Search Data"<<endl;
		cout<<"8 : To Sort"<<endl;
		cout<<"9 : To Exit"<<endl;
		cout<<"Enter your Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				obj.create();
				break;
			}
			case 2:
			{
				obj.display();
				break; 
			}
			case 3:
			{
				obj.insert();
				break;
			}
			case 4:
			{
				obj.del_begin();
				break;
			}
			case 5:
			{
				obj.del_end();
				break;
			}
			case 6:
			{
				obj.del_pos();
				break;
			}
			case 7:
			{
				obj.search();
				break;
			}
			case 8:
			{
				obj.sort();
				break;
			}
            case 9:
                exit(0);
		}
	}
	while(true);
	return 0;
}
