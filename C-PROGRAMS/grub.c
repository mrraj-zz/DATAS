void main(unsigned long magic, unsigned long address)			//Swap depending which you pushed first.
{
	multiboot_info_t *mbi = (multiboot_info_t*)addr;	
	unsigned long total_memory_size = ((unsigned long)mbi->mem_lower + (unsigned long)mbi->mem_upper);
}
