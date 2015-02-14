/*
** biggest_functions.c for biggest_functions in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Sun Feb  1 15:23:32 2015 michael besnainou
** Last update Wed Feb 11 15:09:17 2015 michael besnainou
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

void		gere_cd(t_con *con)
{
  int		i;

  i = 0;
  con->string.str4 = "cd";
  if (my_strncmp(con->string.str4, con->stru.argv_tab[0], 2) == 0)
    {
      while (con->stru.argv_tab[i] != '\0')
        {
	  chdir(con->stru.argv_tab[i]);
          i = i + 1;
        }
      if (i == 1)
        chdir("/home/");
    }
}

void		gere_path_functions(char **env, t_con *con)
{
  int		i;
  pid_t		pid;
  int		status;

  i = 0;
  con->stru.path_tab = my_str_to_wordtab(con->stru.path);
  gere_exit(con);
  gere_cd(con);
  if ((pid = fork()) == -1)
    exit(1);
  if (pid == 0)
    {
      while (con->stru.path_tab[i] != NULL)
        {
          if (execve(my_strcatdup(con->stru.path_tab[i], con->stru.argv_tab[0]),
                     con->stru.argv_tab, env)  == -1)
            i = i + 1;
        }
      my_putstr_error(con->stru.argv_tab[0]);
      my_putstr_error(" : command not found\n");
    }
  else
    wait(&status);
}

void		get_path(char **env, t_con *con)
{
  int		i;
  int		a;
  char		*str;

  con->stru.z = 0;
  i = 0;
  a = 0;
  str = "PATH=";
  while (env[i] != NULL && a == 0)
    {
      if (my_strncmp(str, env[i], 5) == 0)
        a = a + 1;
      i = i + 1;
    }
  while (env[i - 1][con->stru.z] != '\0')
    {
      con->stru.path[con->stru.z] = env[i - 1][con->stru.z];
      con->stru.z = con->stru.z + 1;
    }
  gere_path_functions(env, con);
}
