/*
** struct.h for struct in /home/menett_a/Modules/infographie/colle_fin_module/gfx_colle_fantasy1
**
** Made by Nicolas Menettrier
** Login   <menett_a@epitech.net>
**
** Started on  Mon Dec 21 14:43:38 2015 Nicolas Menettrier
** Last update Wed Dec 23 17:56:12 2015 Nicolas Menettrier
*/

#ifndef STRUCT_H_
# define STRUCT_H_
#include <lapin.h>

typedef	struct	s_map
{
  int		**map;
  const char	*l_n;
  int		width;
  int		height;
  int		til_siz;
  float		start[3];
}		t_map;

typedef struct	s_player
{
  float		angle;
  float		posx;
  float		posy;
  float		x;
  float		y;
}		t_player;

typedef struct		s_data
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_position	*pos;
  t_color		color;
  t_map			map;
  t_player		player;
}			t_data;

#endif /* !STRUCT_H_ */
