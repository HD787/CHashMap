#include <stddef.h>

typedef struct value{
    void* data;
    size_t dataSize;
    char* plainKey;
    struct value* next;
}value;

typedef struct{
    //we have two values for this because in the case of a collision
    //the new value gets chained and the length stays the same
    //and the element count goes up
    int elementCount;
    int bucketCount;
    value** buckets;
}hashMap;