#include <stdio.h>

int main() {
	char array[30000] = {0};
	char *p = array; 

p += 1;
*p += 8;
if (*p) do {
    p -= 1;
    *p += 9;
    p += 1;
    *p -= 1;
} while (*p);
p -= 1;
putchar(*p);
p += 1;
*p += 4;
if (*p) do {
    p -= 1;
    *p += 7;
    p += 1;
    *p -= 1;
} while (*p);
p -= 1;
*p += 1;
putchar(*p);
*p += 7;
putchar(*p);
putchar(*p);
*p += 3;
putchar(*p);
p += 2;
*p += 6;
if (*p) do {
    p -= 1;
    *p += 7;
    p += 1;
    *p -= 1;
} while (*p);
p -= 1;
*p += 2;
putchar(*p);
*p -= 12;
putchar(*p);
p += 1;
*p += 6;
if (*p) do {
    p -= 1;
    *p += 9;
    p += 1;
    *p -= 1;
} while (*p);
p -= 1;
*p += 1;
putchar(*p);
p -= 1;
putchar(*p);
*p += 3;
putchar(*p);
*p -= 6;
putchar(*p);
*p -= 8;
putchar(*p);
p += 3;
*p += 4;
if (*p) do {
    p -= 1;
    *p += 8;
    p += 1;
    *p -= 1;
} while (*p);
p -= 1;
*p += 1;
putchar(*p);
	return 0;
}
