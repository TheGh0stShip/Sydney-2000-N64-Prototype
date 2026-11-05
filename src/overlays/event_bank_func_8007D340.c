/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007D340\n.ent func_8007D340\n"
    "func_8007D340:\n"
    "lui $3,0x800f\n"
    "lw $2,9904($3)\n"
    ".word 0x14400036\n"
    "addiu $16,$3,9904\n"
    "move $4,$18\n"
    "addiu $5,$16,8\n"
    "li $6,40\n"
    "lui $7,0x8007\n"
    "addiu $7,$7,2000\n"
    "sw $18,9904($3)\n"
    "jal func_800AA804\n"
    "sh $17,16($16)\n"
    ".word 0x14400019\n"
    ".end func_8007D340\n.set at\n.set reorder\n");
