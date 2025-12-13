CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic-errors


//run: main


test: test_predicates
	./test_predicates


test_predicates: tests/test_predicates.cc src/predicates.o
	$(CXX) $(CXXFLAGS) -o test_predicates tests/test_predicates.cc src/predicates.o





predicates.o: src/predicates.cc src/predicates.h
	$(CXX) $(CXXFLAGS) -c src/predicates.cc



clean:
	rm -f src/*.o src/*.o test_predicates