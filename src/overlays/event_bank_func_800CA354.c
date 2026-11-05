/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CA354\n.ent func_800CA354\n"
    "func_800CA354:\n"
    "sb $2,1($3)\n"
    "sw $5,18232($18)\n"
    "sw $0,16($29)\n"
    "lb $5,1($3)\n"
    "lw $7,18212($18)\n"
    "jal func_800B9E9C\n"
    "li $6,-1\n"
    "j func_80071AC0\n"
    "sb $0,18187($18)\n"
    ".end func_800CA354\n.set at\n.set reorder\n");
