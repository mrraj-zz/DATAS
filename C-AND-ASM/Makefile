main_c_s : main_c.o main_s.o
    gcc main_c.o main_s.o -o main_c_s
main_c.o :
    gcc -g -c main_c.c -o main_c.o
main_s.o :
    nasm -f elf main_s.s -o main_s.o
