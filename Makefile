CXX = g++
EXEC_HTTP = server_http

SOURCE_HTTP = main_http.cpp
OBJECTS_HTTP = main_http.o

#开启编译器O3优化 ，pthread启动多线程支持
LDFLAGS_COMMON = -std=c++11 -O3 -pthread -lboost_system
LDFLAGS_HTTP = 

LPATH_COMMON = -I/usr/local/boost_1_64_0
LPATH_HTTP = 

LLIB_COMMON = -L/usr/local/boost_1_64_0/stage/lib
LLIB_HTTP = 

http:
	$(CXX) $(SOURCE_HTTP) $(LDFLAGS_COMMON) $(LDFLAGS_HTTP) $(LPATH_COMMON) $(LPATH_HTTP) $(LLIB_COMMON) $(LLIB_HTTP) -o $(EXEC_HTTP)
clear:
	rm -f $(EXEC_HTTP) *.o
