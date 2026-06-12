#include "rating.h"
using namespace std;
#include <iostream>

Rating::Rating(){
    rates = {};
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
    cout << "Please enter your rating in a scale from 0 - 5 (Just Integers)";
    CalculateAverageRating(r);
    cout << "The new rating is: " << rating;

}
float Rating::GetRating(){
    return rating;
}