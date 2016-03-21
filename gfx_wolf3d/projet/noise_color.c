/*
** noise_color.c for noise in /home/menett_a/Modules/infographie/gfx_wolf3d/projet
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Sat Dec 26 23:51:44 2015 Nicolas Menettrier
** Last update Tue Dec 29 16:53:06 2015 Nicolas Menettrier
*/

#include <lapin.h>

void	noise_color_full(t_bunny_pixelarray *pix,
			 unsigned int color)
{
  int		i;
  t_color	_color;

  _color.argb[0] = 0;
  _color.argb[1] = 127;
  _color.argb[2] = 255;
  _color.argb[3] = 0;
  i = 0;
  while (i != (pix->clipable.clip_height * pix->clipable.clip_width))
    {
      if (i < (pix->clipable.clip_height * pix->clipable.clip_width) / 2)
	((int *)pix->pixels)[i] = _color.full;
      else
	((int *)pix->pixels)[i] = WHITE;
      i = i + 1;
    }
}
