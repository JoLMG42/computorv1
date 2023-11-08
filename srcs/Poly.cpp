/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poly.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:29:03 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/06 17:10:42 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poly.hpp"

Poly::Poly(void)
{
	expr = "";
}

Poly::~Poly(void)
{
}

void	Poly::setExpr(char *str)
{
	this->expr = str;
}

std::string Poly::getExpr(void)
{
	return this->expr;
}

void	Poly::setFactors(std::deque<std::string> vec)
{
	this->factors = vec;
}

std::deque<std::string>	Poly::getFactors(void)
{
	return this->factors;
}

void	Poly::setSign(std::deque<char> vec)
{
	this->sign = vec;
}

std::deque<char>	Poly::getSign(void)
{
	return this->sign;
}

void	Poly::setPowers(std::deque<int> vec)
{
	this->powers = vec;
}

std::deque<int>	Poly::getPowers(void)
{
	return this->powers;
}
