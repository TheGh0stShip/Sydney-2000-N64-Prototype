/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80099728\n.ent func_80099728\n"
    "func_80099728:\n"
    "addiu $2,$2,4\n"
    "addiu $3,$3,1\n"
    "sw $2,12($17)\n"
    "andi $2,$18,0xffff\n"
    ".word 0x1440FFF5\n"
    "sh $3,18($17)\n"
    "j func_800741A4\n"
    "lui $4,0x8007\n"
    ".end func_80099728\n.set at\n.set reorder\n");
