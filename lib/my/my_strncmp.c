/*
** my_strncmp.c for my_strncmp in
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Tue Oct  7 09:45:30 2014 michael besnainou
** Last update Sun Feb  1 20:45:34 2015 michael besnainou
*/

#include <stdlib.h>

int	my_strncmp(char *s1, char *s2, int n)
{
  int	j;

  j = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (j < n)
    {
      if (s1[j] != s2[j])
	return (s1[j] - s2[j]);
      j = j + 1;
    }
  return (0);
}
