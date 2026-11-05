/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8009A64C\n.ent func_8009A64C\n"
    "func_8009A64C:\n"
    "lwc1 $f4,32($29)\n"
    "lui $1,0x8007\n"
    "lwc1 $f2,5196($1)\n"
    "c.le.s $f4,$f0\n"
    "mul.s $f0,$f6,$f2\n"
    ".word 0x45000009\n"
    "li $2,0x8000\n"
    "addu $2,$17,$2\n"
    "lbu $3,84($2)\n"
    "li $2,5\n"
    ".word 0x14620021\n"
    "li $16,202\n"
    "li $16,122\n"
    ".end func_8009A64C\n.set at\n.set reorder\n");
