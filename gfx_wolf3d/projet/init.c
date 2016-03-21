/*
** init.c for init pute in /home/menett_a/Modules/infographie/gfx_wolf3d
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Wed Dec 23 14:03:28 2015 Nicolas Menettrier
** Last update Wed Jan  6 14:33:52 2016 Nicolas Menettrier
*/

#include <lapin.h>
#include <math.h>
#include "include/struct.h"

int	test(float x, float y, t_data *map)
{
  int	i;

  i = 0;
  if (x > map->map.width || y > map->map.height)
    i = 1;
  if (map->map.map[(int)y][(int)x] == 1)
    i = i + 1;
  if (map->map.map[(int)y][(int)x] == 2)
    i = i + 1;
  return (i);
}

void	move(t_bunny_event_state event,
	     t_bunny_keysym key,
	     t_data *map)
{
  float	x;
  float	y;

  x = map->player.posx + cos(map->player.angle * M_PI / 180) * 0.3;
  y = map->player.posy + sin(map->player.angle * M_PI / 180) * 0.3;
  if (event == GO_DOWN && key == BKS_Z
      && test(x, y, map) == 0)
    {
      map->player.posx = map->player.posx +
	cos(map->player.angle * M_PI / 180) * 0.3;
      map->player.posy = map->player.posy +
	sin(map->player.angle * M_PI / 180) * 0.3;
    }
  x = map->player.posx - cos(map->player.angle * M_PI / 180) * 0.3;
  y = map->player.posy - sin(map->player.angle * M_PI / 180) * 0.3;
  if (event == GO_DOWN && key == BKS_S
      && test(x, y, map) == 0)
    {
      map->player.posx = map->player.posx -
	cos(map->player.angle * M_PI / 180) * 0.3;
      map->player.posy = map->player.posy -
	sin(map->player.angle * M_PI / 180) * 0.3;
    }
}

void	erase_wall(t_data *map, float angle)
{
  map->player.x = map->player.posx;
  map->player.y = map->player.posy;
  while (test_map(map) != 2
	 && test_map(map) != 1
	 && map->player.x < map->map.width
	 && map->player.y < map->map.height)
    {
      map->player.x = map->player.x +
	cos((M_PI * map->player.angle) / 180) * 0.01;
      map->player.y = map->player.y +
	sin((M_PI * map->player.angle) / 180) * 0.01;
    }
  if (test_map(map) == 2)
    map->map.map[(int)map->player.y][(int)map->player.x] = 0;
}
