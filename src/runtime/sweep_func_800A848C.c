/* Set the text of a slot's label widget to the name for the given id. */
typedef struct Widget {
    char pad[196];
    void *handle;
} Widget;

typedef struct Panel {
    char pad[268];
    Widget *slots[1];
} Panel;

extern int func_80017C4C(void *handle, int a, int *out);
extern int func_8000EB20(char *str);
extern void func_80017CF4(void *handle, int a, unsigned short text);
extern char *D_800F6400[];

void func_800A848C(Panel *panel, int slot, int id)
{
    void *handle;
    int info[4];
    int out;

    handle = panel->slots[slot]->handle;
    out = 0;
    if (func_80017C4C(handle, 0, &out) >= 0) {
        unsigned short text;

        if (id == 32) {
            text = func_8000EB20("LYMPICFLAG");
        } else {
            text = func_8000EB20(D_800F6400[id]);
        }
        func_80017CF4(handle, 0, text);
    }
}
