CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o Video.o Movie.o Series.o Season.o Episode.o InvalidRatingException.o
	$(CXX) $(CXXFLAGS) -o main main.o Video.o Movie.o Series.o Season.o Episode.o InvalidRatingException.o

main.o: main.cpp Libraries/Movie/Movie.hpp Libraries/Series/Series.hpp Exception/InvalidRatingException/InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Video.o: Libraries/Video/Video.cpp Libraries/Video/Video.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Video/Video.cpp

Movie.o: Libraries/Movie/Movie.cpp Libraries/Movie/Movie.hpp Libraries/Video/Video.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Movie/Movie.cpp

Series.o: Libraries/Series/Series.cpp Libraries/Series/Series.hpp Libraries/Video/Video.hpp Libraries/Season/Season.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Series/Series.cpp

Season.o: Libraries/Season/Season.cpp Libraries/Season/Season.hpp Libraries/Episode/Episode.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Season/Season.cpp

Episode.o: Libraries/Episode/Episode.cpp Libraries/Episode/Episode.hpp Libraries/Video/Video.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Episode/Episode.cpp

InvalidRatingException.o: Exception/InvalidRatingException/InvalidRatingException.cpp Exception/InvalidRatingException/InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c Exception/InvalidRatingException/InvalidRatingException.cpp

clean:
	rm -f *.o main
