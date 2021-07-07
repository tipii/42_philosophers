/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_philosopher.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:02:58 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 11:18:57 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PHILOSOPHER_H
# define STRUCT_PHILOSOPHER_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_all	t_all;
typedef struct timeval	t_timeval;
typedef struct s_args	t_args;

typedef struct			s_philosopher
{
	pid_t				pid;
	pthread_t			controller;
	char				*name;
	t_all				*all;
	int					pos;
	int					count_eat;
	int					quit;
	t_timeval			last_meal;
	sem_t				*eating_state;
	t_args				*args;
}						t_philosopher;

#endif
