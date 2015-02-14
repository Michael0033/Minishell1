/*
** my_str_to_wordtab.c for sl in /home/besnai_m/rendu/C-Prog ELEM
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Fri Jan 23 15:07:12 2015 michael besnainou
** Last update Sun Feb  1 23:41:04 2015 michael besnainou
*/

#include <stdlib.h>
#include "../../include/my.h"

void		wordtab_check(char *tab, int big, char *str, int small)
{
  int		size;

  size = big - small;
  tab[size] = '\0';
  while (size >= 0)
    {
      size = size - 1;
      big = big - 1;
      tab[size] = str[big];
    }
}

char		**my_str_to_wordtab(char *str)
{
  int		k;
  int		i;
  int		j;
  int		size;
  char		**tab;

  size = my_strlen(str);
  k = 0;
  j = 0;
  i = 0;
  if ((tab = malloc(sizeof(*tab) * 1000)) == NULL)
    exit(1);
  while (k < size)
    {
      if ((tab[i] = malloc(sizeof(char) * 1000)) == NULL)
	exit(1);
      while ((str[k] >= '!' && str[k] <= '9') ||
	     (str[k] >= '>' && str[k] <= '~'))
        k = k + 1;
      if (k != j)
	wordtab_check(tab[i++], k, str, j);
      j = ++k;
    }
  return (tab);
}
