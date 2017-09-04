
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o State.o
SRCS = Main.cpp State.cpp
HEADERS = State.hpp

#target: dependencies
#	rule to build
#

modE: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o modE

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o modE