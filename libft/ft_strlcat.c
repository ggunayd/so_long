/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:43 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/12/01 12:48:55 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Source ile dest'i birlestirip uzunlugunu dondurur.
 * 
 * @param dst Destination
 * @param src Source
 * @param dstsize Dst'nin uzunlugunu gondermemiz lazim.
 * @return size_t 
 */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	c;
	unsigned int	d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;
	while (src[d] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}
/*
int	main()
{
	char	dst[] = "1234";
	char	src[] = "gul";

	printf("dst uzunlugu: %zu\n", ft_strlen(dst));
	printf("src uzunlugu: %zu\n", ft_strlen(src));
	printf("birlestirilmis uzunluk: %zu\n", ft_strlcat(dst, src, ft_strlen(dst)));
}
*/