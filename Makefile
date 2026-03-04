main: main.o averageScript/average.o
	g++ -o main main.o averageScript/average.o

main.o: main.cpp averageScript/average.h
	g++ -c main.cpp

average.o: averageScript/average.h averageScript/average.cpp
	g++ -c averageScript/average.cpp

clean:
	rm -f *.o main