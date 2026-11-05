/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800CCB74\n.ent func_800CCB74\n"
    "func_800CCB74:\n"
    "c.le.s $f20,$f4\n"
    "nop\n"
    "bc1f L_800CCB8C\n"
    "li $2,90\n"
    "j func_80071DF8\n"
    "sh $2,4548($19)\n"
    "L_800CCB8C:\n"
    "li $2,80\n"
    "j func_80071DF8\n"
    "sh $2,4548($19)\n"
    ".end func_800CCB74\n.set at\n.set reorder\n");
