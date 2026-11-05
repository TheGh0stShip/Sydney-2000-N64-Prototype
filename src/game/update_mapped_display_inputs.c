/* Exact SN GCC 2.8 reconstruction of func_80007384 (ROM 0x7F84..0x846C).
 * Controller, binding and event structures use the N64 o32 ABI.
 * Empty register/memory barriers preserve original target lifetimes and
 * scheduling; they emit no instructions.
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
    register u32 deviceLimit __asm__("$2");
    u32 value;
    register u32 mask __asm__("$8");
    InputBinding *binding;
    register u16 *mapped __asm__("$7");
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
                register u32 ready __asm__("$3") = displayConfigurationReady;
                __asm__("" : "=r"(ready) : "0"(ready));
                mode = map->modes[0];
                device = map->devices[0];
                if (ready == 1 || mode == 3 || mode == 4)
                    enabled = (u32)map->objects[0];
                else enabled = 0;
            } else {
                mode = map->modes[1];
                device = map->devices[1];
                enabled = (u32)map->objects[1];
            }
            if (enabled && device != -1) {
                descriptor = func_800BC408((u16)device);
                __asm__("" : : "r"(descriptor) : "memory");
                deviceLimit = 12;
                __asm__ volatile ("" : "=r"(deviceLimit) : "0"(deviceLimit) : "memory");
                {
                    register u32 checkedGroup __asm__("$11") = groupIndex;
                    __asm__("" : "=r"(checkedGroup) : "0"(checkedGroup));
                    if (checkedGroup == deviceLimit) goto accumulated_value;
                }
                if ((u32)device < deviceLimit) {
                    binding = displayInputStates[descriptor->stateIndex].modes[mode].bindings;
                    if ((u8)pass == 0) mask = map->masks[0];
                    else mask = map->masks[1];
                    {
                        register u32 scratch2 __asm__("$2") = (s32)descriptor->displayIndex;
                        register u32 scratch3 __asm__("$3");
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$9");
                        index = 0;
                        scratch3 = scratch2 * 12;
                        scratch2 = (u32)displayInputRecords;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2));
                        scratch3 = scratch3 + scratch2;
                        scratch2 = (s32)((DisplayRecord *)scratch3)->controllerIndex;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2) : "$7");
                        mapped = &binding->mapped;
                        __asm__("" : "=r"(scratch2), "=r"(mapped) : "0"(scratch2), "1"(mapped));
                        scratch3 = scratch2 * 6;
                        scratch2 = (u32)displayInputControllers;
                        __asm__("" : "=r"(scratch2) : "0"(scratch2));
                        controller = (ControllerRecord *)(scratch3 + scratch2);
                    }
                    for (; ; index++) {
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
                            else {
                                digital = flags & 0x10;
                                __asm__("" : "=r"(digital) : "0"(digital));
                                digital = digital != 0;
                            }
                            if (digital) {
                                register u32 heldButtons __asm__("$5") = controller->buttons;
                                register s32 heldFlags __asm__("$2") = binding->flags;
                                register u32 heldUnsignedFlags __asm__("$3") = (u16)binding->flags;
                                register u32 inverted __asm__("$2");
                                __asm__ volatile ("" : "=r"(heldButtons), "=r"(heldFlags), "=r"(heldUnsignedFlags)
                                                  : "0"(heldButtons), "1"(heldFlags), "2"(heldUnsignedFlags));
                                if (!(heldButtons & heldFlags)) goto missing_binding;
                                inverted = ~heldUnsignedFlags;
                                remainingButtons = heldButtons & inverted;
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
                            value |= *mapped;
                            goto next_binding;
missing_binding:
                            mask |= *mapped;
                        }
next_binding:
                        mapped = (u16 *)((u8 *)mapped + 4);
                        binding++;
                    }
                    {
                        register u32 filtered __asm__("$3") = value & mask;
                        value = filtered;
                        if ((u8)pass == 0) map->masks[0] = mask;
                        else {
                            map->masks[1] = mask;
                            accumulated |= filtered;
                        }
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
                goto updated_value;
accumulated_value:
                value = accumulated;
updated_value:
                {
                    if ((u8)pass == 1) {
                        register u32 checkedGroup __asm__("$11") = groupIndex;
                        register u32 requiredGroup __asm__("$2") = 12;
                        __asm__("" : "=r"(requiredGroup) : "0"(requiredGroup));
                        if (checkedGroup != requiredGroup) goto next_pass;
                    }
                    if ((u16)value != descriptor->value) {
                        register u8 *eventPage __asm__("$4") = (u8 *)0x800F0000;
                        register InputEvent *eventBase __asm__("$4");
                        register u32 eventIndex __asm__("$2");
                        register u32 nextIndex __asm__("$2");
                        register u32 eventOffset __asm__("$3");
                        register u32 referenceTime __asm__("$5");
                        register InputEvent *event __asm__("$3");
                        eventIndex = displayInputEventIndex;
                        __asm__("" : "=r"(eventPage), "=r"(eventIndex)
                                   : "0"(eventPage), "1"(eventIndex));
                        eventBase = (InputEvent *)(eventPage + 0x2C80);
                        __asm__ volatile ("" : "=r"(eventBase), "=r"(eventIndex)
                                            : "0"(eventBase), "1"(eventIndex) : "memory");
                        descriptor->value = value;
                        __asm__ volatile ("" : : "m"(descriptor->value) : "$3");
                        eventOffset = eventIndex * 12;
                        __asm__("" : "=r"(eventOffset) : "0"(eventOffset) : "$2");
                        referenceTime = selectedDisplayConfiguration;
                        __asm__("" : "=r"(eventOffset), "=r"(referenceTime)
                                   : "0"(eventOffset), "1"(referenceTime));
                        event = (InputEvent *)(eventOffset + (u32)eventBase);
                        event->group = group;
                        event->value = value;
                        event->unused[0] = 0;
                        event->unused[1] = 0;
                        nextIndex = displayInputEventIndex;
                        event->time = time;
                        __asm__ volatile ("" : "=r"(nextIndex) : "0"(nextIndex), "m"(event->time));
                        displayInputEventIndex = nextIndex + 1;
                        event->relativeTime = time - referenceTime;
                        if (displayInputEventIndex >= 256) displayInputEventIndex = 0;
                    }
                }
            }
next_pass:
            ;
        }
    }
}
