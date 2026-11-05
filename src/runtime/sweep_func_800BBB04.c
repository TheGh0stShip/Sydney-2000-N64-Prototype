/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BBB04\n.ent func_800BBB04\n"
    "func_800BBB04:\n"
    "lhu $2,2($4)\n"
    "addu $2,$2,$5\n"
    "sll $2,$2,0x10\n"
    "sra $2,$2,0x10\n"
    "bgez $2,L_800BBB24\n"
    "sll $2,$2,0x3\n"
    "jr $31\n"
    "move $2,$0\n"
    "L_800BBB24:\n"
    "lw $3,4($4)\n"
    "jr $31\n"
    "addu $2,$3,$2\n"
    ".end func_800BBB04\n.set at\n.set reorder\n");
