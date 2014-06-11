GCCox=/usr/bin/g++ -std=c++0x
GCC=/usr/bin/g++
SRC= gen-cpp/*.cpp 
OBJ=*.o
INCLUDE=-I./gen-cpp/ -I/usr/local/include/thrift/ -I/usr/include/netinet
FLAGS=-DHAVE_NETINET_IN_H -ggdb
TARGET=libthriftAround7.so.1.0

default: all

generate:
	thrift --gen cpp MapService.thrift

compile:
	$(GCC) $(FLAGS) -fPIC -g -c $(INCLUDE) $(SRC)


all: clean generate compile 
	$(GCC) -shared -Wl,-soname,libthriftAround7.so.1 -o $(TARGET) $(OBJ)
	ln -s $(TARGET) libthriftAround7.so
	ln -s $(TARGET) libthriftAround7.so.1

clean:
	rm  *.so* $(OBJ) || true
