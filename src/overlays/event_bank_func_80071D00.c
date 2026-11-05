/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071D00\n.ent func_80071D00\n"
    "func_80071D00:\n"
    "lui $4,0x8007\n"
    "addiu $4,$4,2952\n"
    "move $5,$16\n"
    "move $6,$0\n"
    "jal func_80013E7C\n"
    ".end func_80071D00\n.set at\n.set reorder\n");
