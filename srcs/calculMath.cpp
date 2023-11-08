/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculMath.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:54:34 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/08 18:17:00 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poly.hpp"
#include <iostream>
#include <deque>

double	ft_sqrt(double A)
{
	double epsilon = 1.0e-6;
	
	if ( A < epsilon ) return 0.0;

	double x = 1.0, xold = 2.0;
	xold = A;
	while (  xold - x  > epsilon )
	{
		xold = (xold + x) / 2;
		x = (  A / xold );
	}
	return x;
}

void	calculMath(std::deque<std::string> deq)
{
	double a = atof((char *)(*(deq.begin())).c_str());
	double b = atof((char *)(*(deq.begin() + 1)).c_str());
	double c = atof((char *)(*(deq.begin() + 2)).c_str());

	if (a == 0)
	{
		double x1;
		if (b == 0)
			x1 = c;
		else
			x1 =  -c / b;
		std::cout << "The solution is:\nx = " << x1 << "\n";
		return ;

	}

	double delta = (b * b) - 4 * a * c;
	if (BONUS == 1)
	{
		double bb = b * b;
		double ac = 4 * a * c;
		std::cout << "Calcul delta with\n=> b² - 4ac\n=> " << b << "² - 4 * " << a << " * " << c << "\n=> " << bb << " - " << ac << "\n=> " << delta << "\n";
	}


	if (delta > 0)
	{
		double x1 = (-b - ft_sqrt(delta)) / (2 * a);
		double x2 = (-b + ft_sqrt(delta)) / (2 * a);
		std::cout << "Discriminant is strictly positive, the two solutions are:\nx1 = " << x1 << " and " << "x2 = " << x2 << "\n";
		return ;
	}
	else if (delta == 0)
	{
		double x1 = (-b / (2 * a));
		std::cout << "Discriminant is equl to 0, the solution is:\nx1 = " << x1 << "\n";
		return ;
	}
	std::cout << "Delta is strictly negative, there is no solution !\n";
}
