typedef struct Glob { char pad[0xD53]; unsigned char sel; } Glob;
extern Glob *D_800FC270;
extern float D_80077480[];
extern unsigned int D_800F2714;

float func_80088048(int unused, float *p, unsigned char n, float x)
{
    float scale;
    float inv;
    float sum;
    double fix;
    float k;
    float a;
    float b;
    float r;
    double dr;
    unsigned int u;

    scale = (p[0] + p[1]) * *(float *)0x8007143C * (D_80077480[D_800FC270->sel] - *(float *)0x80071438);
    sum = 0.0f;
    fix = *(double *)0x80071440;
    k = *(float *)0x80071448;
    a = *(float *)0x8007144C;
    b = *(float *)0x80071450;
    inv = x / (scale + *(float *)0x80071438);
    for (;;) {
        { unsigned char t = n; if (t == 0) break; }
        D_800F2714 = (D_800F2714 * 16807) & 0x7FFFFFFF;
        u = D_800F2714 >> 19;
        dr = (int)u;
        if ((int)u < 0) dr += fix;
        r = (float)dr * k;
        if (r < p[2]) r = p[2];
        n--;
        sum += inv / (r * a + b);
    }
    return sum;
}
