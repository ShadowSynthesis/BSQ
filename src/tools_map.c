/*
** tools_map.c for  in /home/soussa_y/rendu/CPE_2015_BSQ
**
** Made by yoram soussan
** Login   <soussa_y@epitech.net>
**
** Started on  Sun Dec 20 23:10:34 2015 yoram soussan
** Last update Sun Dec 20 23:10:35 2015 yoram soussan
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/bsq.h"
#include "../include/my.h"

t_pt2	*alloc_coin(t_pt2 *coin, int index, int count, int val)
{
  if ((coin = malloc(sizeof(t_pt2))) == NULL)
    {
      my_putstr("Error : malloc\n");
      return (coin);
    }
  coin->val = val;
  coin->x = index;
  coin->y = count;
  return (coin);
}

int	remplir_mat(char **map, t_pt2 **matr, t_pt2 *dim)
{
  int	i;
  int	j;

  i = -1;
  while (++i < dim->x)
    {
      j= -1;
      while (++j < dim->y)
	if (map[i][j] == 'o')
	  {
	    matr[i][j].val = 0;
	    matr[i][j].x =  0;
	    matr[i][j].y =  0;
	  }
	else
	  {
	    matr[i][j].val = 1;
	    matr[i][j].x = matr[i][j].val + (j == 0 ? 0 : matr[i][j-1].x);
	    matr[i][j].y = matr[i][j].val + (i == 0 ? 0 : matr[i-1][j].y);
	  }
    }
  return (0);
}

int	offset_coin(t_pt2 *coin, int j, t_pt2 *dim, int taille)
{
  if (coin->y + j >= dim->y)
    {
      if (coin->x + 1 == dim->x)
	return (-1);
      coin->x += 1;
      coin->y = -1;
    }
  coin->y += j;
  coin->val = 0;
  if ((coin->x + taille >= dim->x) && (coin->y + taille >= dim->y))
    return (-1);
  return (0);
}

t_pt2	*save(t_pt2 *coin, t_pt2 *coin2)
{
  coin2->val = coin->val;
  coin2->x = coin->x;
  coin2->y = coin->y;
  return (coin2);
}
