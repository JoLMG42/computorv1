/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculMath.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:54:34 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/09 19:22:09 by jtaravel         ###   ########.fr       */
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
		{
			x1 = c;
			if (x1 != 0)
			{
				std::cout << "There is no solution !\n";
				return ;
			}

		}
		else if (c == 0)
		{
			std::cout << "The solution is:\nx = 0" << "\n";
			return ;
		}
		else
			x1 =  -c / b;
		if (x1 == 0)
			std::cout << "The solution is true for any value of x !\n";
		else
			std::cout << "The solution is:\nx = " << x1 << "\n";
		return ;

	}

	double delta = (b * b) - 4 * a * c;
	if (BONUS == 1)
	{
		double bb = b * b;
		double ac = 4 * a * c;
		std::cout << "Calculate delta with\n=> b² - 4ac\n=> " << b << "² - 4 * " << a << " * " << c << "\n=> " << bb << " - " << ac << "\n=> " << delta << "\n";
	}


	if (delta > 0)
	{
		double x1 = (-b - ft_sqrt(delta)) / (2 * a);
		double x2 = (-b + ft_sqrt(delta)) / (2 * a);
		if (BONUS == 1)
		{
			std::cout << "\nCalculate x1 with\n=> (-b - √delta) / (2 * a)\n=> (" << -b << " - √" << delta << " / " << "2 * " << a << ")\n";
			std::cout << "=> " << (-b - ft_sqrt(delta)) << " / " << (2 * a) << "\n=> " << x1 << "\n\n";
			std::cout << "\nCalculate x2 with\n=> (-b + √delta) / (2 * a)\n=> (" << -b << " + √" << delta << " / " << "2 * " << a << ")\n";
			std::cout << "=> " << (-b + ft_sqrt(delta)) << " / " << (2 * a) << "\n=> " << x2 << "\n\n";
		}
		std::cout << "Discriminant is strictly positive: " << delta << " the two solutions are:\nx1 = " << x1 << " and " << "x2 = " << x2 << "\n";
		return ;
	}
	else if (delta == 0)
	{
		double x1 = (-b / (2 * a));
		if (BONUS == 1)
		{
			std::cout << "\nCalculate x with\n=> (-b - √delta) / (2 * a)\n=> (" << -b << " - √" << delta << " / " << "2 * " << a << ")\n";
			std::cout << "=> " << (-b - ft_sqrt(delta)) << " / " << (2 * a) << "\n=> " << x1 << "\n\n";
		}
		std::cout << "Discriminant is equl to 0, the solution is:\nx = " << x1 << "\n";
		return ;
	}
	if (delta < 0)
	{
		double x1 = (-b) / (2 * a);
		double y1 = (ft_sqrt(-delta) / (2 * a));
		double x2 = (-b) / (2 * a);
		double y2 = ft_sqrt(-delta) / (2 * a);

		if (BONUS == 1)
		{
			std::cout << "\nCalculate x1 with\n=> (-b - i√delta) / (2 * a)\n=> (" << -b << " - i√" << delta << " / " << "2 * " << a << ")\n";
			std::cout << "=> " << (-b - ft_sqrt(delta)) << " * i / " << (2 * a) << "\n=> " << x1 << " - i" << y1 << "\n\n";
			std::cout << "\nCalculate x2 with\n=> (-b + i√delta) / (2 * a)\n=> (" << -b << " + i√" << delta << " / " << "2 * " << a << ")\n";
			std::cout << "=> " << (-b + ft_sqrt(delta)) << " * / " << (2 * a) << "\n=> " << x2 << " + i" << y2 << "\n\n";
		}

		std::cout << "Discriminant is strictly negativ: " << delta << " the two solutions are:\n";
		std::cout << "x1 = " << x1 << " - " << y1 << " * i" << "\n";
		std::cout << "x2 = " << x2 << " + " << y2 << " * i" << "\n";
		return ;
	}
}
