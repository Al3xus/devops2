AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = myprogram
myprogram_SOURCES = main.cpp FuncA.cpp FuncA.h server.cpp

check_PROGRAMS = test_FuncA
test_FuncA_SOURCES = test_FuncA.cpp FuncA.cpp server.cpp
PACKAGE = myprogram
VERSION = 1.0
test_FuncA_LDADD = -lm

AM_CPPFLAGS = -I$(top_srcdir)

check: test_FuncA
	@./test_FuncA