/*
** read_map.c for read_wolf in /home/menett_a/Modules/infographie/gfx_wolf3d
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Tue Dec 22 12:28:57 2015 Nicolas Menettrier
** Last update Wed Jan  6 14:30:08 2016 Nicolas Menettrier
*/

#include <lapin.h>
#include "include/struct.h"

void	my_putstr_const(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

void	stock_map(t_data *mp, t_bunny_ini *ini)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  k = 0;
  while (j < mp->map.height)
    {
      i = 0;
      while (i < mp->map.width)
	{
	  mp->map.map[j][i] =
	    my_getnbr(bunny_ini_get_field(ini, "level1", "data", k));
	  i = i + 1;
	  k = k + 1;
	}
      j = j + 1;
    }
  mp->map.start[0] =
    my_getnbr(bunny_ini_get_field(ini, "level1", "start_position", 0));
  mp->map.start[1] =
    my_getnbr(bunny_ini_get_field(ini, "level1", "start_position", 1));
  mp->map.start[2] =
    my_getnbr(bunny_ini_get_field(ini, "level1", "start_position", 2));
}

char		*get_wolf(t_data *map, char *map_name)
{
  t_bunny_ini	*ini;
  int		i;

  i = 0;
  if ((ini = bunny_load_ini(map_name)) == NULL)
    return ("Error load ini\n");
  map->map.l_n = bunny_ini_get_field(ini, "level1", "name", 0);
  map->map.height = my_getnbr(bunny_ini_get_field(ini, "level1", "height", 0));
  map->map.width = my_getnbr(bunny_ini_get_field(ini, "level1", "width", 0));
  if ((map->map.map = malloc(sizeof(int *) * map->map.height)) == NULL)
    return ("malloc error\n");
  while (i < map->map.height)
    {
      if ((map->map.map[i] = malloc(sizeof(int) * map->map.width)) == NULL)
	return ("malloc error\n");
      i = i + 1;
    }
  stock_map(map, ini);
  return (NULL);
}
