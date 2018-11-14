
#######################
# Makefile
#######################
# source object target
SOURCE := main.cpp 
OBJS   := libdemo.so 
TARGET := main

# compile and lib parameter
CC      := g++
LIBS    :=-lzookeeper_mt -lzookeeper_st
LDFLAGS := -L/usr/local/lib
DEFINES :=
INCLUDE := -I/usr/local/include/zookeeper/ -I./include/
CFLAGS  := 
CXXFLAGS:= 

all:clean link 
	$(CC) -g -o  $(TARGET) main.cpp  -ldl  -lpthread
link:
	$(CC) -shared -fpic -g -o  $(OBJS) ./src/czookeeper.cpp libdemo.cpp $(INCLUDE) $(LIBS)
clean:
	rm -fr main
	rm -fr libdemo.so