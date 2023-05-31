/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:19:42 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/12/01 13:21:57 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	if (s != NULL)
	{
		while (index < ft_strlen(s))
		{
			f(index, &s[index]);
			index++;
		}
	}
}
/*
// void fsdf(unsigned int i, char *c)
// {
//     *c -= 32;
// }
// int main()
// {
    
//     char str[] = "MUKEMMELfatih";
//     ft_striteri(str, fsdf);
//     puts(str);
// }
*/