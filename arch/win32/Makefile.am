# Process this file with automake to produce Makefile.in
#
# Copyright (C) 2001, 2002 Rob Caelers <robc@krandor.org>
#
# Time-stamp: <2002-10-06 18:12:32 pennersr>
#
# $Id$
#

MAINTAINERCLEANFILES = Makefile.in

SUBDIRS = harpoon

if HAVE_ARCH_WIN32

noinst_LIBRARIES = libarchwin32.a

libarchwin32_a_SOURCES = \
	gettimeofday.c \
	Thread.cc

libarchwin32_a_LIBADD =

endif

INCLUDES = -W -D_XOPEN_SOURCE=600 -I..

EXTRA_DIST = $(wildcard *.cc) $(wildcard *.c) $(wildcard *.hh) $(wildcard *.h) $(wildcard *.icc)
