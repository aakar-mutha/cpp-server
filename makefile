# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The source files
SRCS = ./networking/sockets/createSocket.cpp \
       ./networking/sockets/bindingSocket.cpp \
       ./networking/sockets/listeningSocket.cpp \
	   ./networking/server/createServer.cpp \
	   ./server.cpp \
	   ./startServer.cpp

# The object files
OBJS = $(SRCS:.cpp=.o)

# The build target 
TARGET = serve

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(TARGET)
