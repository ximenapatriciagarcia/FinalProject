#include "Episode.hpp"
#include "../../Exception/DivideByZeroException/DivideByZeroException.hpp"
#include <iostream>
using namespace std;

Episode::Episode(const string& id, const string& title, int length, const string& genre)
    : Video(id, title, length, genre) {}

void Episode::show() const {
    cout << "    [Episode] " << name << " | Length: " << length << " min | Rating: ";
    try {
        cout << getAverageRating();
    } catch (DivideByZeroException& e) {
        cout << "Not rated";
    }
    cout << endl;
}
