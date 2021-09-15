/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:19:25 by hmin              #+#    #+#             */
/*   Updated: 2021/02/26 13:00:20 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	pre_init(t_philo **phi, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->rules[SUM_PH])
	{
		(*phi)[i].info = info;
		(*phi)[i].name = i + 1;
		(*phi)[i].t_start = 0;
		(*phi)[i].curent_time = 0;
		(*phi)[i].last_eat = 0;
		(*phi)[i].last_eat = 0;
		(*phi)[i].must_eat = (*phi)[i].info->rules[T_MST_E];
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_philo			*philo;
	t_info			info;
	int				status;
	pid_t			*processes;

	if (argc < 5 || argc > 6)
		return (ERR_WRONG_ARGC);
	status = philo_pars(argv, &info);
	if (!status)
		if (!(philo = malloc(
				(info.rules[SUM_PH]) * sizeof(t_philo))))
			status = ERR_MALLOC_PHILO;
	if (!status)
		pre_init(&philo, &info);
	if (!status && !(processes =
			malloc(sizeof(pid_t) * info.rules[SUM_PH])))
		status = ERR_MALLOC_PROCESS;
	if (!status)
		status = philo_start(philo, &info, &processes);
	clear_space(status, &philo, &processes);
	exit(status);
}
