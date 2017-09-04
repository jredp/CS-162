
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Menu.o Ant.o Grid.o

SRCS = Main.cpp Menu.cpp Ant.cpp Grid.cpp

HEADERS = Menu.hpp Ant.hpp Grid.hpp

#target: dependencies
#	rule to build
#

assgn1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o assgn1 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o