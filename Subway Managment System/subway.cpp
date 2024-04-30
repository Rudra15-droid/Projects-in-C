#include<iostream>
#include<string.h>
#include<iomanip>
#define MAX_SIZE 50
#define MAX_STATIONS_ON_LINE 20
#define MAX_LINES_IN_SYSTEM 5
using namespace std;
// Global Variables Declared Below:
int stations_count=0,lines_count=0;

//User defined Functions Start below
string getInputString() {
    string result;
    char inputBuffer[MAX_SIZE];
    cout<<"Enter the string: ";
    cin.ignore();
    cin.getline(inputBuffer,MAX_SIZE,'\n');
    for(int i=0;inputBuffer[i]!='\0';i++){
        result=result+inputBuffer[i];
    }
    cout<<result<<endl;
    return result;
}

int getInputInt(){
    int num;
    cout<<"Enter an integer: ";
    cin>>num;
    return num;
}
bool getInputBool(){
    bool flag;
    cout<<"Enter 0 for no, and 1 for yes: ";
    cin>>flag;
    return  flag;
}
void printHeader(int no=47,char c='-'){
    for(int i=0;i<no;i++){
        cout<<c;
    }
    cout<<endl;
}
void printStationTopics(){
    cout<<left<<setw(3)<<"No."<<setw(20)<<"Name"<<setw(14)<<"Platforms"<<setw(10)<<"Accessible"<<endl;
    }
void printLineTopics(){
    cout<<left<<setw(3)<<"No."<<setw(20)<<"Name"<<setw(14)<<"Platforms"<<endl;
    }
class Station{
    string name;
    int numberOfPlatforms;
    bool isAccesible;
    public:
        Station(){
            name="Default Name";
            numberOfPlatforms=1;
            isAccesible=false;
        }
        Station(string name,int platforms,bool accessible){
            this->name=name;
            numberOfPlatforms = platforms;
            isAccesible=accessible;
        }

        void setName(string name){
            this->name=name;
            cout<<"Name set successfully!"<<endl;
        }

        string getName(){
            return name;
        }
        void setPlatforms(int platforms){
            numberOfPlatforms=platforms;
        }
        void setAccessibility(bool accessible){
            isAccesible=accessible;
        }
        void showDetails(int no){
            cout<<boolalpha;
            cout<<left<<setw(3)<<no+1<<setw(20)<<name<<setw(14)<<numberOfPlatforms<<setw(10)<<isAccesible<<endl;
        }

}sub_st[100];



class Line{
    string name;
    Station stations[MAX_STATIONS_ON_LINE];
    int currentNumberOfStations;
    public:
        int numberOfStations(){
            return currentNumberOfStations;
        }
        void setName(){
            cout<<"Enter the name of the line\n\t";
            name=getInputString();
        }

        void addStation(Station *station){
            if(currentNumberOfStations<MAX_STATIONS_ON_LINE){
                stations[currentNumberOfStations]=*station;
                currentNumberOfStations++;
            }else{
                cout<<"The line has reached it's limit for stations!"<<endl;
                cout<<"Please remove some stations before adding newer ones"<<endl;
            }
        }
        void removeStation(Station *station){
            int found=0;
            for(int i=0;i<currentNumberOfStations;i++){
                if(stations[i].getName()==(*station).getName()){
                    found=1;
                    currentNumberOfStations--;
                }
                stations[i]=stations[i+found];
            }
            cout<<"Please note that the station is only removed from the line, and not from the overall list of stations"<<endl;
        }
        void showDetails(int no){
            printHeader(37);
            cout<<left<<setw(3)<<no+1<<setw(20)<<name<<setw(14)<<currentNumberOfStations<<endl;
        }
        void showStationsInfo(){
            printHeader(25);
            cout<<left<<setw(3)<<"No."<<setw(20)<<"Name"<<endl;
            printHeader(25);

        }

}sub_lines[5];


class subwaySystem{
    Line lines[MAX_LINES_IN_SYSTEM];
    int currentNumberOfLines;
public:
    int numberOfLines(){
        return currentNumberOfLines;
        }
};

void showAllStations(){
        printHeader();
        printStationTopics();
        printHeader();
        for(int i=0;i<stations_count;i++){
            sub_st[i].showDetails(i);
            cout<<endl;
        }
        printHeader();
}
void showAllLines(){
        printHeader(37);
        printLineTopics();
        printHeader(37);
        for(int i=0;i<lines_count;i++){
            sub_lines[i].showDetails(i);
            cout<<endl;
        }
        printHeader(37);
    }

void addStationToLine(){
        int chooseLine,chooseStation;
        showAllLines();
        cout<<"Which line do you want to use: ";
        cin>>chooseLine;
        showAllStations();
        cout<<"Which station do you want to add: ";
        cin>>chooseStation;
        sub_lines[chooseLine-1].addStation(&sub_st[chooseStation-1]);
}
void removeStationFromLine(){
    int chooseLine,chooseStation;

}

int main(){
    int cho=1;
    Station station[MAX_STATIONS_ON_LINE*MAX_LINES_IN_SYSTEM];
    cout<<right<<setw(50)<<"Subway Management System"<<endl;
    while(cho!=0){
        cout<<"Choose your operation"<<endl;
        cout<<"1. Add a new Station"<<endl;
        cout<<"2. Create a new line"<<endl;
        cout<<"3. Add a station to a line"<<endl;
        cout<<"4. Remove station from a line"<<endl;
        cout<<"5. Show all stations"<<endl;
        cout<<"6. Show all lines"<<endl;
        cout<<"Enter your choice: ";
        cin>>cho;
        system("cls");
        switch(cho){
            case 1:{
                sub_st[stations_count].setName(getInputString());
                sub_st[stations_count].setPlatforms(getInputInt());
                sub_st[stations_count].setAccessibility(getInputBool());
                cout<<"Station created successfully!"<<endl;
                stations_count++;
            }
            break;
            case 2:{
                    if(lines_count>=MAX_LINES_IN_SYSTEM){
                        cout<<"Too many lines in the system!\nRemove lines before adding new ones"<<endl;
                    }else{
                        sub_lines[lines_count].setName();
                        lines_count++;
                        }
                }
                break;

            case 3:
            {
                addStationToLine();
            }
            break;
            case 4:
            {

            }
            case 5:{
                showAllStations();
            }
            break;
            case 6:
            {
                showAllLines();
            }break;
        }
    }
    return 0;
}
