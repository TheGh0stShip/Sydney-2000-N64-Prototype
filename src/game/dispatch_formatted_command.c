#ifndef LEAF_NAME
#define LEAF_NAME dispatchFormattedCommand
#endif

#ifndef FORMAT_NAME
#define FORMAT_NAME formatString
#endif

#ifndef COPY_NAME
#define COPY_NAME copyString
#endif

#ifndef APPEND_NAME
#define APPEND_NAME appendString
#endif

#ifndef DISPATCH_NAME
#define DISPATCH_NAME dispatchCommand
#endif

typedef signed int s32;
typedef unsigned char u8;

extern s32 FORMAT_NAME(u8 *destination, const u8 *format, ...);
extern u8 *COPY_NAME(u8 *destination, const u8 *source);
extern u8 *APPEND_NAME(u8 *destination, const u8 *source);
extern s32 DISPATCH_NAME(s32 value, s32 *result, void *context, s32 mode);

extern u8 formattedCommand[];
extern u8 commandBuffer[];
extern u8 commandPrefix[];
extern u8 commandContext;
extern const u8 commandFormat[];

s32 LEAF_NAME(s32 value) {
    s32 result = 0;

    FORMAT_NAME(formattedCommand, commandFormat, value);
    COPY_NAME(commandBuffer, commandPrefix);
    APPEND_NAME(commandBuffer, formattedCommand);
    if (DISPATCH_NAME(value, &result, &commandContext, 1) == 0) {
        result = 0;
    }
    return result;
}
