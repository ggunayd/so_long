/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggunaydi <ggunaydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:20:30 by ggunaydi          #+#    #+#             */
/*   Updated: 2022/12/01 13:14:22 by ggunaydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (NULL);
		*ret = '\0';
	}
	else
	{
		if ((n - start) < len)
		len = n - start;
		ret = malloc(sizeof(char) * len + 1);
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, (char *)(s + start), len + 1);
	}
	return (ret);
}

/*
int main()
{
    char a[] = "gorkem";
	int		i;

	i = 3;
	// printf("ft_:%s\n", ft_substr(a, 546, 3));
	printf("sizeof'un icindeki deger: %lu\n", sizeof(unsigned char));
}
*/
