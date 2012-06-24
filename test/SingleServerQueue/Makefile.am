# Name: test/SingleServerQueue/Makefile.am
# Author: Khedesh
# Create at: 06/24/2012, 8:05 AM

bin_PROGRAMS = SingleServerQueue

SingleServerQueue_LINK = $(CXX) -o $@

SingleServerQueue_SOURCES = customer.cpp \
customer_queue.cpp \
server.cpp \
main.cpp

SingleServerQueue_LDADD = @top_srcdir@/src/libKhagine.a

AM_CFLAGS = -I@top_srcdir@/include \
	-L@top_srcdir@/src

