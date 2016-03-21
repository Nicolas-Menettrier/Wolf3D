/*
** tekpixel.c for tepixel.c in /home/menett_a/Modules/infographie/gfx_wolf3d
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Sat Dec 26 23:08:11 2015 Nicolas Menettrier
** Last update Sat Dec 26 23:21:58 2015 Nicolas Menettrier
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int	_pos;

  _pos = (pos->y * pix->clipable.clip_width) + pos->x;
  ((int *)pix->pixels)[_pos] = color->full;
}
