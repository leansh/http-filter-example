#ifndef __LIBDW_H
#define __LIBDW_H

#include <graal_isolate_dynamic.h>


#if defined(__cplusplus)
extern "C" {
#endif

typedef char* (*runDW_fn_t)(graal_isolatethread_t*, char*);

typedef char* (*runDW1_fn_t)(graal_isolatethread_t*, char*, char*, char*);

typedef char* (*runDW2_fn_t)(graal_isolatethread_t*, char*, char*, char*, char*, char*);

#if defined(__cplusplus)
}
#endif
#endif
