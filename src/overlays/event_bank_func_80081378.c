/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80081378\n.ent func_80081378\n"
    "func_80081378:\n"
    "sll $4,$3,0x5\n"
    "subu $4,$4,$3\n"
    "sll $4,$4,0x4\n"
    "addu $4,$4,$19\n"
    "addu $4,$18,$4\n"
    "addiu $16,$16,1\n"
    "mfc1 $6,$f20\n"
    "jal func_800A144C\n"
    "addiu $5,$17,84\n"
    "andi $3,$16,0xff\n"
    "sltiu $2,$3,11\n"
    "bnez $2,func_80081378\n"
    "add.s $f20,$f20,$f22\n"
    ".end func_80081378\n.set at\n.set reorder\n");
