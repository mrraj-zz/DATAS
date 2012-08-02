int main () {
    char greet[] = "hello mate";

    __asm__(
        "movzbl (%0), %%eax\n"
        : : "r"(greet) : "%eax"
    //      ^            ^ do not touch %eax
    //      '- set %0 to a register storing `greet`
    );

    // now %eax should store 'h' (0x68).

    return 0;
}

