#include "Time.h"
using namespace std;
#include <iostream>

Time::Time(){
    hours = 0;
    minutes = 0;
    seconds = 0;
}

bool Time::isValidHour(int h){return (h >= 0);}
bool Time::isValidMinute(int m){return ((m >= 0) && (m < 60));}
bool Time::isValidSecond(int s){return ((s >= 0) && (s < 60));}


//-----------------SETTERS --------------------

void Time::setHours(int h) {
    if (isValidHour(h)) {
        hours = h;
    }
    else{
        cout << "Error, not a valid hour input, please try again";
    }
}

void Time::setMinutes(int m) {
    if (isValidMinute(m)) {
        minutes = m;
    }

    else{
        cout << "Error, not a valid minute input, please try again";
    }
}

void Time::setSeconds(int s) {
    if (isValidSecond(s)) {
        seconds = s;
    }
    else{
        cout << "Error, not a valid second input, please try again";
    }
}
//--------------CONSTRUCTORS----------------------

Time::Time(int h, int m, int s){
    setHours(h);
    setMinutes(m);
    setMinutes(s);
}

Time::Time(int h, int m){
    setHours(h);
    setMinutes(m);
    seconds = 0;
}

Time::Time(int h, int s){
    setHours(h);
    minutes = 0;
    setSeconds(s);
}

Time::Time(int m, int s) {
    hours = 0;
    setMinutes(m);
    setSeconds(s);
}

Time::Time(int h){
    setHours(h);
    minutes = 0;
    seconds = 0;
}

Time::Time(int m){
    hours = 0;
    setMinutes(m);
    seconds = 0;
}

Time::Time(int s){
    hours = 0;
    minutes = 0;
    setSeconds(s);
}
//---------------------GETTERS--------------------


int Time::getHours() {
    return hours;

}
int Time::getMinutes(){
    return minutes;

}
int Time::getSeconds(){
    return seconds;

}

//------------------------------------------------
