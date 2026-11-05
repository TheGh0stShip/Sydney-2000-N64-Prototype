/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007E834\n.ent func_8007E834\n"
    "func_8007E834:\n"
    "addu $16,$16,$22\n"
    "lw $2,180($16)\n"
    "move $5,$18\n"
    "lh $4,16($2)\n"
    "lw $2,20($2)\n"
    "jalr $2\n"
    "addu $4,$17,$4\n"
    "j func_800754E4\n"
    "andi $3,$19,0xff\n"
    ".end func_8007E834\n.set at\n.set reorder\n");
