ENTRY(_start)
STARTUP(bootloader.o)
INPUT(bootloader.o)
SECTIONS
{
   .text 0x7c00:
   {
      *(.text);

   }
   .data 0x7dfe:
   {
      SHORT(0xaa55);
   }
}
OUTPUT_FORMAT(binary)
OUTPUT(test.bin)
