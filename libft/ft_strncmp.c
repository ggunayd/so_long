/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:06:42 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/10/25 13:54:32 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Stringin icindeki ayni karakterleri atliyor, farkli bir karakter
 *  buldugunda bu s1'in karakterini s2'nin karakterini cikariyor ve
 *  desimal degerini donduruyor.
 * 
 * @param s1 
 * @param s2 
 * @param size 
 * @return int Desimal degerini donduruyor.
 */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 1;
	if (!n)
		return (0);
	while (*str1 == *str2 && i++ < n && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
/*
int	main()
{
	char	s1[] = "123de";
	char	s2[] = "123f";

	printf("Karsilastirilanlar: s1[%s] & s2[%s]\n", s1, s2);
	printf("Karsilastirma sonrasi desimal degeri \
farki: %d\n", ft_strncmp(s1, s2, 4));
}
*/