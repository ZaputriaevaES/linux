#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/ptrace.h>
#include <asm/csr.h>

SYSCALL_DEFINE0(riscv_regtbl) 
{
    struct pt_regs *regs = current_pt_regs();

    // Таблица GP-регистров
    printk(KERN_INFO "General Purpose Registers:");
    printk(KERN_INFO "Register | Hex Value          | Dec Value");
    printk(KERN_INFO "---------|--------------------|------------");
    printk(KERN_INFO "ra       | 0x%016lx | %ld", regs->ra, regs->ra);
    printk(KERN_INFO "sp       | 0x%016lx | %ld", regs->sp, regs->sp);
    printk(KERN_INFO "gp       | 0x%016lx | %ld", regs->gp, regs->gp);
    printk(KERN_INFO "tp       | 0x%016lx | %ld", regs->tp, regs->tp);
    printk(KERN_INFO "a0       | 0x%016lx | %ld", regs->a0, regs->a0);
    printk(KERN_INFO "a1       | 0x%016lx | %ld", regs->a1, regs->a1);
    printk(KERN_INFO "---------|--------------------|------------");

    // // Таблица CSR-регистров
    // printk(KERN_INFO "\nControl/Status Registers (CSR):");
    // printk(KERN_INFO "CSR      | Hex Value    | Description");
    // printk(KERN_INFO "---------|-------------|----------------");
    // printk(KERN_INFO "mstatus  | 0x%08lx   | Machine status", csr_read(CSR_MSTATUS));
    // printk(KERN_INFO "mepc     | 0x%08lx   | Exception PC", csr_read(CSR_MEPC));
    // printk(KERN_INFO "mtval    | 0x%08lx   | Trap value", csr_read(CSR_MTVAL));
    // printk(KERN_INFO "mhartid  | 0x%08lx   | Hardware thread ID", csr_read(CSR_MHARTID));
    
    return 0;
}