mainClass: TimeInterval.o main.o
	g++ TimeInterval.o main.o -o mainClass
TimeInterval.o: TimeInterval.cpp TimeInterval.h
	g++ -c TimeInterval.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o
	rm mainClass
run: mainClass
	./mainClass
