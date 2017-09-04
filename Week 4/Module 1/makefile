
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Menu.o Utility.o Recur.o

SRCS = Main.cpp Menu.cpp Utility.cpp Recur.cpp

HEADERS = Menu.hpp Utility.hpp Recur.hpp

#target: dependencies
#	rule to build
#

mod1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o mod1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o mod1