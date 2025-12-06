/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewaltz <ewaltz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:15:18 by ewaltz            #+#    #+#             */
/*   Updated: 2025/12/06 16:20:15 by ewaltz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_index(char *str)
{
  int	i;

  i = 0;
  if (!str)
	return (-1);
  while (str[i])
  {
	if (str [i] == '\n')
	  return (i);
	i++;
  }
  return (-1);
}

char	*ft_strdup(char *str, int len)
{
  int	i;
  char	*new_str;

  i = 0;
  if (!str)
	return (NULL);
  new_str = malloc(sizeof(char) * (len + 1));
  if (!new_str)
	return (NULL);
  while (i < len)
  {
	new_str[i] = str[i];
	i++;
  }
  new_str[i] = '\0';
  return (new_str);
}


char	*get_rest(char *str, int start)
{
  int	i;
  char	*new_str;

  i = 0;
  if (!str)
	return (NULL);
  new_str = malloc(sizeof((char) * len) + 1);
  if (!new_str)
	return (NULL);
  while (str[start])
  {
	new_str[i] = str[start];
	start++;
	i++;
  }
  new_str[i] = '\0';
  return (new_str);
}



char	*get_next_line(int fd)
{
  static char* rest;
  int i;

  i = get_index(rest);
  rest = NULL;
  if (i != -1)
  {
	rest = get_rest(rest, i);
	return (ft_strdup(rest, i))
  }
}
