/*
** tekpixel.c for tek in /home/menett_a/Modules/infographie/gfx_wolf3d/projet
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Sat Dec 26 23:50:28 2015 Nicolas Menettrier
** Last update Sat Dec 26 23:51:04 2015 Nicolas Menettrier
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 unsigned int color)
{
  int	_pos;

  _pos = (pos->y * pix->clipable.clip_width) + pos->x;
  ((int *)pix->pixels)[_pos] = color;
}
