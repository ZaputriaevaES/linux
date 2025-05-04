#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/ptrace.h>
#include <asm/csr.h>
#include <asm/sbi.h>

// Extension id-number of my sbi-call
#define SBI_EXT_CSR_DUMP 0x43535244  // "CSRD" in ASCII

SYSCALL_DEFINE0(riscv_regtbl) 
{
    struct pt_regs *regs = current_pt_regs();

    // GP-register table
    printk(KERN_INFO "General Purpose Registers (GP):");
    printk(KERN_INFO "Register | Hex Value          | Dec Value");
    printk(KERN_INFO "---------|--------------------|------------");
    printk(KERN_INFO "ra       | 0x%016lx | %ld", regs->ra, regs->ra);
    printk(KERN_INFO "sp       | 0x%016lx | %ld", regs->sp, regs->sp);
    printk(KERN_INFO "gp       | 0x%016lx | %ld", regs->gp, regs->gp);
    printk(KERN_INFO "tp       | 0x%016lx | %ld", regs->tp, regs->tp);
    printk(KERN_INFO "a0       | 0x%016lx | %ld", regs->a0, regs->a0);
    printk(KERN_INFO "a1       | 0x%016lx | %ld", regs->a1, regs->a1);
    printk(KERN_INFO "---------|--------------------|------------");
    
    unsigned long mstatus = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MSTATUS, 0, 0, 0, 0, 0).value;
    unsigned long mepc    = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MEPC, 0, 0, 0, 0, 0).value;
    unsigned long mtval   = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MTVAL, 0, 0, 0, 0, 0).value;
    unsigned long mhartid = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MHARTID, 0, 0, 0, 0, 0).value;
    
    // int mstatus_error = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MSTATUS, 0, 0, 0, 0, 0).error;
    // int mepc_error    = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MEPC, 0, 0, 0, 0, 0).error;
    // int mtval_error   = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MTVAL, 0, 0, 0, 0, 0).error;
    // int mhartid_error = sbi_ecall(SBI_EXT_CSR_DUMP, 0, CSR_MHARTID, 0, 0, 0, 0, 0).error;
    // printk("SBI error code: %d\n", mstatus_error);
    // printk("SBI error code: %d\n", mepc_error);
    // printk("SBI error code: %d\n", mtval_error);
    // printk("SBI error code: %d\n", mhartid_error);
    
    // CSR-register table
    printk(KERN_INFO "Control/Status Registers (CSR):");
    printk(KERN_INFO "Register | Hex Value          | Dec Value");
    printk(KERN_INFO "---------|--------------------|------------");
    printk(KERN_INFO "mstatus  | 0x%016lx | %ld", mstatus, mstatus);
    printk(KERN_INFO "mepc     | 0x%016lx | %ld", mepc, mepc);
    printk(KERN_INFO "mtval    | 0x%016lx | %ld", mtval, mtval);
    printk(KERN_INFO "mhartid  | 0x%016lx | %ld", mhartid, mhartid);
    printk(KERN_INFO "---------|--------------------|------------");
    printk(KERN_INFO "---------|--------------------|------------");

    return 0;
}