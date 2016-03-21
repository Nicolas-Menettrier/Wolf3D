/*
** vecnorm.c for vecnorm in /home/menett_a/Modules/infographie/gfx_wolf3d/tcore
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Sat Dec 26 23:16:23 2015 Nicolas Menettrier
** Last update Sat Dec 26 23:21:46 2015 Nicolas Menettrier
*/

#include <lapin.h>
#include <math.h>

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	length;

  length = sqrt(pow(coord1->x - coord0->x, 2) +
		pow(coord1->y - coord0->y, 2));
  return (length);
}
