unsigned char *vgamem = 0xB8000;

void rawputch(char);

int main(char argc, char *argv[])
{
rawputch("A");
rawputch("n");
rawputch("d");
rawputch("r");
rawputch("e");
rawputch("w");

return 0;
}

void rawputch(char c)
{
*vgamem++ = c;
*vgamem++ = 0x07; /* format byte, white on black */

return;
};
