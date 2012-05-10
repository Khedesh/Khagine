# Name: Makefile
# Author: Khedesh
# At: 01/27/2012, 11:25 PM
# Description: makes the source files to objs and gets lib.

# variables

TOPDIR = ..
SRC_DIR = .
INCLUDE_DIR = $(TOPDIR)/include
BUILD_DIR = $(TOPDIR)/build

CXX = g++
CFLAGS = -g -Wall -O2 -pipe -I$(INCLUDE_DIR)

SRCS = logger.cpp entity.cpp event.cpp event_queue.cpp khagine.cpp clock.cpp normal_distribution.cpp exp_distribution.cpp
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))
LIBNAME = khagine
TARGET = $(BUILD_DIR)/lib$(LIBNAME).a

AR = ar cru
RANLIB = ranlib

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(TARGET) $(OBJS)
	$(RANLIB) $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
