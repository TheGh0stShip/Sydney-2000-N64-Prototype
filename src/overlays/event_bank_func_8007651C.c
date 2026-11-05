/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007651C\n.ent func_8007651C\n"
    "func_8007651C:\n"
    "li $18,8\n"
    "sb $0,1212($19)\n"
    "lw $4,-15760($16)\n"
    "lbu $7,2573($4)\n"
    "lbu $3,2820($17)\n"
    "move $5,$7\n"
    "mult $3,$5\n"
    "move $6,$0\n"
    "mflo $3\n"
    "sll $2,$3,0x1\n"
    "addu $2,$2,$3\n"
    "sll $2,$2,0x2\n"
    "addiu $2,$2,2576\n"
    ".end func_8007651C\n.set at\n.set reorder\n");
