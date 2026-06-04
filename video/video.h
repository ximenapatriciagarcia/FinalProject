#ifndef VIDEO_H
#define VIDEO_H
#include "../lenght/Time.h"

#include <string>
class Video {

    public:
    //-------------GETTERS-------------
    virtual double getRating()=0;
    virtual int getID()=0;
    virtual std::string getName()=0;
    virtual Time getLength()=0;

    //------------SETTERS-------------
    virtual void setRating(double r) = 0;
    virtual void setID(int id) = 0;
    virtual void setName(std::string n) = 0;
    virtual void setLength(Time t) = 0;

    protected:
    
    int ID;
    Time length;
    double rating;
    std::string name;

    private:
};
#endif // VIDEO_H