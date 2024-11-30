/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-medi <lde-medi@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:17:14 by lde-medi          #+#    #+#             */
/*   Updated: 2024/11/20 18:38:17 by lde-medi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putstr(char    *str);
int ft_strcmp(char    *s1, char    *s2);
void    swap_pos(char    **s1, char    **s2);

int main(int argc, char    *argv[])
    {
          int    is_sort;
          int    i;

          is_sort = 0;
          while (!is_sort)
         {
              is_sort = 1;
              i = 1;
              while (i < argc - 1)
              {
                  if (ft_strcmp(argv[i], argv[i + 1]) > 0)
                  {
                        swap_pos(&argv[i], &argv[i + 1]);
                        is_sort--;
                  }
                   i++;
              }
         }
         i = 1;
         while (i < argc - 1)
         {
               ft_putstr(argv[i]);
               i++;
          }
          return (0);
        }



int	ft_strcmp(char	*s1, char	*s2)
{
    int	i;

    i = 0;
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void    ft_putstr(char    *str)
{
    while(*str)
    {
      write(1, str, 1);
      str++;
      }
	write(1, "\n", 1);
}

void    swap_pos(char    **s1, char    **s2)
{
      char    *temp;

      temp = *s1;
      *s1 = *s2;
      *s2 = temp;
}
