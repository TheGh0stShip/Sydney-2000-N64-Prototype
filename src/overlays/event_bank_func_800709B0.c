/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800709B0\n.ent func_800709B0\n"
    "func_800709B0:\n"
    "move $4,$17\n"
    "addiu $5,$17,1512\n"
    "addiu $6,$17,2532\n"
    "jal func_800738B8\n"
    "li $7,1\n"
    "j func_80070F00\n"
    "nop\n"
    ".end func_800709B0\n.set at\n.set reorder\n");
