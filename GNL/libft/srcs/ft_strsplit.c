/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:24:26 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/29 16:47:29 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	string_counter(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		sp;
	char	**tab;
	int		i;
	int		j;
	int		start;

	if ((s == 0) || (c == 0))
		return (NULL);
	sp = string_counter(s, c);
	if (!(tab = malloc((sizeof(char*) * (sp + 1)))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < sp)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
