CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o Video.o Movie.o Series.o Episode.o InvalidRatingException.o
	$(CXX) $(CXXFLAGS) -o main main.o Video.o Movie.o Series.o Episode.o InvalidRatingException.o

main.o: main.cpp Movie.hpp Series.hpp InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Video.o: Video.cpp Video.hpp
	$(CXX) $(CXXFLAGS) -c Video.cpp

Movie.o: Movie.cpp Movie.hpp Video.hpp
	$(CXX) $(CXXFLAGS) -c Movie.cpp

Series.o: Series.cpp Series.hpp Video.hpp Episode.hpp
	$(CXX) $(CXXFLAGS) -c Series.cpp

Episode.o: Episode.cpp Episode.hpp InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c Episode.cpp

InvalidRatingException.o: InvalidRatingException.cpp InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c InvalidRatingException.cpp

clean:
	rm -f *.o main