/*
** get_next_line.c for get_next_line in /home/besnai_m/rendu/CPE_2014_get_next_line
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Nov 17 17:12:45 2014 michael besnainou
** Last update Sun Feb  1 20:44:27 2015 michael besnainou
*/

#include "../../include/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int		finish(char *tab, char *line, int *n, int *k)
{
  int		z;

  z = 0;
  while (tab[*k] != '\0')
    {
      if (tab[*k] == '\n')
	{
	  line[z] = 0;
	  *k = *k + 1;
	  return (1);
	}
      line[z] = tab[*k];
      *k = *k + 1;
      z = z + 1;
    }
  line[z] = 0;
  *n = z;
  return (0);
}

char		*my_strcpy(char *dest, char *src, int n, int end)
{
  int		i;

  i = 0;
  if (end != 9876543)
    {
      while (i != end)
        {
          dest[n] = src[i];
          src[i] = 0;
          i = i + 1;
          n = n + 1;
        }
      dest[n] = 0;
    }
  else
    {
      while (src[i] != '\0')
        {
          dest[n] = src[i];
          src[i] = 0;
          n = n + 1;
          i = i + 1;
        }
    }
  return (dest);
}

char		*realloc_that(char *str)
{
  char		*tmp;
  int		y;
  int		z;

  z = 0;
  while (str[z] != '\0')
    z = z + 1;
  y = 0;
  tmp = malloc(z + BUFFER_SIZE + 3);
  if (tmp == NULL)
    return (NULL);
  while (str[y] != '\0')
    {
      tmp[y] = str[y];
      y = y + 1;
    }
  tmp[y] = '\0';
  return (tmp);
}

int		entire(int fd, char *tab, int *k, t_struct *stru)
{
  int		error;

  error = 1;
  while (error > 0)
    {
      error = read(fd, tab,  BUFFER_SIZE);
      tab[BUFFER_SIZE] = 0;
      while (tab[*k] != '\0')
	{
          if (tab[*k] == '\n')
            {
              stru->line = my_strcpy(stru->line, tab, stru->n, *k);
              *k = *k + 1;
              return (1);
            }
          *k = *k + 1;
	}
      stru->line = realloc_that(stru->line);
      stru->line = my_strcpy(stru->line, tab, stru->n, 9876543);
      stru->n = stru->n + *k;
      *k = 0;
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char  	tab[BUFFER_SIZE];
  static int	k;
  static int	end;
  t_struct	stru;

  stru.m = 0;
  stru.n = 0;
  if (end == 1)
    return (0);
  if ((stru.line = malloc(BUFFER_SIZE + 1)) == NULL)
    return (0);
  if (finish(tab, stru.line, &stru.n, &k) == 1)
    return (stru.line);
  while (stru.m != BUFFER_SIZE)
    {
      tab[stru.m] = 0;
      stru.m = stru.m + 1;
    }
  if (entire(fd, tab, &k, &stru) == 1)
    return (stru.line);
  end = 1;
  stru.line[stru.n] = 0;
  return (stru.line);
}
