/*
** my_put_nbr.c for my_put_nbr.c in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Thu Jan 15 14:45:10 2015 michael besnainou
** Last update Thu Jan 15 14:47:26 2015 michael besnainou
*/

#include "../../include/my.h"

int	my_put_nbr(int nb)
{
  if (nb > 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (0);
}
