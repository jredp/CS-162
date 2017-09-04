
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = Main.o Afitch.o Borders.o Coffee.o Final.o Item.o Knapsack.o Map.o Menu.o Park.o Player.o Space.o Statue.o Street.o

SRCS = Main.cpp Afitch.cpp Borders.cpp Coffee.cpp Final.cpp Item.cpp Knapsack.cpp Map.cpp Menu.cpp Park.cpp Player.cpp Space.cpp Statue.cpp Street.cpp

HEADERS = Afitch.hpp Borders.hpp Coffee.hpp Final.hpp Item.hpp Knapsack.hpp Map.hpp Menu.hpp Park.hpp Player.hpp Space.hpp Statue.hpp Street.hpp

#target: dependencies
#	rule to build
#

final: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o final 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o 
	rm final
