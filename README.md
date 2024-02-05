Hash Map implementation

hashMap* createHashMap() - the hashMap struct returned will need to be passed into any associated functions

void deleteHashMap(hashMap* hm) - to cleanup memory

value* lookUp(hashMap* hm, char* key) - search hash map for specific key, value object has void pointer attribute called "data" which contains the data, cast this into expected data type

void insert(hashMap* hm, char* key, void* val, size_t dataSize) - how to add to hash map, pass in key and a pointer to the data representing the value as well as the size of the data, if it's a primitive or a struct you can use the sizeof function, if it's a string you can use strlen function, and if it is some other array you can multiply the size of the array by the sizeof the data type


keys are limited to C strings (char*) this is because the hash function is not polymorphic and a polymorphic hash function doesn't seem that valuable tbh.
the values however, are fully polymorphic, which is nice
