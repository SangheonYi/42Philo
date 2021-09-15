/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_drop_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:29:51 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:40:40 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	take_forks(t_philo *phi)
{
	sem_wait(phi->info->take);
	sem_wait(phi->info->forks);
	sem_wrap_writing(phi, TAKE_F, 17, print_log);
	sem_wait(phi->info->forks);
	sem_wrap_writing(phi, TAKE_F, 17, print_log);
	sem_post(phi->info->take);
}

void	drop_forks(t_philo *phi)
{
	sem_post(phi->info->forks);
	sem_post(phi->info->forks);
}
