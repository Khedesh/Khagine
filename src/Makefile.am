# Name: src/Makefile.am
# Author: Khedesh
# Created at: 06/24/2012, 7:59 AM

instdir = /usr/local/lib
inst_LIBRARIES = libKhagine.a


libKhaginedir = /usr/local/include/Khagine
libKhagine_HEADERS = @top_srcdir@/include/clock.h \
@top_srcdir@/include/config.h \
@top_srcdir@/include/distribution.h \
@top_srcdir@/include/entity.h \
@top_srcdir@/include/event.h \
@top_srcdir@/include/event_queue.h \
@top_srcdir@/include/exp_distribution.h \
@top_srcdir@/include/khagine.h \
@top_srcdir@/include/logger.h \
@top_srcdir@/include/normal_distribution.h \
@top_srcdir@/include/Khagine.hpp

libKhagine_a_SOURCES = clock.cpp \
entity.cpp \
event.cpp \
event_queue.cpp \
exp_distribution.cpp \
khagine.cpp \
logger.cpp \
normal_distribution.cpp

AM_CFLAGS = -I@top_srcdir@/include
