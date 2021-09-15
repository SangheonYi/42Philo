/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:44:53 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:24:33 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	dead_status(t_philo *phi)
{
	phi->info->dead_phi = phi->name;
	sem_wait(phi->info->write);
	print_dead(phi, DEAD, 8);
	sem_post(phi->info->end);
}
