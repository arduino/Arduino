#ifndef _LOCALE_H
#define _LOCALE_H

#if 1 /* ??? unimplemented */
#define LC_ALL      0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MESSAGES 3
#define LC_MONETARY 4
#define LC_NUMERIC  5
#define LC_TIME     6
struct lconv;
extern char *setlocale(int category, const char *locale);
extern struct lconv *localeconv(void);
#endif

#endif /* L_OCALE_H */
