/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800A0CF4\n.ent func_800A0CF4\n"
    "func_800A0CF4:\n"
    "addiu $4,$29,16\n"
    "lbu $5,1($5)\n"
    "sll $6,$6,0x18\n"
    "jal func_8009A828\n"
    "sra $6,$6,0x18\n"
    "move $4,$16\n"
    "jal func_80072F18\n"
    "addiu $5,$29,16\n"
    "j func_80074F64\n"
    "nop\n"
    ".end func_800A0CF4\n.set at\n.set reorder\n");
