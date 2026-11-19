#include "sydney_types.h"

/* Destructor of a large container object: destroys its members in reverse order. */
#pragma interface
struct Base { u8 pad0[0xB4]; virtual ~Base(); };
struct ElBase { u8 pad0[0xB4]; virtual ~ElBase(); };
struct El : ElBase { u8 pad[0xD4 - 0xB8]; virtual ~El(); };
struct BigBase { u8 pad0[0xB4]; virtual ~BigBase(); };
struct Big : BigBase { u8 pad[0x578 - 0xB8]; virtual ~Big(); };
struct GBase { u8 pad0[0xB4]; virtual ~GBase(); };
struct G : GBase { u8 pad[0xDC - 0xB8]; virtual ~G() {} };
struct F : G { virtual ~F() {} };
struct J : G { u8 padDC[0x14]; El arr[50]; u8 pad2A58[0x28]; virtual ~J() {} };
struct A { u8 pad[0x1E0]; ~A(); };
struct B { u8 pad[0x578]; ~B(); };
struct C { u8 pad[0x21C]; ~C(); };
struct D { u8 pad[0x198]; ~D(); };
struct E { u8 pad[0x1170]; ~E(); };
struct I { u8 pad[0x1490]; ~I(); };
struct K { u8 pad[0xD4]; ~K(); };
struct L { u8 pad[0xE4]; ~L(); };
struct M { u8 pad[0xF4]; ~M(); };
struct N { u8 pad[0x10]; ~N(); };

struct Obj : Base {
    u8 padB8[0xD8 - 0xB8];
    A a;
    B b;
    Big bigs[3];
    C c;
    D d;
    u8 pad1A4C[0x1C4C - 0x1C4C];
    E e;
    u8 pad2DBC[0x2DBC - 0x2DBC];
    F f1;
    B b2;
    u8 pad3410[0x3410 - 0x3410];
    F f2;
    F f3;
    u8 pad35C8[0x10];
    I i;
    J j;
    K k1;
    El els[3];
    K k2;
    u8 pad790C[4];
    B b3;
    L l;
    M m;
    N n;
    virtual ~Obj();
};
Obj::~Obj() {
}
