TARGET=mapserver
SRC= *.cpp
GCC = g++
FLAGS=
INCLUDE=-I.  -I../lib/gen-cpp/ -I../mapservice -I/usr/local/include/thrift/ -I/usr/include/netinet
LIBDIR=-L../lib -L../mapservice
OPT=-DHAVE_NETINET_IN_H
LIBS= -lthrift -lthriftAround7 -lmapsearch

DIRS = lib mapservice server
subprojects:
	for sub in ${DIRS}; do \
		make -C $${sub} ;\
	done

default: all
all: subprojects	

debug:
	LD_LIBRARY_PATH=./lib/:./mapservice/ gdb --args ./server/mapserver ./mapservice/strips-data
run:
	LD_LIBRARY_PATH=./lib/:./mapservice/ ./server/mapserver ./mapservice/strips-data
