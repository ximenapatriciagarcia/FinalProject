CXX = g++
INCLUDES = -Ilibs/video -Ilibs/movie -Ilibs/series -Ilibs/episode -Ilibs/exception
CXXFLAGS = -std=c++11 -Wall $(INCLUDES)

all: main

main: main.o Video.o Movie.o Series.o Episode.o InvalidRatingException.o
	$(CXX) $(CXXFLAGS) -o main main.o Video.o Movie.o Series.o Episode.o InvalidRatingException.o

main.o: main.cpp libs/movie/Movie.hpp libs/series/Series.hpp libs/exception/InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Video.o: libs/video/Video.cpp libs/video/Video.hpp
	$(CXX) $(CXXFLAGS) -c libs/video/Video.cpp

Movie.o: libs/movie/Movie.cpp libs/movie/Movie.hpp libs/video/Video.hpp
	$(CXX) $(CXXFLAGS) -c libs/movie/Movie.cpp

Series.o: libs/series/Series.cpp libs/series/Series.hpp libs/video/Video.hpp libs/episode/Episode.hpp
	$(CXX) $(CXXFLAGS) -c libs/series/Series.cpp

Episode.o: libs/episode/Episode.cpp libs/episode/Episode.hpp libs/exception/InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c libs/episode/Episode.cpp

InvalidRatingException.o: libs/exception/InvalidRatingException.cpp libs/exception/InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c libs/exception/InvalidRatingException.cpp

clean:
	rm -f *.o main
