#include "rating.hpp"
#include <iostream>
using namespace std;

Rating::Rating(){
    rates = {};
    rating = 0;
}

void Rating::CalculateAverageRating(int r){
    float sum_rates = 0;
    rates.push_back(r);
    for (int i = 0; i < rates.size(); i++){
        sum_rates += rates[i];
    }
    rating = (sum_rates/rates.size());
}

float Rating::Rate(int r){
    CalculateAverageRating(r);
    return rating;
}

float Rating::GetRating(){
    return rating;
}

void Rating::SetRate(float r){
    rating = r;
}