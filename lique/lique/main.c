//
//  main.c
//  lique
//
//  Created by lihao10 on 2020/4/13.
//  Copyright © 2020 GodL. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "lique.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    lique_ref queue = lique_create(10,&lique_string_callback);
    for (int i=0; i<10; i++) {
        lique_enqueue(queue, "a");
    }
    
    for (int  i=0; i<5; i++) {
        const void *value = lique_dequeue(queue);
        printf("%s \n",value);
    }
    for (int i=0; i<3; i++) {
        lique_enqueue(queue, "b");
    }
    for (int i=0; i<2; i++) {
        lique_enqueue(queue, "c");
    }
    
    for (int i=0; i<10; i++) {
        const void *value = lique_dequeue(queue);
        printf("%s \n",value);
    }
    lique_dequeue(queue);
    printf("Hello, World!\n");
    return 0;
}
