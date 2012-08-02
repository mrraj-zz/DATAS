#include<stdio.h>
#include<linux/types.h>

struct gdt_entry {
	__u16 limit_low;
	__u16 base_low;
	__u8 base_middle;
	__u8 access;
	__u8 granularity;
	__u8 base_high;
}__attribute__((packed));

struct entry {
	__u16 limit;
	__u16 base;
} __attribute__((packed));

typedef struct gdt_entry gdt_entry;
typedef struct entry entry;

void main(void)
{
	struct gdt_entry gdt_ent[5];
	struct entry ent;

	ent.limit = sizeof(gdt_entry)*5 - 1;
	ent.base = (__u32)&gdt_ent;

	printf("limit : %d \n", ent.limit);
	printf("base : %u \n", ent.base);

}
