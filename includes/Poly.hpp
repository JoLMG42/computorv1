/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poly.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:26:50 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/08 15:37:33 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLY_HPP

#define POLY_HPP

#ifndef BONUS
#define BONUS 0
#endif


#include <iostream>
#include <string>
#include <deque>

class	Poly
{
	private:
		std::string			expr;
		std::deque<int>		powers;
		std::deque<char>		sign;
		std::deque<std::string>	factors;

	public:
		Poly(void);
		~Poly(void);

		void				setExpr(char *str);
		std::string	 		getExpr(void);
		void				setPowers(std::deque<int> vec);
		std::deque<int>		getPowers(void);
		void				setSign(std::deque<char> vec);
		std::deque<char> 		getSign(void);
		void				setFactors(std::deque<std::string> vec);
		std::deque<std::string>	getFactors(void);
};


std::deque<std::string> splitStart(std::string str, std::string delim);
std::string     addSpace(std::string cpy);
std::deque<std::string> ft_splitdeque(std::string str, std::string deli);
bool isNumber(const std::string& str);
std::string     refactoStr(std::string str, const char *ope, const char *toSplit);
int     checkFormat(char *str, Poly *poly);
void    reducedForm(Poly *polyLeft, Poly *polyRight);
void    calculMath(std::deque<std::string> deq);


#endif

