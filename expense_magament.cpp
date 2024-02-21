#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

long int tot_exp=0,tot_inc=0,tot_tran=0,curr_bal=0;
int e_count=0,i_count=0,t_count=0,e_cats_count=0,i_cats_count=0,t_cats_count=0,day=1;
int days[100];
string e_cats[100],i_cats[100],t_cats[100];

class expense{
    public:
    long int amt;
    string name,cat;
    int day;
    }e[100];
class income{
    public:
    long int amt;
    string name,cat;
    int day;
    }inc[100];
class transfers{
public:
    long int amt;
    string name;
    int day;
    }t[100];


void add_exp(){
    int found=0;
    string name,cat;
    long int amt;
    cout<<"Enter the name of the expense: ";
    cin>>name;
    cout<<"Enter the amount of expense: ";
    cin>>amt;
    cout<<"Enter the category of expense: ";
    cin>>cat;
    for(int i=0;i<e_cats_count;i++){
        if(cat.compare(e_cats[i])==0){
                found=1;
            goto setvars;
        }
    }
    if(!found){
        cout<<"Creating new category "<<cat<<endl;
        e_cats_count++;
        e_cats[e_cats_count]=cat;
    }
    setvars:
        e[e_count].name=name;
        e[e_count].amt=amt;
        e[e_count].cat=cat;
        e[e_count].day=day;
        tot_exp+=amt;
        curr_bal-=amt;
        cout<<"Record Added Succesfully!"<<endl;
        e_count++;
}

void add_inc(){
    int found=0;
    string name,cat;
    long int amt;
    cout<<"Enter the name of the income: ";
    cin>>name;
    cout<<"Enter the amount of income: ";
    cin>>amt;
    cout<<"Enter the category of income: ";
    cin>>cat;
    for(int i=0;i<i_cats_count;i++){
        if(cat.compare(i_cats[i])==0){
                found=1;
            goto setvars;
        }
    }
    if(!found){
        cout<<"Creating new category "<<cat<<endl;
        i_cats_count++;
        i_cats[i_cats_count]=cat;
    }
    setvars:
        inc[i_count].name=name;
        inc[i_count].amt=amt;
        inc[i_count].cat=cat;
        inc[i_count].day=day;
        tot_inc+=amt;
        curr_bal+=amt;
        cout<<"Record Added Successfully!"<<endl;
        i_count++;

    }

void add_tra(){
    int found=0;
    string name,cat;
    long int amt;
    cout<<"Money transfered to/from:  ";
    cin>>name;
    cout<<"Amount of transfer: (-ve if borrowed ) ";
    cin>>amt;


        t[t_count].name=name;
        t[t_count].amt=amt;
        t[t_count].day=day;
        tot_tran+=amt;
        curr_bal-=amt;
        cout<<"Record Added Successfully!"<<endl;
        t_count++;


}
void show_summ(){
    cout<<"Current Balance: "<<curr_bal<<endl;
    cout<<"Total expenses: "<<tot_exp<<endl;
    cout<<"Total Income: "<<tot_inc<<endl;
    cout<<"Income Records"<<endl;
    cout<<left<<setw(20)<<"Name"<<setw(14)<<"Category"<<setw(15)<<right<<"Amount"<<setw(10)<<"Day"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<i_count;i++){
        cout<<left<<setw(20)<<inc[i].name<<setw(14)<<inc[i].cat<<setw(15)<<right<<inc[i].amt<<setw(10)<<inc[i].day<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
    }
    cout<<"==============================================================================\n"<<endl;
    cout<<"Expense Records"<<endl;
    cout<<left<<setw(20)<<"Name"<<setw(14)<<"Category"<<setw(15)<<right<<"Amount"<<setw(10)<<"Day"<<endl;
    for(int i=0;i<e_count;i++){
        cout<<left<<setw(20)<<e[i].name<<setw(14)<<e[i].cat<<setw(15)<<right<<e[i].amt<<setw(10)<<e[i].day<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
    }
    cout<<"==============================================================================\n"<<endl;
    cout<<"Transfer"<<endl;
    cout<<left<<setw(20)<<"Name"<<setw(15)<<right<<"Amount"<<setw(10)<<"Day"<<endl;
    for(int i=0;i<t_count;i++){
        cout<<left<<setw(20)<<t[i].name<<setw(15)<<right<<t[i].amt<<setw(10)<<t[i].day<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
    }
    cout<<"========================================================================\n"<<endl;

    }

int main(){
    int cho;
    system("cls");
    cout<<"Expense Management Software\n\n"<<endl;
    do{
        cout<<"Current day: "<<day<<"\n\n"<<endl;
        cout<<"1. Add expense"<<endl;
        cout<<"2. Add Income"<<endl;
        cout<<"3. Record Transfer"<<endl;
        cout<<"4. Show summary"<<endl;
        cout<<"5. Set day"<<endl;
        cout<<"0. Exit application"<<endl;
        cout<<"Enter your choice: ";
        cin>>cho;
        switch(cho){
        case 1:
            add_exp();
            break;
        case 2:
            add_inc();
            break;
        case 3:
            add_tra();
            break;
        case 4:
            show_summ();
            break;
        case 5:
            cout<<"Enter which day you want to set: ";
            cin>>day;
            break;
        case 0:
            cout<<"Thanks for using! Have a good day"<<endl;
            break;
            }
    }while(cho!=0);
    }
