/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007232C\n.ent func_8007232C\n"
    "func_8007232C:\n"
    "addiu $4,$4,10072\n"
    "jal func_800AA658\n"
    "addiu $5,$19,200\n"
    "jal func_800AC334\n"
    "move $4,$16\n"
    "jal func_800A7910\n"
    "move $4,$16\n"
    "jal func_800AC308\n"
    "move $4,$19\n"
    "jal func_80017A90\n"
    "lui $4,0x8000\n"
    ".end func_8007232C\n.set at\n.set reorder\n");
