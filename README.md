Hash Map implementation

hashMap* createHashMap() - the hashMap struct returned will need to be passed into any associated functions

void deleteHashMap(hashMap* hm) - to cleanup memory

value* lookUp(hashMap* hm, char* key) - search hash map for specific key, value object has void pointer attribute called "data" which contains the data, cast this into expected data type

void insert(hashMap* hm, char* key, void* val) - how to add to hash map, pass in key and pointer to the data representing the value


keys are limited to C strings (char*) this is because the hash function is not polymorphic and a polymorphic hash function doesn't seem that valuable tbh.
the values however, are fully polymorphic, which is nice
