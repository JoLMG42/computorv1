/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:32:35 by jtaravel          #+#    #+#             */
/*   Updated: 2023/11/08 15:33:06 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poly.hpp"

std::deque<std::string> splitStart(std::string str, std::string delim)
{
	size_t start = 0;
	size_t pos_delim = str.find(delim);
	std::deque<std::string> ret;
	while (pos_delim != str.npos)
	{
		ret.push_back(str.substr(start, pos_delim - start));
		start = pos_delim + delim.length();
		pos_delim = str.find(delim, start);
	}
	ret.push_back(str.substr(start, str.length() - start));
	return (ret);
}

std::string	addSpace(std::string cpy)
{
	int i = 0;
	while (cpy[i])
	{
		if (cpy[i] == '*')
		{
			if (cpy[i - 1] != ' ')
			{
				cpy.insert(i - 1, " ");
				i++;
			}
			if (cpy[i + 1] != ' ')
				cpy.insert(i + 1, " ");
		}
		i++;
	}
	return cpy;
}

std::deque<std::string> ft_splitdeque(std::string str, std::string deli)
{
	std::deque<std::string> res;

		int start = 0;
		int end = str.find(deli);
		int     i = 0;
		while (end != -1)
		{
				res.push_back(str.substr(start, end - start));
				start = end + deli.size();
				end = str.find(deli, start);
				i++;
		}
		res.push_back(str.substr(start, end - start));
		return (res);
}

bool isNumber(const std::string& str)
{
	for (char const& c : str)
	{
		if (std::isdigit(c) == 0 && c != '.')
			return false;
	}
	return true;
}

