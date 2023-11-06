/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poly.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:26:50 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/06 16:46:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLY_HPP

#define POLY_HPP

#include <iostream>
#include <string>
#include <vector>

class	Poly
{
	private:
		std::string			expr;
		std::vector<int>		powers;
		std::vector<char>		sign;
		std::vector<std::string>	factors;

	public:
		Poly(void);
		~Poly(void);

		void				setExpr(char *str);
		std::string	 		getExpr(void);
		void				setPowers(std::vector<int> vec);
		std::vector<int>		getPowers(void);
		void				setSign(std::vector<char> vec);
		std::vector<char> 		getSign(void);
		void				setFactors(std::vector<std::string> vec);
		std::vector<std::string>	getFactors(void);
};

#endif

