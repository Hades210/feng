AC_DEFUN([LSC_CHECK_SCTP], [
  have_sctp=no

  AC_ARG_ENABLE(sctp,
    AS_HELP_STRING([--enable-sctp], [enable SCTP support [[default=yes]]]),,
	enable_sctp="yes")

  AC_MSG_CHECKING([whether to enable SCTP support])  
  AS_IF([test "x$enable_sctp" = "xyes"], [
    AC_MSG_RESULT([yes, checking prerequisites])
    
    AC_CHECK_TYPE([struct sctp_sndrcvinfo], [
        AC_CHECK_LIB(sctp,sctp_recvmsg, [
          SCTP_LIBS="-lsctp"
	  have_sctp=yes
	  AC_DEFINE([HAVE_LIBSCTP], [1], [Define this if you have libsctp])
	])],
      AC_MSG_WARN([SCTP disabled: headers not found]),
      [#include <netinet/sctp.h>
      ])
  ], [
    AC_MSG_RESULT([no, disabled by user])
  ])

  AC_SUBST([SCTP_LIBS])

  AM_CONDITIONAL([HAVE_SCTP], [test "x$have_sctp" = "xyes"])
])