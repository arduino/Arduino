#ifndef __SYS_LOCK_H__
#define __SYS_LOCK_H__

/* 
 * Lock routines for multi-threaded apps. The implementation
 * is provided by the OS.
 */

/*
 * Dummy semaphore structure of size 32 bytes. This is will be
 * type casted to Semaphore_struct in SYS/BIOS RTOS.
 */
typedef struct {
    void *dummy[8];
} __dummy_sem_t;

typedef struct {
    __dummy_sem_t sem;
    unsigned char init_done;
} __lock_mutex_t;

typedef struct {
    void *owner;
    __dummy_sem_t sem;
    unsigned int count;
    unsigned char init_done;
} __lock_recursive_mutex_t;

typedef __lock_mutex_t _LOCK_T;
typedef __lock_recursive_mutex_t _LOCK_RECURSIVE_T;
 
#include <_ansi.h>

#define __LOCK_INIT(class,lock) \
    class _LOCK_T lock = { .sem.dummy = {0, 0, 0, 0, 0, 0, 0, 0}, \
        .init_done = 0 }

#define __LOCK_INIT_RECURSIVE(class,lock) \
    class _LOCK_RECURSIVE_T lock = { .owner = 0, \
        .sem.dummy = {0, 0, 0, 0, 0, 0, 0, 0}, .count = 0, \
        .init_done = 0 }

extern void __libc_lock_init(_LOCK_T *lock);
extern void __libc_lock_init_recursive(_LOCK_RECURSIVE_T *lock);
extern void __libc_lock_close(_LOCK_T *lock);
extern void __libc_lock_close_recursive(_LOCK_RECURSIVE_T *lock);
extern void __libc_lock_acquire(_LOCK_T *lock);
extern void __libc_lock_acquire_recursive(_LOCK_RECURSIVE_T *lock);
extern void __libc_lock_release(_LOCK_T *lock);
extern void __libc_lock_release_recursive(_LOCK_RECURSIVE_T *lock);

/* Returns 0 for success and non-zero for failure */
extern int __libc_lock_try_acquire(_LOCK_T *lock);
extern int __libc_lock_try_acquire_recursive(_LOCK_RECURSIVE_T *lock);

#define __lock_init(lock) \
    __libc_lock_init(&(lock))
#define __lock_init_recursive(lock) \
    __libc_lock_init_recursive(&(lock))
#define __lock_close(lock) \
    __libc_lock_close(&(lock))
#define __lock_close_recursive(lock) \
    __libc_lock_close_recursive(&(lock))
#define __lock_acquire(lock) \
    __libc_lock_acquire(&(lock))
#define __lock_acquire_recursive(lock) \
    __libc_lock_acquire_recursive(&(lock))
#define __lock_try_acquire(lock) \
    __libc_lock_try_acquire(&(lock))
#define __lock_try_acquire_recursive(lock) \
    __libc_lock_try_acquire_recursive(&(lock))
#define __lock_release(lock) \
    __libc_lock_release(&(lock))
#define __lock_release_recursive(lock) \
    __libc_lock_release_recursive(&(lock))

#endif /* __SYS_LOCK_H__ */
