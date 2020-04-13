# lique
A C-implemented restricted queue

```C
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
```
