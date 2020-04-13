//
//  lique.c
//  lique
//
//  Created by lihao10 on 2020/4/13.
//  Copyright © 2020 GodL. All rights reserved.
//

#include "lique.h"
#include <string.h>
#include <stdlib.h>

#define LIQUE_DEFAULE_LIMIT 6

struct lique {
    unsigned int length;
    unsigned int limit;
    unsigned int head_index;
    lique_callback callback;
    const void *queue[];
};

lique_callback lique_string_callback = {
    (lique_enqueue_callback)strdup,
    NULL,
    (lique_destory_callback)free
};

lique_callback _lique_null_callback = {
    NULL,
    NULL,
    NULL
};

lique_ref __attribute__((overloadable)) lique_create(void) {
    return lique_create(LIQUE_DEFAULE_LIMIT, NULL);
}

lique_ref __attribute__((overloadable)) lique_create(unsigned int limit) {
    return lique_create(limit, NULL);
}

lique_ref __attribute__((overloadable)) lique_create(unsigned int limit,lique_callback *callback) {
    lique_ref ref = malloc(sizeof(struct lique) + limit * sizeof(void *));
    ref->length = 0;
    ref->limit = limit;
    ref->head_index = 0;
    if (!callback)  callback = &_lique_null_callback;
    ref->callback = *callback;
    
    return ref;
}
void lique_enqueue(lique_ref queue,const void *value) {
    if (!queue || queue->length == queue->limit) return;
    if (queue->callback.enqueue_callback) {
        value = queue->callback.enqueue_callback(value);
    }
    if (!value) return;
    unsigned int index = queue->head_index + queue->length;
    if (index >= queue->limit) {
        index -= queue->limit;
    }
    queue->queue[index] = value;
    queue->length ++;
}

const void *lique_dequeue(lique_ref queue) {
    if (!queue || queue->length == 0) return NULL;
    const void *value = queue->queue[queue->head_index];
    if (queue->callback.dequeue_callback) {
        queue->callback.dequeue_callback(value);
    }
    queue->length --;
    queue->head_index = (queue->length == 0 || queue->head_index == queue->limit - 1) ? 0 : queue->head_index + 1;
    return value;
}

unsigned int lique_length(lique_ref queue) {
    if (!queue) return 0;
    return queue->length;
}

void lique_destory(lique_ref queue) {
    if (!queue) return;
    for (unsigned int i=0; i<queue->length; i++) {
        unsigned int index = queue->head_index + i;
        if (index >= queue->limit) index -= queue->limit;
        if (queue->callback.destory_callback) {
            queue->callback.destory_callback(queue->queue[index]);
        }
    }
    free(queue);
    queue = NULL;
}

