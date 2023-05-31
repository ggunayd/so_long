/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:12:14 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/10/25 12:47:50 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief s2de arattığı karakterleri s1de bulduğu andan itibaren yazdırır.
 * 
 * @param 
 * @param 
 * @param 
 * @return void*
 */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t	n)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (!s2_len)
		return ((char *)s1);
	if (n != 0)
	{
		while (s1[i] && i <= n - s2_len)
		{
			j = 0;
			while (s2[j] && s2[j] == s1[i + j])
				j++;
			if (j == s2_len)
				return ((char *)&s1[i]);
			i++;
		}
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
    char *a;
    char *b;
    
    a = "gulbahar";
    b = "ba";
    printf("ft_:%s", ft_strnstr(a, b, 5));
}
*/