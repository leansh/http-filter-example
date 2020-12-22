#ifndef __LIBDW_H
#define __LIBDW_H

#include "graal_isolate.h"


#if defined(__cplusplus)
extern "C" {
#endif

char* runDW(graal_isolatethread_t*, char*);

char* runDW1(graal_isolatethread_t*, char*, char*, char*);

char* runDW2(graal_isolatethread_t*, char*, char*, char*, char*, char*);

#if defined(__cplusplus)
}
#endif
#endif
