#                                               -*- Autoconf -*-
# $Id: configure.ac 4 2012-08-24 02:28:17Z mike $
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([sconvert], [2.0], [mpfauth@hiwaay.net])
AM_INIT_AUTOMAKE
LT_PREREQ([2.2])
LT_INIT([dlopen])
AC_CONFIG_SRCDIR([src/eci_ecr.hpp])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_FILES([Makefile src/Makefile lib/Makefile data/Makefile doc/Makefile])
# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/timeb.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([sqrt])

AC_OUTPUT

echo \
"-----------------------------------------

${PACKAGE_NAME} Version ${PACKAGE_VERSION}

Prefix:        ${prefix}
C++ Compiler:  '${CXX} ${CXXFLAGS} ${CPPFLAGS}'
C Compiler:    '${CC} ${CFLAGS} ${CPPFLAGS}'

-----------------------------------------"
