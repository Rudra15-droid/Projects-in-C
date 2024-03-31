#include<iostream>
#include<string>
#include<iomanip>
#define lcount 78
using namespace std;

long int tot_exp=0,tot_inc=0,tot_tran=0,curr_bal=0;
int e_count=0,i_count=0,t_count=0,e_cats_count=0,i_cats_count=0,t_cats_count=0,day=1; //Variables for number of records in each type, along with number of categories and day
int counter=1; // Incrementing variables for assigning IDs
int days[100];
string e_cats[100],i_cats[100],t_cats[100];
long int e_cat_tot[100]={0},i_cat_tot[100]={0};

class expense{
    public:

    int counter,cat;
    long int amt;
    string name;
    int day;
    }e[100];
class income{
    public:
    long int amt;
    int counter,cat;
    string name;
    int day;
    }inc[100];
class transfers{
public:
    long int amt;
    int counter;
    string name;
    int day;
    }t[100];

void printline(int n,char c='-'){ //Print a line using given character n number of times
    while(n>0){
        cout<<c;
        n--;
    }
    cout<<endl;
    }
void sort_chronologically(int opt){
    // 1 for expenses, 2 for income and 3 for transfers
    switch(opt){

    case 1:{
        for(int i=0;i<e_count;i++){
            for(int j=i+1;j<e_count;j++){
                if(e[j].day>e[i].day){
                    expense temp;
                    temp=e[j];
                    e[j]=e[i];
                    e[i]=temp;
                }
            }
        }
    }
    break;
    case 2:
        {
            for(int i=0;i<i_count;i++){
                for(int j=i+1;j<i_count;j++){
                    if(inc[j].day>inc[i].day){
                        income temp;
                        temp=inc[j];
                        inc[j]=inc[i];
                        inc[i]=temp;
                        }
                }
            }
        }
        break;
    case 3:
        {
            for(int i=0;i<t_count;i++){
                for(int j=i+1;j<t_count;j++){
                    if(t[j].day>t[i].day){
                        transfers temp;
                        temp=t[j];
                        t[j]=t[i];
                        t[i]=temp;
                        }
                }
            }
        }
}
}
void add_exp(){
    int catc,ch;
    string name,cat;
    long int amt;
    cout<<"Enter the name of the expense: ";
    cin>>name;
    cout<<"Enter the amount of expense: ";
    cin>>amt;
    cout<<"Choose the category of the expense"<<endl;
    {

        for(int i=0;i<e_cats_count;i++){
            cout<<i+1<<"."<<e_cats[i]<<" ";
        }
        cout<<"Enter your choice (0 to add new category): ";
        cin>>ch;
        if(!ch){
            catc=0;
            goto setcat;
        }else{
            cat=e_cats[ch-1];
            e_cat_tot[ch-1]+=amt;
            }
        goto setvars;
        setcat:
            {
                string catname;
                cout<<"Enter the name of the new category: ";
                cin>>catname;
                e_cats[e_cats_count]=catname;
                cat=e_cats_count;
                e_cat_tot[e_cats_count]+=amt;
                e_cats_count++;
            }
    }
    setvars:
        e[e_count].name=name;
        e[e_count].amt=amt;
        e[e_count].cat=ch;
        e[e_count].day=day;
        e[e_count].counter= counter;
        tot_exp+=amt;
        curr_bal-=amt;
        cout<<"Record Added Succesfully!"<<endl;
        e_count++;
        counter++;
        sort_chronologically(1);
}

void add_inc(){          //Implement Cats according to numbers in this
    int found=0,catc,cat;
    string name;
    long int amt;
    cout<<"Enter the name of the income: ";
    cin>>name;
    cout<<"Enter the amount of income: ";
    cin>>amt;
    cout<<"Enter the category of income: "<<endl;
    {
        int ch;
        for(int i=0;i<i_cats_count;i++){
            cout<<i+1<<"."<<i_cats[i]<<" ";
        }
        cout<<"Enter your choice (0 to add new category): ";
        cin>>ch;
        if(!ch){
            catc=0;
            goto setcat;
        }else{
            cat=ch-1;
            i_cat_tot[ch-1]+=amt;
            }
        goto setvars;
        setcat:
            {
                string catname;
                cout<<"Enter the name of the new category: ";
                cin>>catname;
                i_cats[i_cats_count]=catname;
                cat=i_cats_count;
                i_cat_tot[i_cats_count]+=amt;
                i_cats_count++;
            }
    }
    setvars:
        inc[i_count].name=name;
        inc[i_count].amt=amt;
        inc[i_count].cat=cat;
        inc[i_count].day=day;
        inc[i_count].counter=counter;
        counter++;
        tot_inc+=amt;
        curr_bal+=amt;
        cout<<"Record Added Successfully!"<<endl;
        i_count++;
        sort_chronologically(2);
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
        t[t_count].counter=counter;
        counter++;
        tot_tran+=amt;
        curr_bal-=amt;
        cout<<"Record Added Successfully!"<<endl;
        t_count++;
        sort_chronologically(3);


}
void show_detailed_income(){
    cout<<"Income Records"<<endl;
    printline(lcount);
    cout<<left<<setw(15)<<"ID"<<setw(15)<<"Name"<<setw(14)<<"Category"<<setw(15)<<right<<"Amount"<<setw(10)<<"Day"<<endl;
    printline(lcount);
    for(int i=0;i<i_count;i++){
        cout<<left<<setw(15)<<inc[i].counter<<setw(15)<<inc[i].name<<setw(14)<<i_cats[inc[i].cat]<<setw(15)<<right<<inc[i].amt<<setw(10)<<inc[i].day<<endl;
        printline(lcount);
    }

    }
void show_detailed_expenses(){
    cout<<"Expense Records"<<endl;
    printline(lcount);
    cout<<left<<setw(15)<<"ID"<<setw(15)<<"Name"<<setw(14)<<"Category"<<setw(15)<<right<<"Amount"<<setw(10)<<"Day"<<endl;
    for(int i=0;i<e_count;i++){
        cout<<left<<setw(15)<<e[i].counter<<setw(15)<<e[i].name<<setw(14)<<e_cats[e[i].cat]<<setw(15)<<right<<e[i].amt<<setw(10)<<e[i].day<<endl;
        printline(lcount);
    }
}
void show_detailed_transfers(){
    cout<<"Transfer"<<endl;
    printline(lcount);
    cout<<left<<setw(15)<<"ID"<<setw(15)<<"Name"<<setw(15)<<right<<"Amount"<<setw(10)<<"Day"<<endl;
    for(int i=0;i<t_count;i++){
        cout<<left<<setw(15)<<t[i].counter<<setw(15)<<t[i].name<<setw(15)<<right<<t[i].amt<<setw(10)<<t[i].day<<endl;
        printline(lcount);
    }
    }
void show_detailed_records(){
    show_detailed_income();
    printline(lcount,'=');
    cout<<endl;
    show_detailed_expenses();
    printline(lcount,'=');
    cout<<endl;
    show_detailed_transfers();
    printline(lcount,'=');
}
void show_summ(){
    char cho;
    cout<<"Current Balance: "<<curr_bal<<endl;
    cout<<"Total expenses: "<<tot_exp<<endl;
    cout<<"Total Income: "<<tot_inc<<endl;
    cout<<"\n\n"<<endl;
    cout<<"Income:"<<endl;
    for(int i=0;i<i_cats_count;i++){
    cout<<"\t"<<i_cats[i]<<right<<setw(10)<<i_cat_tot[i]<<endl;
    }
    cout<<endl;
    cout<<"Expenses: "<<endl;
    for(int i=0;i<e_cats_count;i++){
        cout<<"\t"<<e_cats[i]<<right<<setw(10)<<e_cat_tot[i]<<endl;
    }
    cout<<endl;
    again:
    cout<<"Do you want to view the detailed records? (y/n):";
    cin>>cho;
    if(cho=='y'||cho=='Y')
        show_detailed_records();
    else if(cho=='n'||cho=='N')
        return;
    else{
        cout<<"Please enter a valid input!"<<endl;
        goto again;
    }
}
void edit_record(){
    int cho,rno,icho;
    cout<<"Which category of record would you like to edit?"<<endl;
    cout<<"1. Income\n2.Expenses\n3.Transfers\n0. Do nothing and exit"<<endl;
    cout<<"Your choice: "<<endl;
    cin>>cho;
    switch(cho){
    case 1:
        show_detailed_income();
        cout<<"Enter the record number you want to edit: ";
        cin>>rno;
        cout<<"What would you like to change?\n1. Name\n2. Category\n3. Amount\n0. Do nothing and exit"<<endl;
        cin>>icho;
        }
    }
void del_record(){
    int cho,rno;
    cout<<"Which category of record would you like to delete from?"<<endl;
    cout<<"1. Income\n2.Expenses\n3.Transfers\n0. Do nothing and exit"<<endl;
    cout<<"Your choice: "<<endl;
    cin>>cho;
    switch(cho){
    case 1:
     {
        show_detailed_income();
        cout<<"Enter the record number you wish to delete: ";
        cin>>rno;
        int temp=0;
        for(int i=0;i<i_count;i++){
            if(inc[i].counter==rno){
                temp=1;
                tot_inc-=inc[i].amt;
                i_cat_tot[inc[i].cat]=i_cat_tot[inc[i].cat]-inc[i].amt;
                curr_bal-=inc[i].amt;
            }
            inc[i]=inc[i+temp];

        }
        inc[i_count]={0};
        i_count--;
        }
    break;
    case 2:
        {
        show_detailed_expenses();
        cout<<"Enter the record number you wish to delete: ";
        cin>>rno;
        int temp=0;
        for(int i=0;i<e_count;i++){
            if(e[i].counter==rno){
                temp=1;
                tot_exp-=e[i].amt;
                e_cat_tot[e[i].cat]=e_cat_tot[e[i].cat]-e[i].amt;
                curr_bal+=e[i].amt;
            }
            e[i]=e[i+temp];
        }
        e[e_count]={0};
        e_count--;
        }
        break;
    case 3:
        {
        show_detailed_transfers();
        cout<<"Enter the record number you wish to delete: ";
        cin>>rno;
        int temp=0;
        for(int i=0;i<t_count;i++){
            if(t[i].counter==rno){
                temp=1;
                tot_tran-=t[i].amt;
                curr_bal+=t[i].amt;
            }
            t[i]=t[i+temp];
        }
        t[t_count]={0};
        t_count--;
        }

    }}
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
        cout<<"6. Delete record"<<endl;
        cout<<"0. Exit application"<<endl;
        cout<<"Enter your choice: ";
        cin>>cho;
        system("cls");
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
        case 6:
            del_record();
            break;
        case 0:
            cout<<"Thanks for using! Have a good day"<<endl;
            break;
            }
    }while(cho!=0);
}
