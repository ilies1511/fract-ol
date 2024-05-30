/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:13:28 by iziane            #+#    #+#             */
/*   Updated: 2024/05/23 04:56:19 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (s && s[i])
	{
		k = 0;
		while (s[i] != reject[k] && reject[k])
			k++;
		if (s[i] == reject[k])
			break ;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	char	*s;
// 	char	*num;
// 	size_t	res;
// 	size_t	res2;

// 	s = "hallo123456789";
// 	num = "";
// 	res2 = strcspn(s, num);
// 	res = ft_strcspn(s, num);
// 	printf("Meine: %zu\n", res);
// 	printf("Seine: %zu\n", res2);
// 	return (0);
// }
