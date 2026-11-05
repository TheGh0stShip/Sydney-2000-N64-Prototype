/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800760AC\n.ent func_800760AC\n"
    "func_800760AC:\n"
    "sltiu $2,$3,2\n"
    ".word 0x10400008\n"
    "sll $2,$3,0x3\n"
    "addu $2,$2,$20\n"
    "addiu $2,$2,1568\n"
    ".end func_800760AC\n.set at\n.set reorder\n");
