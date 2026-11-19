#include "sydney_types.h"

/* Lays out the menu rows once: resets each row's widgets, places them in two columns and sets their alphas. */
struct Base {
    s32 unk_00;
    u8 pad04[0x9C];
    f32 unk_A0;
    f32 unk_A4;
    u8 padA8[0xC];
    virtual void v0() __asm__("func_80000010");
    virtual void v1() __asm__("func_80000014");
    virtual void v2() __asm__("func_80000018");
    virtual void v3() __asm__("func_8000001C");
    virtual void v4() __asm__("func_80000020");
    virtual void v5() __asm__("func_80000024");
    virtual void v6() __asm__("func_80000028");
    virtual void reset() __asm__("func_8000002C");
};
struct Text {
    void show(s32 on) __asm__("func_800B2158");
    void setAlpha(s32 a) __asm__("func_800B32D4");
};
struct Icon : Base {
    void setAlpha(s32 a) __asm__("func_800CE0CC");
};
struct Row {
    Base *unk_00;
    Text *text;
    Base *unk_08;
    Base *unk_0C;
    Icon *icon;
    Base *unk_14;
    Base *unk_18;
};
struct Menu {
    u8 pad[0x690];
    Row rows[1];
    u8 pad6AC[0x118C - 0x6AC];
    u8 flags;
    u8 numRows;
    u8 unk_118E;
    u8 unk_118F;
    void layout();
};
void Menu::layout() {
    u8 i;
    f32 x;
    if (!(flags & 1)) {
        x = 0.0f;
        for (i = 0; i < numRows; i++) {
            Row *r = &rows[i];
            r->unk_18->reset();
            r->unk_00->reset();
            r->text->show(1);
            r->unk_0C->reset();
            r->icon->reset();
            r->unk_08->reset();
            r->unk_14->reset();
            r->unk_14->unk_A0 = x + 602.0f;
            unk_118E = 0xFF;
            r->unk_14->unk_A4 = 186.0f;
            r->unk_08->unk_A4 = 4.0f;
            r->unk_18->unk_A4 = 19.0f;
            r->unk_00->unk_A4 = 3.0f;
            r->text->setAlpha(0xFF);
            r->icon->setAlpha(0xFF);
            if (i == 3) {
                x = 0.0f;
            }
            x += 244.0f;
            if (numRows >= 5) {
                if (i < 4) {
                    r->unk_14->unk_A4 = 150.0f;
                } else {
                    r->unk_14->unk_A4 = 186.0f;
                }
            }
        }
        flags |= 1;
        unk_118F |= 1;
    }
}
