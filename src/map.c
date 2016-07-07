/*
** map.c for  in /home/soussa_y/rendu/CPE_2015_BSQ
**
** Made by yoram soussan
** Login   <soussa_y@epitech.net>
**
** Started on  Sun Dec 20 23:09:04 2015 yoram soussan
** Last update Mon Dec 21 23:11:37 2015 yoram soussan
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/bsq.h"

int	valide_biggest_square(t_pt2 **matr, t_pt2 *coin, int *offset2)
{
  int	valide;
  int	val1;
  int	val2;

  valide = 1;
  val1 = matr[coin->x + coin->val][coin->y + coin->val].x;
  val2 = matr[coin->x + coin->val][coin->y + coin->val].y;
  if (val1 <= coin->val || val2 <= coin->val)
    {
      if (val2 <= coin->val)
	*offset2 = coin->val + 1;
      valide = 0;
    }
  return (valide);
}

int	search_biggest_square(t_pt2 **matr, t_pt2 *coin, t_pt2 *dim, int *ofset)
{
  int   i;

  if ((coin->x + coin->val >= dim->x) || (coin->y + coin->val >= dim->y) ||
      (matr[coin->x][coin->y].val == 0))
    return (coin->val);
  if (valide_biggest_square(matr, coin, ofset) == 1)
    {
      coin->val ++;
      i = search_biggest_square(matr, coin, dim, ofset);
      i++;
    }
  else
    return (coin->val);
  return (coin->val);
}

t_pt2   *search_square(t_pt2 **matr, t_pt2 *coin, t_pt2 *dim)
{
  int   taille;
  int	os2;
  int   taille2;
  int   go_on;
  t_pt2 *coin2;

  coin2 = NULL;
  if ((coin2 = malloc(sizeof(*coin2))) == NULL)
    return (NULL);
  taille = 0;
  go_on = 0;
  while (go_on == 0)
    {
      os2 = 0;
      taille2 = search_biggest_square(matr, coin, dim, &os2);
      if (taille2 > taille)
	{
	  taille = taille2;
	  coin2 = save(coin, coin2);
	}
      go_on = offset_coin(coin, (os2 == 0 ? 1 : os2), dim, taille2);
    }
  coin = save(coin2, coin);
  free(coin2);
  return (coin);
}

int	analyse_map(char **map, int index, int count)
{
  int	i;
  t_pt2	**matr;
  t_pt2	*coin;
  t_pt2	*dim;

  matr = NULL;
  if ((matr = malloc(index * sizeof(*matr))) == NULL)
    return (my_malloc_error());
  i = -1;
  while (++i < index)
    if ((matr[i] = malloc(count * sizeof(**matr))) == NULL)
      return (my_malloc_error());
  dim = NULL;
  if ((dim = alloc_coin(dim, index, count, 0)) == NULL)
    return (my_malloc_error());
  if (remplir_mat(map, matr, dim) == 1)
    return (-1);
  coin = NULL;
  if ((coin = alloc_coin(coin, 0, 0, 0)) == NULL)
    return (my_malloc_error());
  coin = search_square(matr, coin, dim);
  print_my_map(map, coin, dim);
  free(coin);
  return (0);
}
