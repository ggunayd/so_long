/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:13 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/12/01 12:59:10 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 2 string arasinda n kadar sayar ayniysa 0 dondurur degilse byte'inin
 * farkini dondurur.
 * 
 * @param 
 * @param 
 * @param 
 * @return void*
 */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (s1 == s2 || n == 0)
		return (0);
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char s1[] = "gulb";
	char s2[] = "gul";
	printf("%d", ft_memcmp(s1,s2, 4));
}
*/
