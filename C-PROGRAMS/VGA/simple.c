    #include <stdlib.h>
    #include <vga.h>

    int main(void)
    {
       vga_init();
       vga_setmode(vga_getdefaultmode());
       vga_setcolor(4);
       vga_drawpixel(10, 10);

       sleep(5);
       vga_setmode(TEXT);

       return EXIT_SUCCESS;
    }

