## Makefile.am for DirectFB/inputdrivers/hisi_linux_input

INCLUDES = \
	-I$(top_builddir)/include	\
	-I$(top_builddir)/lib	\
	-I$(top_srcdir)/include	\
	-I$(top_srcdir)/lib	\
	-I$(top_srcdir)/src	\
	-I$(top_srcdir)/systems

linux_input_LTLIBRARIES = libdirectfb_hisi_linux_input.la

if BUILD_STATIC
linux_input_DATA = $(linux_input_LTLIBRARIES:.la=.o)
endif

linux_inputdir = $(MODULEDIR)/inputdrivers

libdirectfb_hisi_linux_input_la_SOURCES = \
	input_fake.h		\
	linux_input.c

libdirectfb_hisi_linux_input_la_LDFLAGS = \
	-module			\
	-avoid-version		\
	$(DFB_LDFLAGS)

libdirectfb_hisi_linux_input_la_LIBADD = \
	$(top_builddir)/lib/direct/libdirect.la \
	$(top_builddir)/src/libdirectfb.la


include $(top_srcdir)/rules/libobject.make

