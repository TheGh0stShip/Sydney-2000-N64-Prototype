/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80071650\n.ent func_80071650\n"
    "func_80071650:\n"
    "move $4,$16\n"
    "addiu $5,$21,2936\n"
    "lui $6,0x8007\n"
    "addiu $6,$6,2668\n"
    "jal func_800A97D4\n"
    "move $7,$17\n"
    "lw $8,52($29)\n"
    "lw $2,12($8)\n"
    "addiu $2,$2,-3\n"
    "sltiu $2,$2,2\n"
    ".word 0x10400003\n"
    "lui $4,0x8007\n"
    "j func_80071B80\n"
    ".end func_80071650\n.set at\n.set reorder\n");
