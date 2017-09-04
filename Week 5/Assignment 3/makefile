
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Menu.o Creature.o Babayaga.o Barbarian.o Bluemen.o Medusa.o Harrypotter.o
SRCS = Main.cpp Menu.cpp Creature.cpp Babayaga.cpp Barbarian.cpp Bluemen.cpp Medusa.cpp Harrypotter.cpp
HEADERS = Menu.hpp Creature.hpp Babayaga.hpp Barbarian.hpp Bluemen.hpp Medusa.hpp Harrypotter.hpp

#target: dependencies
#	rule to build
#

asgn3: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o asgn3

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o asgn3