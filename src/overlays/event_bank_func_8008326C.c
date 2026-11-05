/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8008326C\n.ent func_8008326C\n"
    "func_8008326C:\n"
    "lui $6,0x75\n"
    "ori $6,$6,0x3000\n"
    "li $7,1\n"
    "jal func_800CC294\n"
    "addiu $16,$17,16704\n"
    "jal func_80099B70\n"
    "move $4,$16\n"
    "addiu $4,$17,1116\n"
    "jal func_800A9BE8\n"
    "li $5,4\n"
    "addiu $2,$17,1360\n"
    ".end func_8008326C\n.set at\n.set reorder\n");
