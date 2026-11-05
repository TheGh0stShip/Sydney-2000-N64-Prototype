/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800DB0F4\n.ent func_800DB0F4\n"
    "func_800DB0F4:\n"
    "andi $2,$6,0xffff\n"
    "beqz $2,L_800DB11C\n"
    "addiu $6,$6,-1\n"
    "lhu $2,0($5)\n"
    "sh $2,0($4)\n"
    "lhu $2,0($5)\n"
    "beqz $2,func_800DB0F4\n"
    "addiu $4,$4,2\n"
    "j func_800DB0F4\n"
    "addiu $5,$5,2\n"
    "L_800DB11C:\n"
    "jr $31\n"
    "nop\n"
    ".end func_800DB0F4\n.set at\n.set reorder\n");
