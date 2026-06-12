#include "video.h"
#include <iostream>
using namespace std;


//------GETTERS-------
double Video::GetRating(){
    return rate.GetRating();
}

string Video::GetName(){
    return name;
}
int Video::GetId(){
    return id;
}

//------SETTERS-------
void Video::SetRating(double r){
    rate.Rate(r);
}
void Video::SetId(int id){
    this->id = id;
}
void Video::SetName(std::string n){
    name = n;
}