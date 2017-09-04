
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Menu.o Stack.o Queue.o
SRCS = Main.cpp Menu.cpp Stack.cpp Queue.cpp
HEADERS = Menu.cpp Stack.hpp Queue.hpp

#target: dependencies
#	rule to build
#

mod2: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o mod2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o mod2