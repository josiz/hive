/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaiedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:04:03 by jzaiedma          #+#    #+#             */
/*   Updated: 2019/10/17 11:51:52 by jzaiedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

int		ft_strcmp(char *s1, char *s2)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (s1[a] == '\0' || s2[a] == '\0')
		return (s1[a] - s2[a]);
	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}

void	ft_print_words(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	*temp;

	i = 2;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], argv[i - 1]) < 0)
		{
			temp = argv[i];
			argv[i] = argv[i - 1];
			argv[i - 1] = temp;
			i = 2;
			continue ;
		}
		i++;
	}
	ft_print_words(argv);
}
