#include<iostream>
#include<cstring>
#include<iomanip>
#define MAX_SIZE 50
#define MAX_STATIONS_ON_LINE 20
#define MAX_LINES_IN_SYSTEM 5
using namespace std;
void showAllLines();
// Global Variables Declared Below:
int stations_count=0,lines_count=0;

//User defined Functions Start below

string getInputString() {
    string result;
    char inputBuffer[MAX_SIZE];
    cin.ignore();
    cin.getline(inputBuffer,MAX_SIZE,'\n');
    for(int i=0;inputBuffer[i]!='\0';i++){
        result=result+inputBuffer[i];
    }
    return result;
}

int getInputInt(){
    int num;
    cin>>num;
    return num;
}
bool getInputBool(){
    bool flag;
    cout<<"1/0(true/false) ";
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
    cout<<left<<setw(3)<<"No."<<setw(20)<<"Name"<<setw(14)<<"Stations"<<endl;
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

void createStation(){
    string name;
    int numberOfPlatforms;
    bool accessible;
    cout<<"Enter the name of the station: ";
    name=getInputString();
    sub_st[stations_count].setName(name);
    cout<<"Please enter the number of platforms in "<<name<<": ";
    numberOfPlatforms=getInputInt();
    sub_st[stations_count].setPlatforms(numberOfPlatforms);
    cout<<"Is "<<name<<" accessible to disabled users? ";
    accessible=getInputBool();
    sub_st[stations_count].setAccessibility(accessible);
    cout<<"Station created successfully!"<<endl;
    stations_count++;
    }

class Line{
    string name;
    Station *stations[MAX_STATIONS_ON_LINE];
    int currentNumberOfStations;
    public:
        int numberOfStations(){
            return currentNumberOfStations;
        }
        void setName(){
            cout<<"Enter the name of the line\n\t";
            name=getInputString();
        }
        bool checkStation(Station arg){
            for(int i=0;i<currentNumberOfStations;i++){
                if(arg.getName()==(stations[i]->getName())){
                    return true;
                }
            }
            return false;
        }

        void addStation(Station *station){
            if(currentNumberOfStations<MAX_STATIONS_ON_LINE){
                stations[currentNumberOfStations]=station;
                currentNumberOfStations++;
            }else{
                cout<<"The line has reached it's limit for stations!"<<endl;
                cout<<"Please remove some stations before adding newer ones"<<endl;
            }
        }
        void removeStation(Station *station){
            int found=0;
            for(int i=0;i<currentNumberOfStations;i++){
                if((*stations)[i].getName()==(*station).getName()){
                    found=1;
                    currentNumberOfStations--;
                }
                stations[i]=stations[i+found];
            }
            cout<<"Please note that the station is only removed from the line, and not from the overall list of stations"<<endl;
        }
        void removeStation(int index){
            if(index<=currentNumberOfStations){
                for(int i=index-1;i<currentNumberOfStations;i++){
                    stations[i]=stations[i+1];
                }
                currentNumberOfStations--;
            }
        }
        void showDetails(int no){
            printHeader(37);
            cout<<left<<setw(3)<<no+1<<setw(20)<<name<<setw(14)<<currentNumberOfStations<<endl;
        }
        void showStationsInfo(){
            printHeader(47);
            printStationTopics();
            printHeader(47);
            for(int i=0;i<currentNumberOfStations;i++){
                stations[i]->showDetails(i);
            }
            printHeader(47);

        }

}sub_lines[5];

void createLine(){
    if(lines_count>=MAX_LINES_IN_SYSTEM){
        cout<<"Too many lines in the system!\nRemove lines before adding new ones\n\n"<<endl;
    }else{
        sub_lines[lines_count].setName();
        lines_count++;
       }
    }


class subwaySystem{
    Line *lines[MAX_LINES_IN_SYSTEM];
    int currentNumberOfLines;
public:
    int numberOfLines(){
        return currentNumberOfLines;
        }
    void removeStationFromLine(){
        int lineCode,stationCode;
        showAllLines();
        cout<<"Choose which line you want to remove a station from: ";
        cin>>lineCode;
        if(lineCode<=lines_count){
            sub_lines[lineCode-1].showStationsInfo();
            cout<<"Choose which station you want to remove: ";
            cin>>stationCode;
            if(stationCode<=sub_lines[lineCode-1].numberOfStations()){
                sub_lines[lineCode-1].removeStation(stationCode);
            }
            else{
                cout<<"Please enter a valid Station Code"<<endl;
            }
        }else{
            cout<<"Please enter a valid line number"<<endl;
        }
    }

}subway;

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

void showStationsOnLine(){
    int lineNum;
    showAllLines();
    cout<<"\n\nEnter the Line Number : " ;
    cin>>lineNum;
    sub_lines[lineNum-1].showStationsInfo();
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
void removeStation(){
    int index;
    showAllStations();
    cout<<"Which station do you want to delete?"<<endl;
    cin>>index;
    for(int i=0;i<lines_count;i++){
        if(sub_lines->checkStation(sub_st[i])){
            sub_lines[i].removeStation(&sub_st[i]);
            break;
        }
    }
    for(int i=index;i<stations_count;i++){
        sub_st[index]=sub_st[index+1];
    }
    stations_count--;
}

void removeLine(){
    int index;
    showAllLines();
    cout<<"Which line do you want to remove? ";
    cin>>index;
    if((index>MAX_LINES_IN_SYSTEM||index>lines_count)){
        cout<<"\nNumber of lines in the system are "<<lines_count<<endl;
        cout<<"Please enter a valid number!"<<endl;
        return;
    }
    for(int i=index-1;i<lines_count;i++){
        sub_lines[i]=sub_lines[i+1];
    }
    lines_count--;
    cout<<"Line removed successfully"<<endl;
    }

void noObjectsError(string name){
    cout<<"Please create a "<<name<<" before using this function!\n\n"<<endl;
    }

int main(){
    int cho=1;
    Station station[MAX_STATIONS_ON_LINE*MAX_LINES_IN_SYSTEM];
    cout<<right<<setw(50)<<"Subway Management System"<<endl;
    while(cho!=0){
        cout<<"\n\n"<<endl;
        cout<<"Choose your operation"<<endl;
        cout<<"1. Add a new Station"<<endl;
        cout<<"2. Create a new line"<<endl;
        cout<<"3. Add a station to a line"<<endl;
        cout<<"4. Remove station from a line"<<endl;
        cout<<"5. Show all stations on line"<<endl;
        cout<<"6. Show all lines"<<endl;
        cout<<"7. Show all stations"<<endl;
        cout<<"8. Remove station"<<endl;
        cout<<"9. Remove line"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>cho;
        system("cls");
        switch(cho){
            case 1:{
                createStation();
            }
            break;
            case 2:{
                createLine();
                break;

            case 3:
            {
                if(stations_count==0||lines_count==0){
                    noObjectsError("station and a line");
                    break;
                }
                addStationToLine();
            }
            break;
            case 4:
            {
                if(stations_count==0||lines_count==0){
                    noObjectsError("station and a line");
                    break;
                }
                subway.removeStationFromLine();
            }

            break;
            case 5:{
                if(lines_count==0){
                    noObjectsError("line");
                    break;
                }
                showStationsOnLine();
            }
            break;
            case 6:
            {
                if(lines_count==0){
                    noObjectsError("line");
                    break;
                }
                showAllLines();
            }

            break;
            case 7:
            {
                if(stations_count==0){
                    noObjectsError("station");
                    break;
                }
                showAllStations();
            }
            break;
            case 8:
            {
                if(stations_count==0){
                    noObjectsError("station");
                    break;
                }
                removeStation();
                break;
            }
            case 9:
            {
                if(lines_count==0){
                    noObjectsError("line");
                    break;
                }
                removeLine();
                break;
            }
            case 0:
            {
                cout<<"Thanks for using! Have a good day"<<endl;
            }
        }
    }
    }
    return 0;

}
