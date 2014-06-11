TARGET=mapserver
SRC= *.cpp
GCC = g++
FLAGS=
INCLUDE=-I.  -I../lib/gen-cpp/ -I../mapservice -I/usr/local/include/thrift/ -I/usr/include/netinet
LIBDIR=-L../lib -L../mapservice
OPT=-DHAVE_NETINET_IN_H
LIBS= -lthrift -lthriftAround7 -lmapsearch

default: all

all:	
	$(GCC) -ggdb $(FLAGS) $(INCLUDE) $(LIBDIR) $(OPT) $(SRC) $(LIBS) -o $(TARGET)  

clean:
	rm -rf *.o $(TARGET)
