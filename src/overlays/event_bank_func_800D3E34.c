/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D3E34\n.ent func_800D3E34\n"
    "func_800D3E34:\n"
    "addiu $4,$17,4552\n"
    "lui $2,0x8007\n"
    "lw $5,9788($2)\n"
    "j func_80070DA4\n"
    "addiu $4,$17,4552\n"
    ".end func_800D3E34\n.set at\n.set reorder\n");
