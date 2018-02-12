CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = ValidInt.o Menu.o UserInput.o reverseString.o sumArray.o triangularNumber.o
SRCS = recursives.cpp 

all: ValidInt Menu UserInput reverseString sumArray triangularNumber recursives 

ValidInt: ValidInt.hpp ValidInt.cpp
	${CXX} ${CXXFLAGS} ValidInt.cpp -c

Menu: ValidInt.hpp Menu.hpp ValidInt.cpp Menu.cpp
	${CXX} ${CXXFLAGS} ValidInt.cpp Menu.cpp -c

UserInput: UserInput.hpp UserInput.cpp
	${CXX} ${CXXFLAGS} UserInput.cpp -c

reverseString: reverseString.hpp reverseString.cpp
	${CXX} ${CXXFLAGS} reverseString.cpp -c

sumArray: sumArray.hpp sumArray.cpp
	${CXX} ${CXXFLAGS} sumArray.cpp -c

triangularNumber: triangularNumber.hpp triangularNumber.cpp
	${CXX} ${CXXFLAGS} triangularNumber.cpp -c

recursives: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} ${SRCS} -o recursives

val:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes ./recursives

clean:
	rm -f *.o recursives
