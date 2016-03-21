/*
** go.c for go in /home/menett_a/Modules/infographie/gfx_wolf3d/tcore
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Sat Dec 26 23:23:15 2015 Nicolas Menettrier
** Last update Tue Dec 29 14:30:59 2015 Nicolas Menettrier
*/

#include <lapin.h>
#include <math.h>

void	go(t_bunny_position *curpos,
	   double angle,
	   t_bunny_position *newpos,
	   int move)
{
  newpos->x = curpos->x + cos(angle) * move;
  newpos->y = curpos->y + sin(angle) * move;
}
