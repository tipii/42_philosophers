/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:52:17 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 11:07:40 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			basic_args_check(int argc, char **argv)
{
	int		i;

	i = 1;
	if (!(argc == 5 || argc == 6))
	{
		ft_putstr_fd("Invalid number of args\n", 1);
		return (0);
	}
	while (argv[i])
	{
		if (!(ft_atoi(argv[i]) > 0))
		{
			ft_putstr_fd("An arg is not valid\n", 1);
			return (0);
		}
		i++;
	}
	if (ft_atoi(argv[1]) < 2)
	{
		ft_putstr_fd("Not enough philosophers\n", 1);
		return (0);
	}
	return (1);
}

void		fill_with_args(t_args *args, int argc, char **argv)
{
	args->nbr_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->nbr_philo_must_eat = ft_atoi(argv[5]);
	else
		args->nbr_philo_must_eat = -1;
}
