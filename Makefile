
CXX = g++
TARGET = libdemo.so
#g++ -shared -fpic -o libdemo.so libdemo.cpp
all:
	$(CXX) -shared -fpic -o $(TARGET) libdemo.cpp
	$(CXX) -o main main.cpp -ldl