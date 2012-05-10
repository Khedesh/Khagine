# Name: Makefile
# Author: Khedesh
# At: 01/27/2012, 11:25 PM
# Description: makes the source files to objs and gets lib.

# variables

TOPDIR = ..
SRC_DIR = .
INCLUDE_DIR = $(TOPDIR)/include
BUILD_DIR = $(TOPDIR)/build

INSTALL_DIR = /usr/local

CXX = g++
CFLAGS = -g -Wall -O2 -pipe -I$(INCLUDE_DIR)

CP = cp
RM = rm

SRCS = logger.cpp entity.cpp event.cpp event_queue.cpp khagine.cpp clock.cpp normal_distribution.cpp exp_distribution.cpp
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))
LIBNAME = khagine
TARGET = $(BUILD_DIR)/lib$(LIBNAME).a

AR = ar cru
RANLIB = ranlib

all: $(TARGET)

install: $(TARGET)
	$(CP) -f $(TARGET) $(INSTALL_DIR)/lib
	$(CP) -rf $(INCLUDE_DIR) $(INSTALL_DIR)/include/Khagine

uninstall:
	$(RM) -rf $(INSTALL_DIR)/lib/$(TARGET) $(INSTALL_DIR)/include/Khagine

$(TARGET): $(OBJS)
	$(AR) $(TARGET) $(OBJS)
	$(RANLIB) $(TARGET)

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
