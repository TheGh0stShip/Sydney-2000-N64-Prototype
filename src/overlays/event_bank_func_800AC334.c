/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800AC334\n.ent func_800AC334\n"
    "func_800AC334:\n"
    "addiu $2,$2,4\n"
    "addiu $3,$3,1\n"
    "sw $2,12($17)\n"
    "andi $2,$18,0xffff\n"
    ".word 0x1440FFF5\n"
    "sh $3,18($17)\n"
    "j func_80074690\n"
    "lui $4,0x800f\n"
    ".end func_800AC334\n.set at\n.set reorder\n");
