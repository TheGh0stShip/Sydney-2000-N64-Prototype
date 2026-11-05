/* Runtime-stage N64 MIPS/o32 reconstruction; verified rows live in config/runtime. */
typedef struct Link Link;
struct Link { unsigned int unused; Link *next; };
Link *func_800AB024(Link *link) { return link->next->next->next; }
