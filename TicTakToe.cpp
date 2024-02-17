#include <iostream>
#include <string>
using namespace std;

class tictac
{
public:
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
string n1;
string n2;
char token;
bool tie;

tictac()
{
token='X';
tie=false;

n1=" ";
n2=" ";
}

public:
void layout()
{


    cout<<"      |      |      \n";
    cout<<"   "<<space[0][0]<<"  |  "<<space[0][1]<<"   |   "<<space[0][2]<<"\n";
    cout<<"      |      |      \n";
    cout<<"--------------------\n";
    cout<<"      |      |      \n";
    cout<<"   "<<space[1][0]<<"  |  "<<space[1][1]<<"   |   "<<space[1][2]<<"\n";
    cout<<"      |      |      \n";
    cout<<"--------------------\n";
    cout<<"      |      |      \n";
    cout<<"   "<<space[2][0]<<"  |  "<<space[2][1]<<"   |   "<<space[2][2]<<"\n";
    cout<<"      |      |      \n";
    cout<<"\n\n\n";
}

void fillToken()
{
    int digit;

    if(token=='X')
    {
        cout<<"Please enter 0 for exit \n";
        cout<<n1<<"  please enter:";
        cin>>digit;
        if(digit == 0)
        {
            exit(0);
        }
    }
    
    if(token=='O')
    {
        cout<<"Please enter 0 for exit \n";
        cout<<n2<<"  please enter:";
        cin>>digit;
        if(digit == 0)
        {
            exit(0);
        }
    }

    if(digit==1)
    {
        row=0;
        column=0;
    }
    else if(digit==2)
    {
        row=0;
        column=1;
    }
    else if(digit==3)
    {
        row=0;
        column=2;
    }
    else if(digit==4)
    {
        row=1;
        column=0;
    }
    else if(digit==5)
    {
        row=1;
        column=1;
    }
    else if(digit==6)
    {
        row=1;
        column=2;
    }
    else if(digit==7)
    {
        row=2;
        column=0;
    }
    else if(digit==8)
    {
        row=2;
        column=1;
    }
    else if(digit==9)
    {
        row=2;
        column=2;
    }
    else
    {
        cout<<"WRONGE ENTRY !!!";
    }

    if(token=='X' && space[row][column]!='X' && space[row][column]!='O')
    {
        space[row][column]='X';
        token='O';
    }
    else if(token=='O' && space[row][column]!='X' && space[row][column]!='O')
    {
        space[row][column]='O';
        token='X';
    }
    else
    {
        cout<<"There is no empty space!!\n";
        fillToken();
    }
    layout();
}

bool check()
{
    int count=0;
    for(int i=0;i<3;i++)
    {
        if(((space[i][0]==space[i][1]) && (space[i][0]==space[i][2] )) || ((space[0][i]==space[1][i]) && (space[0][i]==space[2][i])))
        {
            return true;
        }
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
        {
            return true;
        }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j] != 'X' && space[i][j] !='O')
            {
                return false;
            }
            if(space[i][j]=='X' || space[i][j]=='O')
            {
                count++;
            }
        }
    }
    if(count==9)
    {
        tie=true;
        return true;
    }
    else
    return false;


}

};
int main()
{
    
    tictac obj;
    cout<<"\n\nEnter name of the FIRST player : \n";
    cin>>obj.n1;
    cout<<"Enter name of the SECOND player : \n";
    cin>>obj.n2;
    cout<<"\n\n";

    cout<<"-"<<obj.n1<<" is player 1 so he/she will play FIRST(X) \n";
    cout<<"-"<<obj.n2<<" is player 2 so he/she will play SECOND(O) \n\n\n";
    obj.layout();
    while (!obj.check())
    {
        
        obj.fillToken();
        obj.check();
    }
   
    if(obj.token =='X' && obj.tie == false)
    {
        cout<<obj.n2<<"wins!!"<<endl;
        
    }
    if(obj.token =='O' && obj.tie == false)
    {
        cout<<obj.n1<<"wins!!"<<endl;
        
    }
    if(obj.tie==true)
    {
        cout<<"IT'S A DRAW !!"<<endl;
        
    }
    return 0;
}
