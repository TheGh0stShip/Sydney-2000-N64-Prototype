/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BB8C0\n.ent func_800BB8C0\n"
    "func_800BB8C0:\n"
    "move $5,$18\n"
    "addiu $6,$29,24\n"
    "addiu $18,$29,56\n"
    "move $7,$18\n"
    "lw $2,3852($19)\n"
    "addiu $17,$29,40\n"
    "addiu $2,$2,-256\n"
    "sw $2,3852($19)\n"
    ".end func_800BB8C0\n.set at\n.set reorder\n");
