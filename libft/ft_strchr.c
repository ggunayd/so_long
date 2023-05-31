/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:19:36 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/12/01 13:04:59 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief String'in icinde char ariyor, buldugunda bulunan
 *  karakterden itibaren geri kalanini donduruyor.
 * 
 * @param str String
 * @param c Char
 * @return char* 
 */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
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
	printf("Bulunduktan sonraki hali: %s\n", ft_strchr(string, c));
}
*/