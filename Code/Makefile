CFLAGS = -O2 -fPIC -Wall -Wextra -ansi -pedantic
LIBS =  -ldnest3 -lgsl -lgslcblas -lboost_system -lboost_thread

default:
	# Build the library
	g++ $(CFLAGS) -c PSFs/*.cpp
	g++ -shared -o libimages.so *.o
	rm -f *.o

	# Build the subprojects
	cd StarField2; make

