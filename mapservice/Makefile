TARGET=libmapsearch.so.1.0
SRC= *.cpp
OBJ=*.o
GCC = g++
FLAGS=-ggdb -DHAVE_NETINET_IN_H
INCLUDE=-I. -I../lib/gen-cpp/ -I/usr/local/include/thrift/ -I/usr/include/netinet
LIBDIR=
OPT=-DHAVE_NETINET_IN_H
LIBS=-lthrift

default: create-lib 

create-exe:
	$(GCC) -ggdb $(FLAGS) $(INCLUDE) $(LIBDIR) $(OPT) $(SRC) $(LIBS) -o $(TARGET)  

compile:
	$(GCC) $(FLAGS) -fPIC -g -c $(INCLUDE) $(SRC)
create-lib: clean compile
	$(GCC) -shared -Wl,-soname,libmapsearch.so.1 -o $(TARGET) $(OBJ)
	ln -s $(TARGET) libmapsearch.so
	ln -s $(TARGET) libmapsearch.so.1

clean:
	rm  *.so* $(OBJ) || true
