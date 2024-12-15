AC_PREREQ([2.69])
AC_INIT([MyProject], [1.0], [your-email@example.com])
AM_INIT_AUTOMAKE([foreign])

AC_PROG_CXX

AC_CHECK_LIB([m], [pow], [], [AC_MSG_ERROR([Math library is required])])

AC_ARG_ENABLE([tests],
    [AS_HELP_STRING([--enable-tests], [Build and run unit tests])],
    [enable_tests=$enableval], [enable_tests=yes])

if test "x$enable_tests" = "xyes"; then
    AC_SUBST([check_PROGRAMS], [test_FuncA])
else
    AC_SUBST([check_PROGRAMS], [])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
