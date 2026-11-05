/* Initialize the runtime heap and event queues, configure display, and post startup. */
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u32 ticks; u8 pad[0x10]; u16 width,height; union { int value; u8 bytes[4]; } time; } RuntimeClock;
typedef char runtime_clock_width[sizeof(void *)==4?1:-1];
typedef char runtime_clock_time_offset[(unsigned long)&((RuntimeClock *)0)->time==0x18?1:-1];
extern RuntimeClock runtimeClock;
extern volatile int runtimeFrameTime;
extern int runtimeOutputCookie,runtimeSystemReady,selectedDisplayConfiguration;
extern u8 runtimeSavedMode,runtimeCurrentMode;
extern u8 runtimeHeap[],runtimePriorityQueue[],runtimeOutputQueue[],runtimeMainObject[];
extern void func_800AA92C(void *,int,int);
extern void func_800AB3B8(void *,int);
extern void func_800ABA20(void *,int);
extern int func_80006F00(void);
extern void func_80010EF4(u16 *,u16 *);
extern void func_80017B14(u16,u16,int,int *);
extern void func_800DAC40(void);
extern void func_800AB2A4(void *,int,int,void *,int,int);
int func_800B4470(void) {
 int configuration; int result;
 int step=runtimeClock.time.bytes[3];
 runtimeFrameTime=0;
 if(step==0)step=1;
 runtimeOutputCookie=step;
 func_800AA92C(runtimeHeap,0x2000000,0x80000);
 func_800AB3B8(runtimePriorityQueue,100);
 func_800ABA20(runtimeOutputQueue,128);
 runtimeSystemReady=1;
 runtimeCurrentMode=runtimeSavedMode;
 if(func_80006F00()) {
  func_80010EF4(&runtimeClock.width,&runtimeClock.height);
  func_80017B14(runtimeClock.width,runtimeClock.height,16,&configuration);
  func_800DAC40();
  selectedDisplayConfiguration=configuration;
  func_800AB2A4(runtimePriorityQueue,runtimeClock.time.value,3,runtimeMainObject,0,42);
  result=1;
 } else result=0;
 return result;
}
