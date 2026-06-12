#ifndef VIDEO_H
#define VIDEO_H
#include "../Time/Time.h"
#include "../rating/rating.h"

#include <string>
class Video {

    public:
    //-------------GETTERS-------------
    double GetRating();
    int GetId();
    std::string GetName();
    virtual void ShowLength() = 0;

    //------------SETTERS-------------
    void SetRating(double r);
    void SetId(int id);
    void SetName(std::string n);
    virtual void SetLength(Time t) = 0;

    protected:
    int id;
    Rating rate;
    std::string name;
    private:
};
#endif // VIDEO_H