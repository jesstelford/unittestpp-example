all: tests
 
# $@ matches the target; $< matches the first dependant
tests: main.o PhysObject.o
	g++ -o $@ $< -L"/usr/src/unittest-cpp/UnitTest++" -lUnitTest++

main.o: main.cpp
	g++ -c $<
     
PhysObject.o: PhysObject.h
	g++ -c $<
     
clean:
	rm main.o tests
