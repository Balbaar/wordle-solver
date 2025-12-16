CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic-errors

########
# main #
########

all: wordle_solver

wordle_solver: bin/wordle_solver
	./bin/wordle_solver

bin/wordle_solver: build/main.o build/filter.o build/candidates.o build/input.o build/predicates.o
	mkdir -p bin
	$(CXX) $(CXXFLAGS) \
		build/main.o \
		build/filter.o \
		build/candidates.o \
		build/input.o \
		build/predicates.o \
		-o bin/wordle_solver




#########
# tests #
#########
test: build/test_predicates
	./build/test_predicates



build/test_predicates: tests/test_predicates.cc build/predicates.o
	mkdir -p bin
	$(CXX) $(CXXFLAGS) tests/test_predicates.cc build/predicates.o -o build/test_predicates


##############
# Components #
##############

build/main.o: src/main.cc build/filter.o build/candidates.o build/input.o
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/main.cc -o build/main.o

build/predicates.o: src/predicates.cc
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/predicates.cc -o build/predicates.o

build/candidates.o: src/candidates.cc
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/candidates.cc -o build/candidates.o

build/filter.o: src/filter.cc build/predicates.o
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/filter.cc -o build/filter.o

build/input.o: src/input.cc build/predicates.o
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/input.cc -o build/input.o


clean:
	rm -f build/*.o bin/*