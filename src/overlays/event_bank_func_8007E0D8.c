/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E0D8\n.ent func_8007E0D8\n"
    "func_8007E0D8:\n"
    "addiu $7,$7,4872\n"
    ".word 0x16C00028\n"
    "nop\n"
    "jal func_80017A90\n"
    "lui $4,0x4000\n"
    "lb $3,1780($16)\n"
    "andi $2,$20,0xff\n"
    ".word 0x10430016\n"
    "li $2,-1\n"
    ".word 0x10620006\n"
    ".end func_8007E0D8\n.set at\n.set reorder\n");
