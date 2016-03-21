/*
** raycasting.c for raycasting in /home/menett_a/Modules/infographie/gfx_wolf3d
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Tue Dec 22 19:27:12 2015 Nicolas Menettrier
** Last update Sun Dec 27 21:38:19 2015 Nicolas Menettrier
*/

#include <lapin.h>
#include <math.h>
#include "include/proto.h"
#include "include/struct.h"

void			my_draw_line(float len, t_data *m, int i, float angle)
{
  t_bunny_position	pos[2];
  int			count;
  float			_angle[2];
  t_color		_color;

  _angle[0] = angle * M_PI / 180;
  _angle[1] = m->player.angle * M_PI / 180;
  count = 0;
  pos[0].x = i;
  pos[0].y = m->pix->clipable.clip_height / 2;
  pos[1].x = pos[0].x;
  pos[1].y = pos[0].y;
  len = len * cos(fabs(_angle[1] - _angle[0]));
  _color.full = m->color.full;
  if (test_map(m) == 2)
    _color.full = GREEN;
  while (count < (20 / len) * 20 && count < m->pix->clipable.clip_height / 2)
    {
      tekpixel(m->pix, &pos[0], _color.full);
      tekpixel(m->pix, &pos[1], _color.full);
      pos[0].y = pos[0].y - 1;
      pos[1].y = pos[1].y + 1;
      count = count + 1;
    }
}

int	test_map(t_data *world)
{
  int	i;

  i = 0;
  if (world->map.map[(int)world->player.y][(int)world->player.x] == 1)
    i = 1;
  if (world->map.map[(int)world->player.y][(int)world->player.x] == 2)
    i = 2;
  return (i);
}

void	raycasting(t_data *world)
{
  float	angle;
  float	len;
  int	i;

  i = 0;
  angle = world->player.angle - 30;
  while (i < world->pix->clipable.clip_width)
    {
      world->player.x = world->player.posx;
      world->player.y = world->player.posy;
      while (test_map(world) != 1 && test_map(world) != 2
	     && world->player.x < world->map.width
	     && world->player.y < world->map.height)
	{
	  world->player.x = world->player.x + cos((M_PI * angle) / 180) * 0.01;
	  world->player.y = world->player.y + sin((M_PI * angle) / 180) * 0.01;
	}
      len = sqrt(pow(world->player.x - world->player.posx, 2) +
		 pow(world->player.y - world->player.posy, 2));
      if (world->player.x < world->map.width
	  && world->player.y < world->map.height)
	my_draw_line(len, world, i, angle);
      i = i + 1;
      angle = (float)angle + 60 / (float)world->pix->clipable.clip_width;
    }
}

void			put_cursor(t_data *map)
{
  t_bunny_position	pos;
  int			i;

  i = -5;
  while (i < 6)
    {
      pos.x = map->pix->clipable.clip_width / 2;
      pos.y = map->pix->clipable.clip_height / 2 + i;
      tekpixel(map->pix, &pos, BLUE);
      i = i + 1;
    }
  i = -5;
  while (i < 6)
    {
      pos.y = map->pix->clipable.clip_height / 2;
      pos.x = map->pix->clipable.clip_width / 2 + i;
      tekpixel(map->pix, &pos, BLUE);
      i = i + 1;
    }
}
