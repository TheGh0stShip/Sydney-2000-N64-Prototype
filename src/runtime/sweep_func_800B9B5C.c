void func_800B9B5C(short *in, float *out)
{
    float scale = 1.0f / 4096.0f;

    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
    out[3] = in[3];
    out[0] *= scale;
    out[1] *= scale;
    out[2] *= scale;
    out[3] *= scale;
}
