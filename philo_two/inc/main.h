/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 09:22:40 by tpalhol           #+#    #+#             */
/*   Updated: 2020/11/30 13:30:41 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "struct_philosopher.h"
# include "struct_all.h"
# include "struct_args.h"

/*
** MAIN
*/
void	start_threads(t_all *all);
void	*philo_life(void *p);
void	philo_eating(t_philosopher *philo);

/*
** PARSE
*/
int		basic_args_check(int argc, char **argv);
void	fill_with_args(t_args *args, int argc, char **argv);

/*
** INIT
*/
int		init_table(t_all *all);
int		init_semaphores(t_all *all);

/*
** CONTROLLER
*/
void	*controller(void *a);
int		check_death_condition(t_philosopher *philo);

/*
** TIME
*/
time_t	get_time_since_start(t_timeval start);
int		diff_ms(t_timeval t1, t_timeval t2);
void	msleep(int u_seconds);

/*
** UTILS
*/
int		ft_atoi(const char *str);
void	print_state(t_philosopher *philo, char *str);
int		error_malloc(void);
int		error_semaphore(void);
t_all	*init_all(t_all *all);

/*
** CLEAN
*/
void	join_threads(t_all *all);
void	free_all(t_all *all);

/*
** DEBUG
*/
void	print_table(t_all *all);
void	print_args(t_args *args);

/*
** WRITE
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long nbr, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

/*
** SEMAPHORE
*/
char	*generate_sem_name(t_philosopher *philo);
sem_t	*create_semaphore(char *name, int i);

#endif
