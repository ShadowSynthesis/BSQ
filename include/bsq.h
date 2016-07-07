/*
** bsq.h for  in /home/soussa_y/rendu/CPE_2015_BSQ
**
** Made by yoram soussan
** Login   <soussa_y@epitech.net>
**
** Started on  Sun Dec 20 23:08:30 2015 yoram soussan
** Last update Mon Dec 21 15:41:21 2015 yoram soussan
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define BUFFSIZE 8000

typedef struct	s_pt2
{
  int	val;
  int	x;
  int	y;
}		t_pt2;

int	my_error(int argc);
int	my_malloc_error();
int	my_map_error();
int	my_error2(char *str);
void	my_puterror(char *str, int size);
char	*recup_ligne(const int fd);
t_pt2	*alloc_coin(t_pt2 *coin, int index, int count, int val);
int	remplir_mat(char **map, t_pt2 **matr, t_pt2 *dim);
void	print_my_map(char **map, t_pt2 *coin, t_pt2 *dim);
int	offset_coin(t_pt2 *coin, int j, t_pt2 *dim, int taille);
int	valide_biggest_square(t_pt2 **matr, t_pt2 *coin, int *offset2);
int	search_biggest_square(t_pt2 **matr, t_pt2 *coin, t_pt2 *dim, int *offset);
t_pt2   *save(t_pt2 *coin, t_pt2 *coin2);
t_pt2   *search_square(t_pt2 **matr, t_pt2 *coin, t_pt2 *dim);
int	analyse_map(char **map, int index, int count);

#endif /* !GET_NEXT_LINE_H_ */
