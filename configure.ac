AC_ARG_ENABLE([tests],
    [AS_HELP_STRING([--enable-tests], [Build and run unit tests])],
    [enable_tests=$enableval], [enable_tests=no])

if test "x$enable_tests" = "xyes"; then
    AC_SUBST([check_PROGRAMS], [test_FuncA])
else
    AC_SUBST([check_PROGRAMS], [])
fi