#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



void print_hex(int n)
{
  char *digits16;
  char digit;

  digits16="0123456789abcdef";
  if (n)
    {
      print_hex(n/16);
      digit = digits16[n%16];
      write (1, &digits16[n%16], 1);
    }
}
  
int ft_is_printable();

void ft_putstr_non_printable (char *str)
{
  char c;
  
  c=*str;
  while (c)
    {
      if (ft_is_printable(c))
	{
	  write (1, &c, 1);
	}
      else
	{
	  write (1, "\\", 1);
	  print_hex(c);
	}
      str++;
      c=*str;}
}

int main()
{
  ft_putstr_non_printable ("print_hex");
}