#ifndef RATING_H
#define RATING_H
#include <vector>



class Rating {
    private:
    std::vector<int> rates;
    float rating;
    void CalculateAverageRating(int r);
    public:
    Rating();
    float GetRating();
    float Rate(int r);
    void SetRate(float r);

};
#endif