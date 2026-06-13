CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o Video.o Movie.o Series.o Season.o Episode.o Rating.o InvalidRatingException.o EmptyFieldException.o InvalidNumberException.o DivideByZeroException.o
	$(CXX) $(CXXFLAGS) -o main main.o Video.o Movie.o Series.o Season.o Episode.o Rating.o InvalidRatingException.o EmptyFieldException.o InvalidNumberException.o DivideByZeroException.o

main.o: main.cpp Libraries/Movie/Movie.hpp Libraries/Series/Series.hpp Exception/InvalidRatingException/InvalidRatingException.hpp Exception/EmptyFieldException/EmptyFieldException.hpp Exception/InvalidNumberException/InvalidNumberException.hpp Exception/DivideByZeroException/DivideByZeroException.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Video.o: Libraries/Video/Video.cpp Libraries/Video/Video.hpp Libraries/Rating/Rating.hpp Exception/EmptyFieldException/EmptyFieldException.hpp Exception/InvalidNumberException/InvalidNumberException.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Video/Video.cpp

Rating.o: Libraries/Rating/Rating.cpp Libraries/Rating/Rating.hpp Exception/InvalidRatingException/InvalidRatingException.hpp Exception/DivideByZeroException/DivideByZeroException.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Rating/Rating.cpp

Movie.o: Libraries/Movie/Movie.cpp Libraries/Movie/Movie.hpp Libraries/Video/Video.hpp Exception/DivideByZeroException/DivideByZeroException.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Movie/Movie.cpp

Series.o: Libraries/Series/Series.cpp Libraries/Series/Series.hpp Libraries/Video/Video.hpp Libraries/Season/Season.hpp Libraries/Episode/Episode.hpp Exception/DivideByZeroException/DivideByZeroException.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Series/Series.cpp

Season.o: Libraries/Season/Season.cpp Libraries/Season/Season.hpp Libraries/Episode/Episode.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Season/Season.cpp

Episode.o: Libraries/Episode/Episode.cpp Libraries/Episode/Episode.hpp Libraries/Video/Video.hpp Exception/DivideByZeroException/DivideByZeroException.hpp
	$(CXX) $(CXXFLAGS) -c Libraries/Episode/Episode.cpp

InvalidRatingException.o: Exception/InvalidRatingException/InvalidRatingException.cpp Exception/InvalidRatingException/InvalidRatingException.hpp
	$(CXX) $(CXXFLAGS) -c Exception/InvalidRatingException/InvalidRatingException.cpp

EmptyFieldException.o: Exception/EmptyFieldException/EmptyFieldException.cpp Exception/EmptyFieldException/EmptyFieldException.hpp
	$(CXX) $(CXXFLAGS) -c Exception/EmptyFieldException/EmptyFieldException.cpp

InvalidNumberException.o: Exception/InvalidNumberException/InvalidNumberException.cpp Exception/InvalidNumberException/InvalidNumberException.hpp
	$(CXX) $(CXXFLAGS) -c Exception/InvalidNumberException/InvalidNumberException.cpp

DivideByZeroException.o: Exception/DivideByZeroException/DivideByZeroException.cpp Exception/DivideByZeroException/DivideByZeroException.hpp
	$(CXX) $(CXXFLAGS) -c Exception/DivideByZeroException/DivideByZeroException.cpp

clean:
	rm -f *.o main
