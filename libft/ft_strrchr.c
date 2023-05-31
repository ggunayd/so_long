/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:05:22 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/10/24 17:18:55 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief String'in icinde char ariyor, buldugunda bulunan
 *  karakterin "adresini" donduruyor.
 * 
 * @param str String
 * @param c Char
 * @return char* 
 */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*s)
		s++;
	while (s >= start)
	{
		if (*((char *)s) == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
/*
int	main()
{
	char	string[] = "gulbahar";
	char	c = 'b';

	printf("Aranan: %s\n", string);
	printf("Arayici: %c\n", c);
	printf("Bulunduktan sonraki hali: %s\n", ft_strrchr(string, c));
}
*/