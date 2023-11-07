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

	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";

	if (a == 0)
	{
		double x1 =  -c / b;
		std::cout << x1 << "\n";
		return ;

	}

	double delta = (b * b) - 4 * a * c;
	std::cout << delta << "\n";

	if (delta > 0)
	{
		double x1 = (-b - ft_sqrt(delta)) / (2 * a);
		double x2 = (-b + ft_sqrt(delta)) / (2 * a);

		std::cout << x1 << "\n";
		std::cout << x2 << "\n";
	}
	else if (delta == 0)
	{
		double x1 = (-b / (2 * a));
		std::cout << x1 << "\n";
	}
}
