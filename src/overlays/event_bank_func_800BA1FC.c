/* Symbolic reconstruction of the reviewed overlay routine. */
__asm__(
    ".set noreorder\n.set noat\n.text\n.globl func_800BA1FC\n.ent func_800BA1FC\n"
    "func_800BA1FC:\n"
    "beqz $2,L_800BA214\n"
    "li $2,2\n"
    ".word 0x106000AC\n"
    "andi $2,$17,0xff\n"
    "j func_80072144\n"
    "sll $2,$2,0x2\n"
    "L_800BA214:\n"
    ".word 0x10620082\n"
    "li $2,3\n"
    ".word 0x1062003F\n"
    "andi $2,$17,0xff\n"
    "j func_80072144\n"
    "sll $2,$2,0x2\n"
    ".end func_800BA1FC\n.set at\n.set reorder\n");
