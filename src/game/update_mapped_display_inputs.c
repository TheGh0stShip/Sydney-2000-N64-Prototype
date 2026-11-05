/* NONMATCHING reconstruction of func_80007384 (ROM 0x7F84..0x846C).
 * Controller, binding and event structures use the N64 o32 ABI.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef struct {
    void *objects[2];
    u32 modes[2];
    s8 devices[2];
    u16 masks[2];
    u16 unused;
} DisplayInputMap;
typedef struct { s16 displayIndex; u16 value; u32 stateIndex; } InputDescriptor;
typedef struct { u32 first, second; s16 controllerIndex; u16 value; } DisplayRecord;
typedef struct { u16 buttons; s8 stickX, stickY; u16 unused; } ControllerRecord;
typedef struct { s16 flags; u16 mapped; } InputBinding;
typedef struct { InputBinding bindings[6]; } InputBindingMode;
typedef struct { InputBindingMode modes[9]; } InputBindingState;
typedef struct { u32 relativeTime, time; u8 group, value, unused[2]; } InputEvent;
typedef char check_input_map_size[sizeof(DisplayInputMap) == 24 ? 1 : -1];
typedef char check_input_state_size[sizeof(InputBindingState) == 216 ? 1 : -1];
typedef char check_input_event_size[sizeof(InputEvent) == 12 ? 1 : -1];
extern DisplayInputMap displayInputMaps[13];
extern u32 displayConfigurationReady;
extern InputBindingState displayInputStates[];
extern DisplayRecord displayInputRecords[4];
extern ControllerRecord displayInputControllers[];
extern volatile u16 displayInputEventIndex;
extern InputEvent displayInputEvents[256];
extern u32 selectedDisplayConfiguration;
extern InputDescriptor *func_800BC408(u16 device);
extern u32 func_800AAC44(void *object, u32 time);

void func_80007384(u32 time) {
    u32 accumulated = 0;
    register u32 group __asm__("$22");
    u32 pass, index;
    u32 groupIndex;
    DisplayInputMap *map;
    register InputDescriptor *descriptor __asm__("$20");
    u32 mode;
    s32 device;
    register u32 enabled __asm__("$2");
    u32 value;
    register u32 mask __asm__("$8");
    InputBinding *binding;
    ControllerRecord *controller;
    u16 flags;
    u32 trigger;
    u32 digital;
    u32 remainingButtons;
    void *object;

    for (group = 0; ; group++) {
        register u32 currentGroup __asm__("$4") = (u8)group;
        register u32 groupCopy __asm__("$3");
        register u32 mapOffset __asm__("$2");
        register u8 *mapBase __asm__("$11");
        __asm__("" : "=r"(currentGroup) : "0"(currentGroup));
        pass = 0;
        if (currentGroup >= 13) break;
        groupCopy = currentGroup;
        __asm__("" : "=r"(groupCopy) : "0"(groupCopy));
        mapOffset = groupCopy * 24;
        mapBase = (u8 *)displayInputMaps;
        __asm__("" : "=r"(mapBase) : "0"(mapBase));
        map = (DisplayInputMap *)(mapOffset + (u32)mapBase);
        __asm__("" : : "r"(map) : "memory");
        groupIndex = currentGroup;
        __asm__("" : : "m"(groupIndex));
        for (; ; pass++) {
            register u32 currentPass __asm__("$3") = (u8)pass;
            __asm__("" : "=r"(currentPass) : "0"(currentPass));
            if (currentPass >= 2) break;
            value = 0;
            if (currentPass == 0) {
                mode = map->modes[0];
                device = map->devices[0];
                if (displayConfigurationReady == 1 || mode == 3 || mode == 4)
                    enabled = (u32)map->objects[0];
                else enabled = 0;
            } else {
                mode = map->modes[1];
                device = map->devices[1];
                enabled = (u32)map->objects[1];
            }
            if (enabled && device != -1) {
                descriptor = func_800BC408((u16)device);
                        if (groupIndex == 12) {
                    value = accumulated;
                } else if ((u32)device < 12) {
                    binding = displayInputStates[descriptor->stateIndex].modes[mode].bindings;
                    if ((u8)pass == 0) mask = map->masks[0];
                    else mask = map->masks[1];
                    controller = &displayInputControllers[
                        displayInputRecords[descriptor->displayIndex].controllerIndex];
                    for (index = 0; ; index++) {
                        register u32 currentBinding __asm__("$2") = (u8)index;
                        __asm__("" : "=r"(currentBinding) : "0"(currentBinding));
                        if (currentBinding >= 6) break;
                        if (binding->flags != -1) {
                            flags = binding->flags;
                            if (flags & 2) digital = 1;
                            else if (flags & 1) digital = 1;
                            else if (flags & 8) digital = 1;
                            else if (flags & 4) digital = 1;
                            else if (flags & 0x8000) digital = 1;
                            else if (flags & 0x4000) digital = 1;
                            else if (flags & 0x1000) digital = 1;
                            else if (flags & 0x2000) digital = 1;
                            else if (flags & 0x20) digital = 1;
                            else digital = (flags & 0x10) != 0;
                            if (digital) {
                                if (!(controller->buttons & binding->flags)) goto missing_binding;
                                remainingButtons = controller->buttons & ~binding->flags;
                                goto triggered_binding;
                            }
                            switch (binding->flags) {
                            case 0x200:
                                if ((controller->buttons & 0x200) || controller->stickX < -30) trigger = 1;
                                else trigger = 0;
                                if (!trigger) goto missing_binding;
                                controller->stickX = 0;
                                remainingButtons = controller->buttons & ~0x200;
                                goto triggered_binding;
                            case 0x100:
                                if ((controller->buttons & 0x100) || controller->stickX > 30) trigger = 1;
                                else trigger = 0;
                                if (!trigger) goto missing_binding;
                                controller->stickX = 0;
                                remainingButtons = controller->buttons & ~0x100;
                                goto triggered_binding;
                            case 0x800:
                                if ((controller->buttons & 0x800) || controller->stickY > 30) trigger = 1;
                                else trigger = 0;
                                if (!trigger) goto missing_binding;
                                controller->stickY = 0;
                                remainingButtons = controller->buttons & ~0x800;
                                goto triggered_binding;
                            case 0x400:
                                if ((controller->buttons & 0x400) || controller->stickY < -30) trigger = 1;
                                else trigger = 0;
                                if (!trigger) goto missing_binding;
                                controller->stickY = 0;
                                remainingButtons = controller->buttons & ~0x400;
                                goto triggered_binding;
                            default:
                                goto next_binding;
                            }
triggered_binding:
                            controller->buttons = remainingButtons;
                            value |= binding->mapped;
                            goto next_binding;
missing_binding:
                            mask |= binding->mapped;
                        }
next_binding:
                        binding++;
                    }
                    value &= mask;
                    if ((u8)pass == 0) map->masks[0] = mask;
                    else {
                        map->masks[1] = mask;
                        accumulated |= value;
                    }
                } else {
                    object = map->objects[0];
                    if (object) {
                        if (device < 21) {
                            u8 *vtable = *(u8 **)((u8 *)object + 0xB4);
                            s16 adjust = *(s16 *)(vtable + 0x50);
                            u32 (*callback)(void *, u32) = *(u32 (**)(void *, u32))(vtable + 0x54);
                            value = callback((u8 *)object + adjust, time);
                        } else if (device < 29) value = func_800AAC44(object, time);
                        else value = descriptor->value;
                    }
                }
                if ((u8)pass != 1 || groupIndex == 12) {
                    if ((u16)value != descriptor->value) {
                        u32 referenceTime = selectedDisplayConfiguration;
                        InputEvent *event = &displayInputEvents[displayInputEventIndex];
                        descriptor->value = value;
                        event->group = group;
                        event->value = value;
                        event->unused[0] = 0;
                        event->unused[1] = 0;
                        event->time = time;
                        displayInputEventIndex++;
                        event->relativeTime = time - referenceTime;
                        if (displayInputEventIndex >= 256) displayInputEventIndex = 0;
                    }
                }
            }
        }
    }
}
