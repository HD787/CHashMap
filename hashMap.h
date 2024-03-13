#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "privateFunctions.h"
#include "hashMapStruct.h"


hashMap* createHashMap(int bucketCount){
    hashMap* val = malloc(sizeof(hashMap) * bucketCount);
    val->bucketCount = bucketCount;
    val->elementCount = 0;
    val->buckets = malloc(sizeof(value*) * val->bucketCount);
    return val;
}

void deleteHashMap(hashMap* hm){
    for (int i = 0; i < hm->bucketCount; i++) {
        value* temp = hm->buckets[i];
        while (temp != NULL) {
            value* prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(hm->buckets);
    free(hm);
}

value* lookUp(hashMap* hm, char* key){
    unsigned long hashValue = hash(key);
    unsigned long bucket = hashValue % hm->bucketCount;
    value* temp = hm->buckets[bucket];
    if(temp == NULL){
        printf("key not found (no bucket)");
        return NULL;
    } 
    else if(strcmp(temp->plainKey, key) == 0){
        return temp; 
    }
    while(strcmp(temp->plainKey, key) != 0){
        temp = temp->next;
        if (temp == NULL) break;
    }
    if(temp == NULL){ 
        printf("key not found in bucket");
        return NULL;
    }
    return temp;
}

void insert(hashMap* hm, char* key, void* val, size_t dataSize){
    unsigned long hashValue = hash(key);
    unsigned long bucket = hashValue % hm->bucketCount;
    value* temp =  hm->buckets[bucket];
    if(temp == NULL){
        hm->buckets[bucket] = malloc(sizeof(value));
        hm->buckets[bucket]->data = malloc(dataSize);
        memcpy(hm->buckets[bucket]->data, val, dataSize);
        hm->buckets[bucket]->dataSize = dataSize;
        hm->buckets[bucket]->plainKey = key;
        hm->buckets[bucket]->next = NULL;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        };
        temp->next = malloc(sizeof(value));
        temp->next->data = malloc(dataSize);
        memcpy(temp->next->data, val, dataSize);
        temp->next->dataSize = dataSize;
        temp->next->plainKey = key;
        temp->next->next = NULL;
    }
}
