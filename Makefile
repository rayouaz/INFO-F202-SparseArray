
FLAGS= -std=c++14 -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

CXX = g++
MAIN= main.cpp
OUT= main.out

all: $(OUT)

$(OUT): BalancedArray.hpp Array.hpp  Abr.hpp Node.hpp $(MAIN)
	$(CXX) $(FLAGS) $(MAIN) -g -o  $(OUT)

.PHONY : clean

clean:
	rm *.o *.out;
