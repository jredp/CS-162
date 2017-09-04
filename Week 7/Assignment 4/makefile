
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Menu.o Creature.o Babayaga.o Barbarian.o Bluemen.o Medusa.o Harrypotter.o Team.o
SRCS = Main.cpp Menu.cpp Creature.cpp Babayaga.cpp Barbarian.cpp Bluemen.cpp Medusa.cpp Harrypotter.cpp Team.cpp
HEADERS = Menu.hpp Creature.hpp Babayaga.hpp Barbarian.hpp Bluemen.hpp Medusa.hpp Harrypotter.hpp Team.hpp

#target: dependencies
#	rule to build
#

asgn4: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o asgn4

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o asgn4