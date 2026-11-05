/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007620C\n.ent func_8007620C\n"
    "func_8007620C:\n"
    "sb $3,3385($16)\n"
    "jal func_800177AC\n"
    "sb $0,3386($16)\n"
    "lw $31,44($29)\n"
    "lw $20,40($29)\n"
    "lw $19,36($29)\n"
    ".end func_8007620C\n.set at\n.set reorder\n");
