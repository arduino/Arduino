/* Copyright (c) 2002,2007 Marek Michalkiewicz
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id$ */

#ifndef __ERRNO_H_
#define __ERRNO_H_ 1

/** \file */
/** \defgroup avr_errno <errno.h>: System Errors

    \code #include <errno.h>\endcode

    Some functions in the library set the global variable \c errno when an
    error occurs. The file, \c <errno.h>, provides symbolic names for various
    error codes. 
 */

#ifdef __cplusplus
extern "C" {
#endif

/** \ingroup avr_errno
    \brief Error code for last error encountered by library

    The variable \c errno holds the last error code encountered by
    a library function.  This variable must be cleared by the
    user prior to calling a library function.

    \warning The \c errno global variable is not safe to use in a threaded or
    multi-task system. A race condition can occur if a task is interrupted
    between the call which sets \c error and when the task examines \c
    errno. If another task changes \c errno during this time, the result will
    be incorrect for the interrupted task. */
extern int errno;

#ifdef __cplusplus
}
#endif

/** \ingroup avr_errno
    \def EDOM

    Domain error. */
#define EDOM       33

/** \ingroup avr_errno
    \def ERANGE

    Range error. */
#define ERANGE     34

#ifndef __DOXYGEN__

/* ((((('E'-64)*26+('N'-64))*26+('O'-64))*26+('S'-64))*26+('Y'-64))*26+'S'-64 */
#define ENOSYS ((int)(66081697 & 0x7fff))

/* (((('E'-64)*26+('I'-64))*26+('N'-64))*26+('T'-64))*26+('R'-64) */
#define EINTR ((int)(2453066 & 0x7fff))

#define E2BIG ENOERR
#define EACCES ENOERR
#define EADDRINUSE ENOERR
#define EADDRNOTAVAIL ENOERR
#define EAFNOSUPPORT ENOERR
#define EAGAIN ENOERR
#define EALREADY ENOERR
#define EBADF ENOERR
#define EBUSY ENOERR
#define ECHILD ENOERR
#define ECONNABORTED ENOERR
#define ECONNREFUSED ENOERR
#define ECONNRESET ENOERR
#define EDEADLK ENOERR
#define EDESTADDRREQ ENOERR
#define EEXIST ENOERR
#define EFAULT ENOERR
#define EFBIG ENOERR
#define EHOSTUNREACH ENOERR
#define EILSEQ ENOERR
#define EINPROGRESS ENOERR
#define EINVAL ENOERR
#define EIO ENOERR
#define EISCONN ENOERR
#define EISDIR ENOERR
#define ELOOP ENOERR
#define EMFILE ENOERR
#define EMLINK ENOERR
#define EMSGSIZE ENOERR
#define ENAMETOOLONG ENOERR
#define ENETDOWN ENOERR
#define ENETRESET ENOERR
#define ENETUNREACH ENOERR
#define ENFILE ENOERR
#define ENOBUFS ENOERR
#define ENODEV ENOERR
#define ENOENT ENOERR
#define ENOEXEC ENOERR
#define ENOLCK ENOERR
#define ENOMEM ENOERR
#define ENOMSG ENOERR
#define ENOPROTOOPT ENOERR
#define ENOSPC ENOERR
#define ENOTCONN ENOERR
#define ENOTDIR ENOERR
#define ENOTEMPTY ENOERR
#define ENOTSOCK ENOERR
#define ENOTTY ENOERR
#define ENXIO ENOERR
#define EOPNOTSUPP ENOERR
#define EPERM ENOERR
#define EPIPE ENOERR
#define EPROTONOSUPPORT ENOERR
#define EPROTOTYPE ENOERR
#define EROFS ENOERR
#define ESPIPE ENOERR
#define ESRCH ENOERR
#define ETIMEDOUT ENOERR
#define EWOULDBLOCK ENOERR
#define EXDEV ENOERR

/* ((((('E'-64)*26+('N'-64))*26+('O'-64))*26+('E'-64))*26+('R'-64))*26+'R'-64 */
#define ENOERR ((int)(66072050 & 0xffff))

#endif	/* !__DOXYGEN__ */

#endif
