/* Header to define cxx abi parts missing from avrlibc */

#ifndef ABI_H_INCLUDED
#define ABI_H_INCLUDED

#include <stdlib.h>

__extension__ typedef int __guard __attribute__((mode (__DI__)));

extern "C" {
int __cxa_guard_acquire(__guard *);
void __cxa_guard_release (__guard *);
void __cxa_guard_abort (__guard *); 

void __cxa_pure_virtual(void) __attribute__ ((__noreturn__));
void __cxa_deleted_virtual(void) __attribute__ ((__noreturn__));
}

#endif
