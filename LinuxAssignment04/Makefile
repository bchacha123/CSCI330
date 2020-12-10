CXX=g++
CXXFLAGS=-g -Wall

main : assignment04.o funtions.o assignment04h.o
	$(CXX) $(CXXFLAGS) -o main assignment04.o funtions.o assignment04h.o

assignment04.o : assignment04.cpp
	$(CXX) $(CXXFLAGS) -c assignment04.cpp -o assignment04.o

funtions.o : funtions.cpp
	$(CXX) $(CXXFLAGS) -c funtions.cpp -o funtions.o

assignment04h.o : assignment04h.h
	$(CXX) $(CXXFLAGS) -c assignment04h.h -o assignment04h.o



