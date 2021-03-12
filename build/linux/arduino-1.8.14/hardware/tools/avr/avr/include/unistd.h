#define __need_size_t
#include <stddef.h>

#include <sys/types.h>

extern int write (int, const void *, size_t);
extern int read (int, void *, size_t);
off_t lseek (int, off_t, int);
