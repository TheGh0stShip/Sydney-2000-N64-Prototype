struct Label {
    char pad[188];
    char line0[212];
    char line1[212];
    char line2[212];
};

extern void func_800CB204(struct Label *self, void *line, float x, float y, float width, float scale, int a, int b, int c);
extern void func_800191E0(void *object, unsigned int color);

void func_800CB428(struct Label *self)
{
    func_800CB204(self, self->line0, 0.0f, 12.0f, 602.0f, 20.0f, 0, 0, 0);
    func_800191E0(self->line0 + 196, 0x82000000);
    func_800CB204(self, self->line1, 0.0f, 11.0f, 602.0f, 1.0f, 0, 0, 0);
    func_800191E0(self->line1 + 196, 0xFF000000);
    func_800CB204(self, self->line2, 0.0f, 32.0f, 602.0f, 1.0f, 0, 0, 0);
    func_800191E0(self->line2 + 196, 0xFF000000);
}
