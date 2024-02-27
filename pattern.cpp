#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Please enter the string you want: ";
    cin>>str;
    cout<<"\n\n"<<endl;
    int siz=str.length();
    for(int row=0;row<(siz);row++){
        for(int i=row;i<siz;i++){
            cout<<str[i];
        }

    for(int sp=1+row;sp>0;sp--){
        cout<<" ";
    }
    cout<<str[row];

    for(int sp=1+row;sp>0;sp--){
        cout<<" ";
    }
    for(int i=row;i<siz;i++){
            cout<<str[i];
        }
   // if(row!=siz-1)
        cout<<endl;
        }


    for(int row=siz-2;row>=0;row--){
        for(int i=row;i<siz;i++){
            cout<<str[i];
        }

    for(int sp=1+row;sp>0;sp--){
        cout<<" ";
    }
    cout<<str[row];

    for(int sp=1+row;sp>0;sp--){
        cout<<" ";
    }
    for(int i=row;i<siz;i++){
            cout<<str[i];
        }

    cout<<endl;
    }

    cout<<"\n\nPrepared by: "<<endl;

    for(int row=1;row<=5;row++){
        for(int col=1;col<=5;col++){
            if(col==1||row==1||(col==5&&row<=3)||row==3||(row==4&&col==3)||(row==5&&col==5)){
                cout<<"* ";
            }else{
                cout<<"  ";
                }
        }
        cout<<" ";
        for(int col=1;col<=5;col++){
            if(col==1||col==5||row==5){
                cout<<"* ";
            }else
                cout<<"  ";
        }
        cout<<" ";
        for(int col=1;col<=5;col++){
            if(col==1||(col==5&&row==3)||(row==2&&col==4)||(row==4&&col==4)||((row==1||row==5)&&col<4)){
                cout<<"* ";
            }else
                cout<<"  ";
        }
        cout<<" ";
        for(int col=1;col<=5;col++){
            if(col==1||row==1||(col==5&&row<=3)||row==3||(row==4&&col==3)||(row==5&&col==5)){
                cout<<"* ";
            }else{
                cout<<"  ";
                }
        }
        cout<<" ";
        for(int col=1;col<=5;col++){
            if(col==1||col==5||row==1||row==3){
               cout<<"* ";
            }else{
                cout<<"  ";
                }
            }

        cout<<endl;
    }
    }
