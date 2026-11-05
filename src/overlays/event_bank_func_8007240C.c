/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007240C\n.ent func_8007240C\n"
    "func_8007240C:\n"
    "addu $4,$16,$19\n"
    "addiu $4,$4,3468\n"
    "sll $2,$3,0x2\n"
    "addu $2,$17,$2\n"
    "lw $5,268($2)\n"
    "li $6,76\n"
    "jal func_800B3870\n"
    "addiu $5,$5,20\n"
    "lbu $2,4000($19)\n"
    ".word 0x10400005\n"
    "addu $2,$19,$16\n"
    "lwc1 $f0,3540($2)\n"
    ".end func_8007240C\n.set at\n.set reorder\n");
