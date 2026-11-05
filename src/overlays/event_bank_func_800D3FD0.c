/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D3FD0\n.ent func_800D3FD0\n"
    "func_800D3FD0:\n"
    "subu $3,$6,$3\n"
    "andi $3,$3,0xff\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "j func_80071408\n"
    "addu $2,$2,$5\n"
    ".end func_800D3FD0\n.set at\n.set reorder\n");
