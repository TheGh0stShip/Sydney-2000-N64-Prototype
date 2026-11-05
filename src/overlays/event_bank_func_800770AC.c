/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800770AC\n.ent func_800770AC\n"
    "func_800770AC:\n"
    "slt $2,$3,$12\n"
    ".word 0x10400009\n"
    "sll $2,$6,0x2\n"
    "addiu $3,$29,24\n"
    "addu $2,$3,$2\n"
    "sw $5,0($2)\n"
    ".end func_800770AC\n.set at\n.set reorder\n");
