/* Runtime-stage C reconstruction; no matching credit until verified manifest entry. */
typedef struct RuntimeNode RuntimeNode;
struct RuntimeNode { unsigned int type; RuntimeNode *parent, *firstChild, *next; };
void func_800AC334(RuntimeNode *object) { RuntimeNode *previous=object->parent; if(previous) { register RuntimeNode *first __asm__("$2")=previous->firstChild; if(first==object) previous->firstChild=object->next; else { do { previous=first; __asm__("" : "=r"(first) : "0"(first)); first=first->next; } while(first != object); previous->next=object->next; } object->next=0; object->parent=0; } }
