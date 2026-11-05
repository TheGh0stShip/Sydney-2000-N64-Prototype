/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800B32D4\n.ent func_800B32D4\n"
    "func_800B32D4:\n"
    "addiu $3,$3,1\n"
    "sw $2,12($16)\n"
    "andi $2,$17,0xffff\n"
    ".word 0x1440FFF5\n"
    "sh $3,18($16)\n"
    "j func_8007416C\n"
    "nop\n"
    ".end func_800B32D4\n.set at\n.set reorder\n");
