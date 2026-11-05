/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075DB4\n.ent func_80075DB4\n"
    "func_80075DB4:\n"
    "lhu $3,18($16)\n"
    "addiu $2,$2,4\n"
    "addiu $3,$3,1\n"
    "sw $2,12($16)\n"
    "andi $2,$17,0xffff\n"
    ".word 0x1440FFF5\n"
    "sh $3,18($16)\n"
    "j func_80072AC8\n"
    "lui $17,0x1\n"
    ".end func_80075DB4\n.set at\n.set reorder\n");
