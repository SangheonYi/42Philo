/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:46:11 by hmin              #+#    #+#             */
/*   Updated: 2021/02/25 13:45:01 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	print_dead(t_philo *phi, char *str, int n)
{
	ft_putnbr_light(cur_time() - phi->t_start);
	write(1, " ", 1);
	ft_putnbr_light(phi->name);
	write(1, " ", 1);
	write(1, str, n);
}
