#define DEBUG 1
#define DISABLED 0

#if DISABLED
#include <debug.h>
#endif

#ifdef DISABLED
#include "empty_1.h"
#endif

#include "empty_2.h"

typedef MyType int;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

#if DISABLED
void shouldNotBePrototyped() {

}
#endif

#if DEBUG
void debug() {

}
#endif

#ifdef UNDEFINED
void undefinedFunction() {
}
#endif

#ifdef DISABLED
void disabledIsDefined() {
}
#endif

int useMyType(MyType type) {

}