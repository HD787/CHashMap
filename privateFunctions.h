//this is the djb2 hash algorithm, I stole this, thank you Dan Bernstein
//this orginally used an unsigned char, I changed it to char for simplicity, i dont think this will cause problems
unsigned long hash(char *str){
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}