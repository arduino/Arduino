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

/*
   string.h

   Contributors:
     Created by Marek Michalkiewicz <marekm@linux.org.pl>
 */

#ifndef	_STRING_H_
#define	_STRING_H_ 1

#ifndef __DOXYGEN__
#define	__need_NULL
#define	__need_size_t
#include <stddef.h>

#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif

#ifndef __ATTR_CONST__
# define __ATTR_CONST__	__attribute__((__const__))
#endif
#endif	/* !__DOXYGEN__ */

#ifdef __cplusplus
extern "C" {
#endif

/** \file */
/** \defgroup avr_string <string.h>: Strings
    \code #include <string.h> \endcode

    The string functions perform string operations on NULL terminated
    strings. 

    \note If the strings you are working on resident in program space (flash),
    you will need to use the string functions described in \ref avr_pgmspace. */


/** \ingroup avr_string

    This macro finds the first (least significant) bit set in the
    input value.

    This macro is very similar to the function ffs() except that
    it evaluates its argument at compile-time, so it should only
    be applied to compile-time constant expressions where it will
    reduce to a constant itself.
    Application of this macro to expressions that are not constant
    at compile-time is not recommended, and might result in a huge
    amount of code generated.

    \returns The _FFS() macro returns the position of the first
    (least significant) bit set in the word val, or 0 if no bits are set.
    The least significant bit is position 1.  Only 16 bits of argument
    are evaluted.
*/
#if defined(__DOXYGEN__)
#define _FFS(x)
#else  /* !DOXYGEN */
#define	_FFS(x) \
	(1				\
	 + (((x) & 1) == 0)		\
	 + (((x) & 3) == 0)		\
	 + (((x) & 7) == 0)		\
	 + (((x) & 017) == 0)		\
	 + (((x) & 037) == 0)		\
	 + (((x) & 077) == 0)		\
	 + (((x) & 0177) == 0)		\
	 + (((x) & 0377) == 0)		\
	 + (((x) & 0777) == 0)		\
	 + (((x) & 01777) == 0)		\
	 + (((x) & 03777) == 0)		\
	 + (((x) & 07777) == 0) 	\
	 + (((x) & 017777) == 0)	\
	 + (((x) & 037777) == 0)	\
	 + (((x) & 077777) == 0)	\
	 - (((x) & 0177777) == 0) * 16)
#endif /* DOXYGEN */

/** \ingroup avr_string
    \fn int ffs(int val);

    \brief This function finds the first (least significant) bit set in the input value.

    \returns The ffs() function returns the position of the first
    (least significant) bit set in the word val, or 0 if no bits are set.
    The least significant bit is position 1.

    \note For expressions that are constant at compile time, consider
    using the \ref _FFS macro instead.
*/
extern int ffs(int __val) __ATTR_CONST__;

/** \ingroup avr_string
    \fn int ffsl(long val);

    \brief Same as ffs(), for an argument of type long. */
extern int ffsl(long __val) __ATTR_CONST__;

/** \ingroup avr_string
    \fn int ffsll(long long val);

    \brief Same as ffs(), for an argument of type long long. */
__extension__ extern int ffsll(long long __val) __ATTR_CONST__;

/** \ingroup avr_string
    \fn void *memccpy(void *dest, const void *src, int val, size_t len)
    \brief Copy memory area.

    The memccpy() function copies no more than \p len bytes from memory
    area \p src to memory area \p dest, stopping when the character \p val
    is found.

    \returns The memccpy() function returns a pointer to the next character
    in \p dest after \p val, or NULL if \p val was not found in the first
    \p len characters of \p src. */
extern void *memccpy(void *, const void *, int, size_t);

/** \ingroup avr_string
    \fn void *memchr(const void *src, int val, size_t len)
    \brief Scan memory for a character.

    The memchr() function scans the first len bytes of the memory area pointed
    to by src for the character val.  The first byte to match val (interpreted
    as an unsigned character) stops the operation.

    \returns The memchr() function returns a pointer to the matching byte or
    NULL if the character does not occur in the given memory area.  */
extern void *memchr(const void *, int, size_t) __ATTR_PURE__;

/** \ingroup avr_string
    \fn int memcmp(const void *s1, const void *s2, size_t len)
    \brief Compare memory areas

    The memcmp() function compares the first len bytes of the memory areas s1
    and s2. The comparision is performed using unsigned char operations.

    \returns The memcmp() function returns an integer less than, equal to, or
    greater than zero if the first len bytes of s1 is found, respectively, to be
    less than, to match, or be greater than the first len bytes of s2.

    \note Be sure to store the result in a 16 bit variable since you may get
    incorrect results if you use an unsigned char or char due to truncation.

    \warning This function is not -mint8 compatible, although if you only care
    about testing for equality, this function should be safe to use. */
extern int memcmp(const void *, const void *, size_t) __ATTR_PURE__;

/** \ingroup avr_string
    \fn void *memcpy(void *dest, const void *src, size_t len)
    \brief Copy a memory area.

    The memcpy() function copies len bytes from memory area src to memory area
    dest.  The memory areas may not overlap.  Use memmove() if the memory
    areas do overlap.

    \returns The memcpy() function returns a pointer to dest.  */
extern void *memcpy(void *, const void *, size_t);

/** \ingroup avr_string
    \fn void *memmem(const void *s1, size_t len1, const void *s2, size_t len2)

    The memmem() function finds the start of the first occurrence of the
    substring \p s2 of length \p len2 in the memory area \p s1 of length
    \p len1.

    \return The memmem() function returns a pointer to the beginning of
    the substring, or \c NULL if the substring is not found. If \p len2
    is zero, the function returns \p s1. */
extern void *memmem(const void *, size_t, const void *, size_t) __ATTR_PURE__;

/** \ingroup avr_string
    \fn void *memmove(void *dest, const void *src, size_t len)
    \brief Copy memory area.

    The memmove() function copies len bytes from memory area src to memory area
    dest.  The memory areas may overlap.

    \returns The memmove() function returns a pointer to dest.  */
extern void *memmove(void *, const void *, size_t);

/** \ingroup avr_string
    \fn void *memrchr(const void *src, int val, size_t len)

    The memrchr() function is like the memchr() function, except that it
    searches backwards from the end of the \p len bytes pointed to by \p
    src instead of forwards from the front. (Glibc, GNU extension.)

    \return The memrchr() function returns a pointer to the matching
    byte or \c NULL if the character does not occur in the given memory
    area. */
extern void *memrchr(const void *, int, size_t) __ATTR_PURE__;

/** \ingroup avr_string
    \fn void *memset(void *dest, int val, size_t len)
    \brief Fill memory with a constant byte.

    The memset() function fills the first len bytes of the memory area pointed
    to by dest with the constant byte val.

    \returns The memset() function returns a pointer to the memory area dest. */
extern void *memset(void *, int, size_t);

/** \ingroup avr_string
    \fn char *strcat(char *dest, const char *src)
    \brief Concatenate two strings.

    The strcat() function appends the src string to the dest string
    overwriting the '\\0' character at the end of dest, and then adds a
    terminating '\\0' character.  The strings may not overlap, and the dest
    string must have enough space for the result.

    \returns The strcat() function returns a pointer to the resulting string
    dest.  */
extern char *strcat(char *, const char *);

/** \ingroup avr_string
    \fn char *strchr(const char *src, int val)
    \brief Locate character in string.

    The strchr() function returns a pointer to the first occurrence of
    the character \p val in the string \p src.

    Here "character" means "byte" - these functions do not work with
    wide or multi-byte characters.

    \returns The strchr() function returns a pointer to the matched
    character or \c NULL if the character is not found. */
extern char *strchr(const char *, int) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strchrnul(const char *s, int c)

    The strchrnul() function is like strchr() except that if \p c is not
    found in \p s, then it returns a pointer to the null byte at the end
    of \p s, rather than \c NULL. (Glibc, GNU extension.)

    \return The strchrnul() function returns a pointer to the matched
    character, or a pointer to the null byte at the end of \p s (i.e.,
    \c s+strlen(s)) if the character is not found.	*/
extern char *strchrnul(const char *, int) __ATTR_PURE__;

/** \ingroup avr_string
    \fn int strcmp(const char *s1, const char *s2)
    \brief Compare two strings.

    The strcmp() function compares the two strings \p s1 and \p s2.

    \returns The strcmp() function returns an integer less than, equal
    to, or greater than zero if \p s1 is found, respectively, to be less
    than, to match, or be greater than \p s2. A consequence of the
    ordering used by strcmp() is that if \p s1 is an initial substring
    of \p s2, then \p s1 is considered to be "less than" \p s2.	*/
extern int strcmp(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strcpy(char *dest, const char *src)
    \brief Copy a string.

    The strcpy() function copies the string pointed to by src (including the
    terminating '\\0' character) to the array pointed to by dest.  The strings
    may not overlap, and the destination string dest must be large enough to
    receive the copy.

    \returns The strcpy() function returns a pointer to the destination
    string dest.

    \note If the destination string of a strcpy() is not large enough (that
    is, if the programmer was stupid/lazy, and failed to check the size before
    copying) then anything might happen.  Overflowing fixed length strings is
    a favourite cracker technique. */
extern char *strcpy(char *, const char *);

/** \ingroup avr_string
    \fn int strcasecmp(const char *s1, const char *s2)
    \brief Compare two strings ignoring case.

    The strcasecmp() function compares the two strings \p s1 and \p s2,
    ignoring the case of the characters.

    \returns The strcasecmp() function returns an integer less than,
    equal to, or greater than zero if \p s1 is found, respectively, to
    be less than, to match, or be greater than \p s2. A consequence of
    the ordering used by strcasecmp() is that if \p s1 is an initial
    substring of \p s2, then \p s1 is considered to be "less than"
    \p s2. */
extern int strcasecmp(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strcasestr(const char *s1, const char *s2)

    The strcasestr() function finds the first occurrence of the
    substring \p s2 in the string \p s1. This is like strstr(), except
    that it ignores case of alphabetic symbols in searching for the
    substring. (Glibc, GNU extension.)

    \return The strcasestr() function returns a pointer to the beginning
    of the substring, or \c NULL if the substring is not found. If \p s2
    points to a string of zero length, the function returns \p s1. */
extern char *strcasestr(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_string
    \fn size_t strcspn(const char *s, const char *reject)

    The strcspn() function calculates the length of the initial segment
    of \p s which consists entirely of characters not in \p reject.

    \return The strcspn() function returns the number of characters in
    the initial segment of \p s which are not in the string \p reject.
    The terminating zero is not considered as a part of string.	*/
extern size_t strcspn(const char *__s, const char *__reject) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strdup(const char *s1)
    \brief Duplicate a string.

    The strdup() function allocates memory and copies into it the string
    addressed by s1, including the terminating null character.

    \warning The strdup() function calls malloc() to allocate the memory
    for the duplicated string! The user is responsible for freeing the
    memory by calling free().

    \returns The strdup() function returns a pointer to the resulting string
    dest. If malloc() cannot allocate enough storage for the string, strdup()
    will return NULL.

    \warning Be sure to check the return value of the strdup() function to
    make sure that the function has succeeded in allocating the memory!
*/
extern char *strdup(const char *s1);

/** \ingroup avr_string
    \fn size_t strlcat(char *dst, const char *src, size_t siz)
    \brief Concatenate two strings.

    Appends \p src to string \p dst of size \p siz (unlike strncat(),
    \p siz is the full size of \p dst, not space left).  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz <=
    \p strlen(dst)).

    \returns The strlcat() function returns strlen(src) + MIN(siz,
    strlen(initial dst)).  If retval >= siz, truncation occurred.  */
extern size_t strlcat(char *, const char *, size_t);

/** \ingroup avr_string
    \fn size_t strlcpy(char *dst, const char *src, size_t siz)
    \brief Copy a string.

    Copy \p src to string \p dst of size \p siz.  At most \p siz-1
    characters will be copied.  Always NULL terminates (unless \p siz == 0).

    \returns The strlcpy() function returns strlen(src). If retval >= siz,
    truncation occurred.  */
extern size_t strlcpy(char *, const char *, size_t);

/** \ingroup avr_string
    \fn size_t strlen(const char *src)
    \brief Calculate the length of a string.

    The strlen() function calculates the length of the string src, not
    including the terminating '\\0' character.

    \returns The strlen() function returns the number of characters in
    src.  */
extern size_t strlen(const char *) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strlwr(char *s)
    \brief Convert a string to lower case.

    The strlwr() function will convert a string to lower case. Only the upper
    case alphabetic characters [A .. Z] are converted.  Non-alphabetic
    characters will not be changed.

    \returns The strlwr() function returns a pointer to the converted
    string. */
extern char *strlwr(char *);

/** \ingroup avr_string
    \fn char *strncat(char *dest, const char *src, size_t len)
    \brief Concatenate two strings.

    The strncat() function is similar to strcat(), except that only the first
    n characters of src are appended to dest.

    \returns The strncat() function returns a pointer to the resulting string
    dest.  */
extern char *strncat(char *, const char *, size_t);

/** \ingroup avr_string
    \fn int strncmp(const char *s1, const char *s2, size_t len)
    \brief Compare two strings.

    The strncmp() function is similar to strcmp(), except it only compares the
    first (at most) n characters of s1 and s2.

    \returns The strncmp() function returns an integer less than, equal to, or
    greater than zero if s1 (or the first n bytes thereof) is found,
    respectively, to be less than, to match, or be greater than s2.  */
extern int strncmp(const char *, const char *, size_t) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strncpy(char *dest, const char *src, size_t len)
    \brief Copy a string.

    The strncpy() function is similar to strcpy(), except that not more than n
    bytes of src are copied. Thus, if there is no null byte among the first n
    bytes of src, the result will not be null-terminated.

    In the case where the length of src is less than that of n, the remainder
    of dest will be padded with nulls.

    \returns The strncpy() function returns a pointer to the destination
    string dest.  */
extern char *strncpy(char *, const char *, size_t);

/** \ingroup avr_string
    \fn int strncasecmp(const char *s1, const char *s2, size_t len)
    \brief Compare two strings ignoring case.

    The strncasecmp() function is similar to strcasecmp(), except it
    only compares the first \p len characters of \p s1.

    \returns The strncasecmp() function returns an integer less than,
    equal to, or greater than zero if \p s1 (or the first \p len bytes
    thereof) is found, respectively, to be less than, to match, or be
    greater than \p s2. A consequence of the ordering used by
    strncasecmp() is that if \p s1 is an initial substring of \p s2,
    then \p s1 is considered to be "less than" \p s2.  */
extern int strncasecmp(const char *, const char *, size_t) __ATTR_PURE__;

/** \ingroup avr_string
    \fn size_t strnlen(const char *src, size_t len)
    \brief Determine the length of a fixed-size string.

    The strnlen function returns the number of characters in the string
    pointed to by src, not including the terminating '\\0' character, but at
    most len. In doing this, strnlen looks only at the first len characters at
    src and never beyond src+len.

    \returns The strnlen function returns strlen(src), if that is less than
    len, or len if there is no '\\0' character among the first len
    characters pointed to by src. */
extern size_t strnlen(const char *, size_t) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strpbrk(const char *s, const char *accept)

    The strpbrk() function locates the first occurrence in the string
    \p s of any of the characters in the string \p accept.

    \return  The strpbrk() function returns a pointer to the character
    in \p s that matches one of the characters in \p accept, or \c NULL
    if no such character is found. The terminating zero is not
    considered as a part of string: if one or both args are empty, the
    result will be \c NULL. */
extern char *strpbrk(const char *__s, const char *__accept) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strrchr(const char *src, int val)
    \brief Locate character in string.

    The strrchr() function returns a pointer to the last occurrence of the
    character val in the string src.

    Here "character" means "byte" - these functions do not work with wide or
    multi-byte characters.

    \returns The strrchr() function returns a pointer to the matched character
    or NULL if the character is not found. */
extern char *strrchr(const char *, int) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strrev(char *s)
    \brief Reverse a string.

    The strrev() function reverses the order of the string.

    \returns The strrev() function returns a pointer to the beginning of the
    reversed string.  */
extern char *strrev(char *);

/** \ingroup avr_string
    \fn char *strsep(char **sp, const char *delim)
    \brief Parse a string into tokens.

    The strsep() function locates, in the string referenced by \p *sp,
    the first occurrence of any character in the string \p delim (or the
    terminating '\\0' character) and replaces it with a '\\0'.  The
    location of the next character after the delimiter character (or \c
    NULL, if the end of the string was reached) is stored in \p *sp. An
    ``empty'' field, i.e. one caused by two adjacent delimiter
    characters, can be detected by comparing the location referenced by
    the pointer returned in \p *sp to '\\0'.

    \return The strsep() function returns a pointer to the original
    value of \p *sp. If \p *sp is initially \c NULL, strsep() returns
    \c NULL. */
extern char *strsep(char **, const char *);

/** \ingroup avr_string
    \fn size_t strspn(const char *s, const char *accept)

    The strspn() function calculates the length of the initial segment
    of \p s which consists entirely of characters in \p accept.

    \return  The strspn() function returns the number of characters in
    the initial segment of \p s which consist only of characters from \p
    accept. The terminating zero is not considered as a part of string. */
extern size_t strspn(const char *__s, const char *__accept) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strstr(const char *s1, const char *s2)
    \brief Locate a substring.

    The strstr() function finds the first occurrence of the substring \p
    s2 in the string \p s1.  The terminating '\\0' characters are not
    compared.

    \returns The strstr() function returns a pointer to the beginning of
    the substring, or \c NULL if the substring is not found. If \p s2
    points to a string of zero length, the function returns \p s1. */
extern char *strstr(const char *, const char *) __ATTR_PURE__;

/** \ingroup avr_string
    \fn char *strtok(char *s, const char *delim)
    \brief Parses the string s into tokens.

    strtok parses the string s into tokens. The first call to strtok
    should have s as its first argument. Subsequent calls should have
    the first argument set to NULL. If a token ends with a delimiter, this
    delimiting character is overwritten with a '\\0' and a pointer to the next
    character is saved for the next call to strtok. The delimiter string
    delim may be different for each call.

    \returns The strtok() function returns a pointer to the next token or
    NULL when no more tokens are found.

    \note strtok() is NOT reentrant. For a reentrant version of this function
    see \c strtok_r().
*/
extern char *strtok(char *, const char *);

/** \ingroup avr_string
    \fn char *strtok_r(char *string, const char *delim, char **last)
    \brief Parses string into tokens.

    strtok_r parses string into tokens. The first call to strtok_r
    should have string as its first argument. Subsequent calls should have
    the first argument set to NULL. If a token ends with a delimiter, this
    delimiting character is overwritten with a '\\0' and a pointer to the next
    character is saved for the next call to strtok_r. The delimiter string
    \p delim may be different for each call. \p last is a user allocated char*
    pointer. It must be the same while parsing the same string. strtok_r is
    a reentrant version of strtok().

    \returns The strtok_r() function returns a pointer to the next token or
    NULL when no more tokens are found. */
extern char *strtok_r(char *, const char *, char **);

/** \ingroup avr_string
    \fn char *strupr(char *s)
    \brief Convert a string to upper case.

    The strupr() function will convert a string to upper case. Only the lower
    case alphabetic characters [a .. z] are converted.  Non-alphabetic
    characters will not be changed.

    \returns The strupr() function returns a pointer to the converted
    string.  The pointer is the same as that passed in since the operation is
    perform in place. */
extern char *strupr(char *);

#ifndef __DOXYGEN__
/* libstdc++ compatibility, dummy declarations */
extern int strcoll(const char *s1, const char *s2);
extern char *strerror(int errnum);
extern size_t strxfrm(char *dest, const char *src, size_t n);
#endif	/* !__DOXYGEN__ */

#ifdef __cplusplus
}
#endif

#endif /* _STRING_H_ */

