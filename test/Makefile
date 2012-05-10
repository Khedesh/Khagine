# Name: Makefile
# Author: Khedesh
# At: 01/27/2012, 11:46 PM
# Description: This file makes test executable file.

# variables

TOPDIR = ..
TEST_DIR = .
INCLUDE_DIR = $(TOPDIR)/include
BUILD_DIR = $(TOPDIR)/build

CXX = g++
CFLAGS = -g -Wall -O2 -pipe -I$(INCLUDE_DIR) -L$(BUILD_DIR)
LIBS = -l$(LIBNAME) -lm -lpthread 

SRCS = main.cpp customer.cpp server.cpp customer_queue.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
TARGET = test
LIBNAME = khagine

all: $(TARGET)

$(TARGET): $(SRCS) $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) $(LIBS) -o $(TARGET)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
