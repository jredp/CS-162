
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o State.o Queue.o
SRCS = Main.cpp State.cpp Queue.cpp
HEADERS = State.hpp Queue.hpp

#target: dependencies
#	rule to build
#

modF: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o modF

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o modF