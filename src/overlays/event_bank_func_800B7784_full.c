typedef unsigned char u8; typedef signed char s8; typedef short s16; typedef int s32; typedef unsigned int u32; typedef float f32;
typedef struct { char p[0x68]; s32 vol; } Snd;
extern void *D_80070908[]; extern Snd D_800F1AE0; extern s32 D_800F2744,D_800F2778; extern char D_800F26E0[];
extern void func_80071244(void); extern void func_80083AD8(u8*); extern void func_8008350C(u8*); extern void func_80083580(u8*,s32); extern void func_80082A84(u8*,s32,s32,s32,s32,s32); extern void func_80082BEC(u8*,s32,s32); extern void func_80082618(u8*);
extern s32 func_800B9BD4(void*,void*,void*,void*,void*,s32); extern s32 func_800B9964(void*,void*,void*,void*); extern void func_800B9FA4(void*,s32,s32,f32,s32,s32); extern void func_800BB9C0(void*,s32,u8*); extern void func_800BB8E0(void*); extern f32 func_800BB8C0(void*); extern void func_800B8C70(void*,f32); extern void func_800BBA1C(void*); extern void func_800C9EF8(void*,s32); extern s32 func_8001D4B8(Snd*,s32,s32,s32); extern void func_8001D640(Snd*,s32,s32); extern void func_800AB2A4(void*,s32,s32,void*,s32,s32);
#define I(o) (*(s32*)(obj+(o)))
#define U(o) (*(u8*)(obj+(o)))
#define S(o) (*(s8*)(obj+(o)))
#define H(o) (*(s16*)(obj+(o)))
#define F(o) (*(f32*)(obj+(o)))
#define P(o) (*(u8**)(obj+(o)))
#define K(a) (*(f32*)(a))
static __inline__ void sfx(s32 id,s32 vol){Snd*s=&D_800F1AE0;func_8001D640(s,func_8001D4B8(s,id,0,1),(s->vol*vol)>>15);}
void func_800B7784(u8 *obj, void *arg)
{
 f32 a[4],b[4],c[2]; s32 t; f32 x;
 if(arg==0) goto end;
 func_80071244();
 {static void *const keep[]={&&L0,&&L1,&&L2,&&L3,&&L4};u32 n=I(0x44b0);if(n>=5)goto end;goto *D_80070908[n];}
L0:
 I(0xf0c)-=0x100;
 if(I(0xf14)==0||I(0xf0c)>=0)goto end;
 func_80083AD8(obj);
 func_800B9FA4(obj+0x11c8,2,-1,F(0x42f0),0,1);
 func_8008350C(obj);
 func_80082A84(obj,2,0,0,0,0);
 func_80082A84(obj,31,0,0,0,0);
 I(0xf0c)=0x5a00;I(0x44b0)=1;I(0x1048)=0;goto end;
L1:
 I(0xf0c)-=0x100;
 func_800B9BD4(obj+0x11c8,arg,a,c,b,0);
 func_800B9964(obj+0x11c8,a,c,b);
 t=I(0xf0c);
 if(t<=0){
  sfx(87,32767);
  I(0x44b0)=2;P(0xf1c)[3]=0;P(0xf1c)[2]=0;I(0xf0c)=I(0xf10);func_80083580(obj,32);I(0x2a54)=1;func_800BBA1C(obj+0x1368);goto end;
 }
 if(t<0xf01){if(t<0xc01)func_80082BEC(obj,31,32);}goto end;
L2:
 {u8*q=obj+0x1368;func_800BB9C0(q,D_800F2744-D_800F2778,P(0xf1c));func_800BB8E0(q);x=func_800BB8C0(q);F(0x42f0)=x;F(0x42f0)=x*F(0x42f8);}
 if(U(0x44b7)==0){if(U(0x44b4)!=0)func_800B8C70(obj+0x11c8,F(0x42f0));else func_800B8C70(obj+0x11c8,F(0x42f4));}
 if(U(0x44b6)==0){
  s32 hit=func_800B9BD4(obj+0x11c8,arg,a,c,b,0);func_800B9964(obj+0x11c8,a,c,b);
  if(hit){
   if(U(0x44b4)==0){if(U(0x44b8)){U(0x44b7)=0;U(0x44b8)=1;U(0x44b4)=1;}else{U(0x44b7)=0;func_800B9FA4(obj+0x11c8,0,-1,F(0x42f0),0,1);U(0x44b4)=1;}}
   else{U(0x44b6)=1;U(0x44b8)=0;U(0x42ec)--;func_800C9EF8(obj+0x2598,(u8)(U(0x42ed)-U(0x42ec)));}
   if(S(0x42ec)==0)I(0x44b0)=3;
  }
 }else if(U(0x44b4)&&U(0x44b5)){U(0x44b6)=0;func_800B9FA4(obj+0x11c8,1,-1,F(0x42f0),0,1);U(0x44b4)=0;U(0x44b5)=0;}
 I(0xf0c)-=0x100;if(I(0xf0c)<=0){I(0x44b0)=3;I(0xf0c)=0;}goto end;
L3:
 func_8008350C(obj);func_80082A84(obj,2,0,0,0,0);func_80082A84(obj,20,0,0,0,0);func_80082A84(obj,43,S(0x42ed),0,0,0);func_80082A84(obj,45,S(0x42ed)-S(0x42ec),0,0,0);
 if(S(0x42ec)==0){f32 q=((f32)I(0xf0c)/K(0x8007091c)*K(0x80070920))/((f32)I(0xf10)/K(0x8007091c)*K(0x80070920))*K(0x80070924);if(q>=K(0x80070928))H(0x11c4)=100;else if(q>=K(0x8007092c))H(0x11c4)=90;else H(0x11c4)=80;}else H(0x11c4)=0;
 func_80082618(obj);I(0xf0c)=0x7800;I(0x44b0)=4;I(0xf14)=0;goto end;
L4:
 I(0xf0c)-=0x100;if(I(0xf14)!=0&&I(0xf0c)<=0)func_800AB2A4(D_800F26E0,D_800F2744,7,obj,0,7);
end:;
}
