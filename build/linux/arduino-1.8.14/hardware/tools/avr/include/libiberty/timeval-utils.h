/* Basic struct timeval utilities.
   Copyright (C) 2011-2015 Free Software Foundation, Inc.

This file is part of the libiberty library.
Libiberty is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

Libiberty is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with libiberty; see the file COPYING.LIB.  If not,
write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
Boston, MA 02110-1301, USA.  */

#ifndef TIMEVAL_UTILS_H
#define TIMEVAL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* forward decl */
struct timeval;

extern void timeval_add (struct timeval *result,
			 const struct timeval *a, const struct timeval *b);

extern void timeval_sub (struct timeval *result,
			 const struct timeval *a, const struct timeval *b);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TIMEVAL_UTILS_H */
