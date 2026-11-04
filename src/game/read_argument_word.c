#ifndef LEAF_NAME
#define LEAF_NAME readArgumentWord
#endif

#ifndef WORD_INDEX
#define WORD_INDEX 0
#endif

int LEAF_NAME(int *words) {
    return words[WORD_INDEX];
}
