/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:05:37 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/27 15:37:10 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			ft_atoi(const char *str)
{
	long	atoi;
	int		i;

	i = 0;
	atoi = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			atoi = (atoi * 10) + str[i] - 48;
			i++;
		}
		else
			return (-1);
	}
	return (atoi);
}

void		print_state(t_philosopher *philo, char *str)
{
	sem_wait(philo->all->mic);
	ft_putnbr_fd(get_time_since_start(philo->all->start), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->pos + 1, 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	sem_post(philo->all->mic);
}

int			error_malloc(void)
{
	ft_putstr_fd("Error malloc\n", 2);
	return (1);
}

int			error_semaphore(void)
{
	ft_putstr_fd("Error semaphore\n", 2);
	return (1);
}

t_all		*init_all(t_all *all)
{
	if (!(all = malloc(sizeof(t_all))))
		return (NULL);
	if (!(all->args = malloc(sizeof(t_args))))
		return (NULL);
	return (all);
}
