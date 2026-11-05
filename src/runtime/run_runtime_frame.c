/* Advance due runtime events, child updates and stage/audio callbacks.
 * The counter tracks passes at exactly the observed frame time; ordinary
 * catch-up passes do not consume the first equal-time pass.
 * GNU register locals plus the empty input constraint retain the original
 * frame/time lifetimes; the constraint emits no instructions.
 */
typedef unsigned short u16;
typedef struct { unsigned char head[12]; u16 count; } RuntimePriorityHeap;
typedef char runtime_frame_pointer_width[sizeof(void *)==4?1:-1];
typedef char runtime_frame_count_offset[(unsigned long)&((RuntimePriorityHeap *)0)->count==12?1:-1];
extern volatile int runtimeFrameTime;
extern int runtimeStopFrame,runtimeClockTime,runtimeDisplayState,runtimeClockTicks,runtimeExitFlag;
extern RuntimePriorityHeap runtimePriorityQueue;
extern unsigned char runtimeOutputQueue[],runtimeStageObject[],runtimeAudioObject[];
extern int func_800AB024(RuntimePriorityHeap *);
extern void func_800D5064(void *);
extern void func_800BBBE0(void);
extern void func_800AB140(RuntimePriorityHeap *,int);
extern void func_800AB8C8(void *);
extern void func_800D5108(void *);
extern void func_800A30E8(void *,int);
int func_800B4578(void) {
 register int frame __asm__("s0")=runtimeFrameTime;
 register int time __asm__("s1");
 int iterations=0;
 runtimeStopFrame=0;
 time=runtimeClockTime+256;
 if(runtimeDisplayState && runtimeClockTime==frame) {
  int future;
  time=frame;
  __asm__("" : : "r"(time), "r"(frame));
  future=0;
  /* With no due event, allow the stage's idle transition to run. */
  switch(runtimePriorityQueue.count) {
  case 0: future=1; break;
  default:
   if(runtimePriorityQueue.count!=0 && func_800AB024(&runtimePriorityQueue)>frame) future=1;
  }
  if(future)func_800D5064(runtimeStageObject);
 }
 while(frame>=time && !runtimeStopFrame) {
  if(time==frame) {
   if(iterations==0)runtimeStopFrame=1;
   else runtimeStopFrame=0;
   iterations++;
  } else runtimeStopFrame=0;
  func_800BBBE0();
  func_800AB140(&runtimePriorityQueue,time);
  func_800AB8C8(runtimeOutputQueue);
  func_800D5108(runtimeStageObject);
  time+=256;
  runtimeClockTicks++;
  frame=runtimeFrameTime;
 }
 func_800A30E8(runtimeAudioObject,runtimeFrameTime>>8);
 return runtimeExitFlag==0;
}
