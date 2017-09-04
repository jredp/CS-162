
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Critter.o Grid.o Ant.o

SRCS = Main.cpp Critter.cpp Grid.cpp Ant.cpp

HEADERS = Critter.hpp Grid.hpp Ant.hpp

#target: dependencies
#	rule to build
#

modC: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o modC

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o modC