/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075D88\n.ent func_80075D88\n"
    "func_80075D88:\n"
    "addiu $7,$7,2008\n"
    ".word 0x14400012\n"
    "nop\n"
    "lw $2,8($16)\n"
    "lw $4,4($16)\n"
    "sw $2,12($16)\n"
    ".end func_80075D88\n.set at\n.set reorder\n");
