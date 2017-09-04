
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Menu.o Item.o List.o

SRCS = Main.cpp Menu.cpp Item.cpp List.cpp

HEADERS = Menu.hpp Item.hpp List.hpp

#target: dependencies
#	rule to build
#

assgn2: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o assgn2 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o assgn2