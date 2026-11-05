typedef struct {
    unsigned char pad[92];
    float level;
    unsigned char rest[116];
} Channel;

typedef struct {
    unsigned char header[184];
    Channel channels[20];
    unsigned char pad[4612 - 184 - 20 * 212];
    float floor;
    int active;
} Mixer;

void func_800CA4F0(Mixer *mixer)
{
    float step;
    float delta;
    unsigned char i;

    if (mixer->channels[0].level > mixer->floor) {
        delta = mixer->channels[0].level - mixer->floor;
        delta += delta;
        if (delta < 32.767f) {
            delta = 32.767f;
        }
        step = delta / 30.0f;
        for (i = 0; i < 20; i++) {
            mixer->channels[i].level -= step;
            if (mixer->channels[i].level < mixer->floor) {
                mixer->channels[i].level = mixer->floor;
                if (i == 0) {
                    mixer->active = 0;
                }
            }
        }
    }
}
