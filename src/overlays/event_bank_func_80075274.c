/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_80075274\n.ent func_80075274\n"
    "func_80075274:\n"
    "lw $2,1216($18)\n"
    "addiu $2,$2,-256\n"
    ".word 0x1C40018C\n"
    "sw $2,1216($18)\n"
    "lui $4,0x1\n"
    "ori $4,$4,0x3c8\n"
    "addu $4,$18,$4\n"
    "lui $5,0x8007\n"
    "addiu $5,$5,26096\n"
    "li $6,1\n"
    "li $7,-1\n"
    "lui $16,0x1\n"
    ".end func_80075274\n.set at\n.set reorder\n");
