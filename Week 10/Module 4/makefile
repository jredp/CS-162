
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Fib.o

SRCS = Main.cpp Fib.cpp

HEADERS = Fib.hpp

#target: dependencies
#	rule to build
#

mod4: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o mod4 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o 
	rm mod4
