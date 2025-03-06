// int2str.c
// ENCM 369 Winter 2025 Lab 6 Exercise G

#include <stdio.h>

char digits[] = "0123456789";

void int2str(char *dest, int src)
{
  unsigned abs_src, ten, rem, temp;
  char *p, *q;

  if (src == 0)
  {
    dest[0] = '0';
    dest[1] = '\0';
    return;
  }

  if (src == -2147483648) // check for 32-bit "weird number"
    abs_src = 0x80000000u;
  else if (src < 0)
    abs_src = -src;
  else
    abs_src = src;

  // compute and store decimal digits of abs_src
  p = dest;
  ten = 10u;
  while (abs_src != 0)
  {
    rem = abs_src % ten;
    *p = digits[rem];
    p++;
    abs_src /= ten;
  }

  // store '-' if necessary, then terminate string
  if (src < 0)
  {
    *p = '-';
    p++;
  }
  *p = '\0';

  // reverse order of chars in string
  q = p - 1;
  p = dest;
  while (p < q)
  {
    temp = *p;
    *p = *q;
    *q = temp;
    p++;
    q--;
  }
}

char buf[12];
char finish[] = "\"\n";

void try_it(const char *msg, int src)
{
  int2str(buf, src);
  fputs(msg, stdout);
  fputs(buf, stdout);
  fputs(finish, stdout);
}

int main(void)
{
  try_it("try #1: \"", 0);
  try_it("try #2: \"", 1);
  try_it("try #3: \"", -1);
  try_it("try #4: \"", -2147483648);
  try_it("try #5: \"", -2147483647);
  try_it("try #6: \"", 2147483647);
  try_it("try #7: \"", 123);
  try_it("try #8: \"", -456789);
  return 0;
}
