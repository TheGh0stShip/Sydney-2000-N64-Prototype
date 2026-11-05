/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_8007735C\n.ent func_8007735C\n"
    "func_8007735C:\n"
    "sh $2,0($16)\n"
    "addiu $16,$16,12\n"
    "addiu $17,$17,12\n"
    "j func_80073ECC\n"
    "addiu $18,$18,1\n"
    ".end func_8007735C\n.set at\n.set reorder\n");
