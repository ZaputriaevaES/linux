#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/csr.h> 

SYSCALL_DEFINE0(riscv_regtbl) 
{
    printk("This is my own syscall\n");
    
    unsigned long csr_value;

    __asm__ volatile ("csrr %0, time" : "=r"(csr_value));

    printk(KERN_INFO "my_custom_call: CSR_TIME = %lu\n", csr_value);

    return csr_value;
    
    return 0;
}