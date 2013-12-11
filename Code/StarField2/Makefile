CFLAGS = -O2 -Wall -Wextra -ansi -pedantic
LIBS =  -limages -ldnest3 -lgsl -lgslcblas -lboost_system -lboost_thread

default:
	g++ $(CFLAGS) -c *.cpp
	g++ -L .. -o main *.o $(LIBS)
	rm -f *.o

