#include<stdio.h>
#include<linux/types.h>

struct idt {
	unsigned int length;
	unsigned int pointer;
}__attribute__((packed));

void main(void)
{
        static const __u64 boot_gdt[] __attribute__((aligned(16))) = {
                /* CS: code, read/execute, 4 GB, base 0 */
                [GDT_ENTRY_BOOT_CS] = GDT_ENTRY(0xc09b, 0, 0xfffff),
                /* DS: data, read/write, 4 GB, base 0 */
                [GDT_ENTRY_BOOT_DS] = GDT_ENTRY(0xc093, 0, 0xfffff),
                /* TSS: 32-bit tss, 104 bytes, base 4096 */
                /* We only have a TSS here to keep Intel VT happy;
                   we don't actually use it for anything. */
                [GDT_ENTRY_BOOT_TSS] = GDT_ENTRY(0x0089, 4096, 103),
        };
        /* Xen HVM incorrectly stores a pointer to the gdt_ptr, instead
           of the gdt_ptr contents.  Thus, make it static so it will
           stay in memory, at least long enough that we switch to the
           proper kernel GDT. */
        static struct gdt_ptr gdt;

        gdt.len = sizeof(boot_gdt)-1;
        gdt.ptr = (u32)&boot_gdt + (ds() << 4);

        asm volatile("lgdtl %0" : : "m" (gdt));

}
