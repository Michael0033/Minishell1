/*
** small_functions.c for small_functions in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Sun Feb  1 15:19:18 2015 michael besnainou
** Last update Sun Feb  1 23:35:23 2015 michael besnainou
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

void		gere_empty_env(char **env)
{
  char		*s;

  if (env[0] ==  NULL || env[1] == NULL)
    {
      my_putstr("$>");
      while ((s = get_next_line(0)))
	{
	  if (s != NULL)
	    {
	      my_putstr_error(s);
	      my_putstr_error(" : Command not found");
	    }
	  my_putchar('\n');
	  my_putstr("$>");
	}
    }
}

void		gere_ctrl_c()
{
  my_putchar('\n');
  my_putstr("$>");
}

void		gere_exit(t_con *con)
{
  con->string.str5 = "exit";
  if (my_strncmp(con->string.str5, con->stru.argv_tab[0], 4) == 0)
    exit(1);
}
