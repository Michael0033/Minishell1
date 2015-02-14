/*
** my_putstr_error.c for putstr_error in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Sun Feb  1 23:33:06 2015 michael besnainou
** Last update Sun Feb  1 23:33:51 2015 michael besnainou
*/

#include <unistd.h>

void	my_putstr_error(char *str)
{
  while (*str)
    write(2, str++, 1);
}
