//
//  lique.h
//  lique
//
//  Created by lihao10 on 2020/4/13.
//  Copyright © 2020 GodL. All rights reserved.
//

#ifndef lique_h
#define lique_h

#ifndef lique_define
#define lique_define

#ifdef __cplusplus
    #define LIQUE_EXTERN_C_BEGIN  extern "C" {
    #define LIQUE_EXTERN_C_END  }
#else
    #define LIQUE_EXTERN_C_BEGIN
    #define LIQUE_EXTERN_C_END
#endif

#endif

LIQUE_EXTERN_C_BEGIN

#include <stdio.h>

typedef const void * (*lique_enqueue_callback)(const void *);
typedef void (*lique_dequeue_callback)(const void *);
typedef void (*lique_destory_callback)(const void *);

typedef struct _lique_callback {
    lique_enqueue_callback enqueue_callback;
    lique_dequeue_callback dequeue_callback;
    lique_destory_callback destory_callback;
}lique_callback;

extern lique_callback lique_string_callback;

typedef struct lique* lique_ref;

extern lique_ref __attribute__((overloadable)) lique_create(void);

extern lique_ref __attribute__((overloadable)) lique_create(unsigned int limit);

extern lique_ref __attribute__((overloadable)) lique_create(unsigned int limit,lique_callback *callback);

extern void lique_enqueue(lique_ref queue,const void *value);

extern const void *lique_dequeue(lique_ref queue);

extern unsigned int lique_length(lique_ref queue);

extern void lique_destory(lique_ref queue);

LIQUE_EXTERN_C_END

#endif /* lique_h */
