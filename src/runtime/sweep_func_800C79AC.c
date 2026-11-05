struct Scroller {
    char pad[1740];
    float targetY;
    float targetX;
    float currentY;
    float currentX;
    int elapsed;
    unsigned short active;
    unsigned short direction;
};

extern void func_800C76BC(struct Scroller *);

void func_800C79AC(struct Scroller *self, unsigned int x, unsigned int y, int snap)
{
    float fx = (float)x / 64000.0f;
    float fy = (float)y / 64000.0f;

    self->targetY = fy;
    self->targetX = fx;
    if (snap) {
        self->currentX = fx;
        self->currentY = fy;
        func_800C76BC(self);
    }
    self->elapsed = 0;
    self->active = 1;
    if (self->targetX > self->currentX) {
        self->direction |= 8;
    } else if (self->currentX > self->targetX) {
        self->direction |= 16;
    }
    if (self->targetY > self->currentY) {
        self->direction |= 2;
    } else if (self->currentY > self->targetY) {
        self->direction |= 4;
    }
}
