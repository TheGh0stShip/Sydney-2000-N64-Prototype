/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800730BC\n.ent func_800730BC\n"
    "func_800730BC:\n"
    "sw $16,192($29)\n"
    "andi $18,$21,0xff\n"
    "sltiu $2,$18,3\n"
    ".word 0x1040005F\n"
    "li $5,15\n"
    "addiu $6,$29,16\n"
    "sll $17,$18,0x1\n"
    "addu $17,$17,$18\n"
    "sll $16,$17,0x3\n"
    "addu $16,$16,$18\n"
    "sll $16,$16,0x2\n"
    "addu $16,$16,$18\n"
    "sll $16,$16,0x2\n"
    "addu $2,$16,$22\n"
    ".end func_800730BC\n.set at\n.set reorder\n");
