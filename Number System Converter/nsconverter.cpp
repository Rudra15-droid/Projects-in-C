#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
string hexconv(int no){
    switch(no){
    case 1:
        return "1";
    case 2:
        return "2";
    case 3:
        return "3";
    case 4:
        return "4";
    case 5:
        return "5";
    case 6:
        return "6";
    case 7:
        return "7";
    case 8:
        return "8";
    case 9:
        return "9";
    case 10:
        return "A";
    case 11:
        return "B";
    case 12:
        return "C";
    case 13:
        return "D";
    case 14:
        return "E";
    case 15:
        return "F";

        }
    }
int revhexconv(char a){
    switch(a){
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
        }

    }
void fromdec(){
    long int n;
    int base;
    cout<<"Enter the base: ";
    cin>>base;
    cout<<"Enter the number in decimal: ";
    cin>>n;
    long long int bin=0,result=0;
    long int temp=n;
    while(temp>0){
        bin+=temp%base;
        temp/=base;
        if(temp>=0){
            bin*=10;
        }
    }
    while(bin>0){
        result+=bin%10;
        bin/=10;
        if(bin>0){
            result*=10;
        }
    }
    cout<<n<<" in base "<<base<<" is "<<result<<endl;


}
void todec(){
    int base;
    long long in;
    long long result=0;
    cout<<"Enter the base: ";
    cin>>base;
    cout<<"Enter the number in base "<<base<<": ";
    cin>>in;
    int power=0;
    while(in>0){
        result+=(in%10)*pow(base,power);
        in/=10;
        power++;
    }
    cout<<"The number in decimal is "<<result<<endl;
    }

void dectohex(){
    long long in;
    string out_t("");
    string out("0x");
    cout<<"Enter the number in decimal: ";
    cin>>in;
    while(in>0){
        out_t+=hexconv(in%16);
        in/=16;
    }
    reverse(out_t.begin(),out_t.end());
    out+=out_t;
    cout<<out<<endl;

    }
void hextodec(){
    string in;
    cout<<"Enter the number in hexadecimal: ";
    cin>>in;
    int power=0;
    long long int res=0;
    for(int i=in.length()-1;i>=0;i--){
        res+=revhexconv(in[i])*(pow(16,power));
        power++;
    }
    cout<<"Decimal: "<<res<<endl;
    }

int main(){
    long long int result;
    int choice;
    do{
        cout<<"1. Convert from Decimal(base<=10)"<<endl;
        cout<<"2. Convert to Decimal(base<=10)"<<endl;
        cout<<"3. Convert Decimal to Hexadecimal"<<endl;
        cout<<"4. Convert Hexadecimal to Decimal"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        system("cls");
        switch(choice){
        case 1:
            fromdec();
            break;
        case 2:
            todec();
            break;
        case 3:
            dectohex();
            break;
        case 4:
            hextodec();
            break;
        case 0:
            cout<<"Exiting. See you soon!";
            }
    }while(choice!=0);

}
