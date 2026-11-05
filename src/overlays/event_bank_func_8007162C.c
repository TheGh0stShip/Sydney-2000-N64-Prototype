/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007162C\n.ent func_8007162C\n"
    "func_8007162C:\n"
    "move $4,$17\n"
    "lui $5,0x8007\n"
    "addiu $5,$5,2648\n"
    "jal func_800AEDC0\n"
    "li $6,20\n"
    "addiu $16,$21,4004\n"
    "move $4,$16\n"
    "jal func_800AC37C\n"
    "move $5,$21\n"
    ".end func_8007162C\n.set at\n.set reorder\n");
