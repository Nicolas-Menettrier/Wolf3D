/*
** my_putstr.c for my_putstr in /home/menett_a/Modules/infographie/gfx_wolf3d
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Tue Dec 22 13:50:45 2015 Nicolas Menettrier
** Last update Wed Dec 23 13:27:06 2015 Nicolas Menettrier
*/

#include "include/struct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
