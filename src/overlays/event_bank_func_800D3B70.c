/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800D3B70\n.ent func_800D3B70\n"
    "func_800D3B70:\n"
    "andi $3,$3,0xff\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "addu $2,$2,$5\n"
    "lw $5,0($2)\n"
    "j func_8007140C\n"
    "addiu $4,$17,4552\n"
    ".end func_800D3B70\n.set at\n.set reorder\n");
