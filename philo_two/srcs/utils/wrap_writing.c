/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:28:30 by hmin              #+#    #+#             */
/*   Updated: 2021/02/23 09:17:50 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	sem_wrap_writing(t_philo *phi, char *str, int n, void f_write())
{
	sem_wait(phi->info->write);
	f_write(phi, str, n);
	sem_post(phi->info->write);
}
