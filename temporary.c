#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *p;
  unsigned long int add;
  intptr_t adress = (intptr_t) p;
  char *hexadress[17];
  p="Bonjour les amin";

  printf ("%p", p);
  write (1, adress, 16);
}
