
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Critter.o Grid.o

SRCS = Main.cpp Critter.cpp Grid.cpp

HEADERS = Critter.hpp Grid.hpp

#target: dependencies
#	rule to build
#

modB: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o modB 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o modB