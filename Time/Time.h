#ifndef TIME_H
#define TIME_H
class Time{
    private:
    int hours;
    int minutes;
    int seconds;
    bool isValidHour(int h);
    bool isValidMinute(int m);
    bool isValidSecond(int s);

    public:
    Time();
    Time(int h);
    Time(int h, int m);
    Time(int m, int s);
    Time(int h, int m, int s);
    //Display
    void showTime();
    //Getters
    int getHours();
    int getMinutes();
    int getSeconds();
    //Setters
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);

};
#endif