
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Critter.o Ant.o Doodlebug.o Grid.o
SRCS = Main.cpp Critter.cpp Ant.cpp Doodlebug.cpp Grid.cpp
HEADERS = Critter.hpp Ant.hpp Doodlebug.hpp Grid.hpp

#target: dependencies
#	rule to build
#

modD: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o modD

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o modD