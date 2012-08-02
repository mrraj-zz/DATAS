/*
* Attribute for variable `packed' specifies that a variable or structure field
* should have the smallest possible alignment, unless a larger value is
* supplied with the `aligned' attribute.
* That is extremely useful if the data is to be transfered in the binary form
* to another computer with possibly different alignment boundary.
*/
 
#include <stdio.h>
#include <stdint.h>
 
/*
* Variables aligned by default
* The size of the following structure, and offsets of its variables may differ
* for different hosts.
*/
struct Default {
int8_t i1;
int16_t i2;
int32_t i4;
int64_t i8;
int16_t f1;
int16_t f2;
};
 
/*
* 'packed' shall use the smallest of possible alignments - 1 byte
* The size of the following structure, and offsets of its variables should not
* differ on different computers
*/
struct Packed {
int8_t i1;
int16_t i2 __attribute__((packed));
int32_t i4 __attribute__((packed));
int64_t i8 __attribute__((packed));
int16_t f1 : 4 __attribute__((packed));
int16_t f2 : 4 __attribute__((packed));
};
 
int
main()
{
printf("Default alignment:\n");
printf(" offset of i1 %zu\n", offsetof(struct Default, i1));
printf(" offset of i2 %zu\n", offsetof(struct Default, i2));
printf(" offset of i4 %zu\n", offsetof(struct Default, i4));
printf(" offset of i8 %zu\n", offsetof(struct Default, i8));
printf(" size of struct %zu\n", sizeof(struct Default));
 
printf("Alignment 1:\n");
printf(" offset of i1 %zu\n", offsetof(struct Packed, i1));
printf(" offset of i2 %zu\n", offsetof(struct Packed, i2));
printf(" offset of i4 %zu\n", offsetof(struct Packed, i4));
printf(" offset of i8 %zu\n", offsetof(struct Packed, i8));
printf(" size of struct %zu\n", sizeof(struct Packed));
 
return 0;
}
