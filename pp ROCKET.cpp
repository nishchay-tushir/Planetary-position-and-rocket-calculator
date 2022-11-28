/*
 * main.cpp
 *
 *  Created on: 19-Aug-2022
 *      Author: Nishchay Tushir
 */

#include <iostream>
#include <fstream>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class wdata{
    public:
        int airspeed;
        int weather; //0 is for sunny , 1 is for cloudy , 2 is for rainy;
        int humidity;
        int temperature;
};

class rocket {
	public :
	      string name;
        float mass;        
        float th;
        int year;
        int month;
        int day;
        rocket(){
          cout<<"What is the code for the rocket: ";
          cin>>name;
          cout<<"Mass of the rocket in Tons? ";//sample value=325.7
          cin>>mass;
          cout<<"How much thrust does it produce in Tons? ";//3945.69
          cin>>th;
          cout<<"What will be the launch year? ";
          cin>>year;
          cout<<"Month of launch? ";
          cin>>month;
          cout<<"Day of launch? ";
          cin>>day;
        }
        rocket(string dummyname, float dummymass , float dummyth){
          name=dummyname;
          mass=dummymass;
          th=dummyth;
        }

		void getdetails();
		int launchcal();
};


int rocket::launchcal(){
        float weight=mass*9.8;
        float thrustrq=3500;//3.5million kg of thrust required to escape the earth's atmosphere;
        float thw=th/weight;//thrust to weight ratio required for rocket =1.15 to 1.5
        int dummy=0;
        cout<<"\n\n";
        string hello = "############################################# STARTING LAUNCH CALCULATIONS ENGINE #############################################";     
        for(int l=0;l<hello.length();l++){
          cout<<hello[l];
          Sleep(20);
        }
        cout<<"\nWeight on Earth: "<<weight<<endl;
        Sleep(700);
        cout<<"Thrust/Weight ratio: "<<thw<<endl;
        Sleep(1000);
        cout<<"\n";
        if (th>thrustrq){
            cout<<"Thrust required to exit the atmosphere found satisfactory."<<endl;
            Sleep(200);
            cout<<"Proceeding............"<<endl;
            Sleep(500);
            if(thw>1.15 && thw<1.5){
                cout<<"Launch power to weight ratio found satisfactory."<<endl;
                dummy=1;
                Sleep(500);
            }
            else{
                cout<<"Rocket: "<<name<<" power to weight ratio found unsatisfactory."<<endl;
                dummy=0;
            }
        }
        else {
            cout<<"Rocket: "<<name<<" unfortunately won't be able to succesfully escape the Earth's atmosphere."<<endl;
            dummy=0;
        }
        return dummy;         
}

int weatherok(int &airspeed,int &weather,int &humidity,int &temperature,int &day,int &month,int &year){
  int dummy,dummy1,dummy2,dummy3;
  string hello = "############################################# STARTING WEATHER CALCULATIONS ENGINE #############################################";     
        for(int l=0;l<hello.length();l++){
          cout<<hello[l];
          Sleep(30);
        }
  Sleep(500);
  cout<<"\nAnalyzing weather conditions on "<<day<<"/"<<month<<"/"<<year<<endl;
  if (airspeed<37){
    Sleep(800);
    cout<<"Windspeed :"<<airspeed<<"km/h : OK "<<endl;
    dummy1=1;
  }
  else {
    cout<<"Airspeed :"<<airspeed<<"km/h : Not good for launch "<<endl;
    dummy1=0;
  }
  if (weather==0){
    Sleep(800);
    cout<<"Weather: Sunny : OK "<<endl;
    dummy2=1;
  }
  else {
    cout<<"Weather not good for launch "<<endl;
    dummy2=0;
  }
  if (temperature<33 && temperature>10){
    Sleep(800);
    cout<<"Temperature :"<<temperature<<"C : OK "<<endl;
    dummy3=1;
  }
  else {
    cout<<"Temperature :"<<temperature<<"C : Not good for launch "<<endl;
    dummy3=0;
  }
  if (dummy1==1 && dummy2==1 && dummy3==1){
    dummy=1;
  }
  return dummy;
}

int is_leap_year(int y) {
  return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int days_in_month(int m, int y) {
  if (m == 4 || m == 6 || m == 9 || m == 11)
    return 30;
  else if (m == 2)
    return is_leap_year(y) ? 29 : 28;
  else
    return 31;
}

int days_Between(int &year , int &month , int &day) {  
  int result = day;
  for (int y = 2000; y < year; y++)
    result += is_leap_year(y) ? 366 : 365;
  for (int m = 1; m < month; m++)
    result += days_in_month(month, year);
  return result;
}

int success(int &days){
    string hello = "############################################ STARTING POSITION CALCULATIONS ENGINE ############################################";     
        for(int l=0;l<hello.length();l++){
          cout<<hello[l];
          Sleep(30);
        }
    Sleep(500);
    cout<<"\nAll calculations for take off found satisfactory , calculating t-days to launch."<<endl;
    Sleep(500);
    int synodic=528;
    int x=0;
    //initial synodic day=12/6/2001;
    while(x==0){
        synodic=synodic+780;
        if (synodic>(days)){
            cout<<"Next Mars and Earth will be alligned in "<<synodic-days<<" days"<<endl;
            cout<<"Days you should launch the space vehicle in "<<synodic-days-210<<endl;
            x=1;
            Sleep(800);
        }
    }
    return synodic-days-210;
}

//synodic day of mars =780 days-501 days it takes to reach mars so we need to launch 501 day prior;last synodic day =12th june 2001=528 days;

int main(){
  

  int input=1;
  while(input==1){
        string hello = "Welcome to PP rocket project ";    
        for(int l=0;l<hello.length();l++){
          cout<<hello[l];
          Sleep(50);
        }
        cout<<"\n";


        ifstream myfile;
        myfile.open("C:\\Users\\Nishchay Tushir\\Desktop\\PProcketproject\\data.txt");
        if (!myfile) {
            cerr << "Unable to open file data.txt";
        exit(1);   // call system to stop
        }
        string x;
        int a;
        wdata t;
        while (myfile >> x) {}
        myfile.close();
        string rx = x.substr(0, 2);
        string px = x.substr(2, 1);                        ////pulling weather from .txt
        string gx = x.substr(3, 2);
        t.airspeed=stoi(rx);
        t.weather=stoi(px);
        t.temperature=stoi(gx);

        rocket r;
        //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        //SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        int dummy=r.launchcal();
        if (dummy ==1){
          
          int current;
          current=abs(days_Between(r.year,r.month,r.day));
          int daystolaunch;
          daystolaunch=success(current);

          //##############################################################################################################
          //converting the days to launch back to a proper date
          int day=r.day;
          int month=r.month;
          int year=r.year;
          for (int i=0;i<daystolaunch;i++){
              day++;
              if (day > daysPerMonth[month-1] || ( month==2 && day==29 && !is_leap_year(year) ) ){
                day = 1;
                month++;
                if (month==13){
                  month = 1;
                  year++;
                }
              }
          }
          Sleep(900);
          cout<<"Exact Date you should launch "<<r.name<<" on "<<day<<"/"<<month<<"/"<<year<<endl; 
          Sleep(900);
          int weathercheck;
          weathercheck=weatherok(t.airspeed,t.weather,t.humidity,t.temperature,day,month,year);
          if (weathercheck==1){
            cout<<"################################### All conditions are upto launch standard, Go for launch ###################################"<<endl;
          }
          else{
            cout<<"Weather not found satisfactory"<<endl;
          }         
        }
        else {
          cout<<"Simulaion failed : Rocket "<<r.name<<" not found satisfactory for further calculations."<<endl;
        }
        cout<<"Do you want to run the code again? (1 for yes 0 for no)"<<endl;
        cin>>input;
  }
        return 0;
}

