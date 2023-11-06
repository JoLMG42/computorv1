#include <iostream>
#include <vector>
#include "Poly.hpp"
#include <stdlib.h>


std::vector<std::string> ft_splitVector(std::string str, std::string deli)
{
	std::vector<std::string> res;

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
		if (std::isdigit(c) == 0)
			return false;
	}
	return true;
}

int	checkFormat(char *str, Poly *poly)
{
	std::vector<std::string>	factors;
	std::vector<char>		sign;
	std::vector<int>		powers;
	poly->setExpr(str);
	std::vector<std::string> vec = ft_splitVector(str, " ");
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (((*it).find("*") <= (*it).length() || (*it)[0] == '*') && (*it).length() != 1)
			return (0);
		else if (((*it).find("*") <= (*it).length() || (*it)[0] == '*') && (*it).length() == 1)
		{
			std::vector<std::string>::iterator tmp(it);
			tmp--;
			if (!isNumber(*tmp))
				return (0);
			factors.push_back(*tmp);
			tmp = it;
			tmp++;  
			if ((*tmp)[0] != 'X' || (*tmp)[1] != '^')
				return (0);
			else if ((*tmp)[0] == 'X' && (*tmp)[1] == '^')
			{
				std::string pow = (*tmp).substr(2, (*tmp).length());
				if (!isNumber(pow) || pow.length() < 1)
					return (0);
				else
					powers.push_back(atoi(pow.c_str()));
			}
			factors.push_back(*tmp);
			tmp++;
			if (tmp != vec.end() && (*tmp).length() > 0 && ((*tmp)[0] == '+' || (*tmp)[0] == '-' ))
				sign.push_back((*(tmp))[0]);
			//std::cout << "ici = " << (*tmp) << "\n";
		}
	}
	poly->setFactors(factors);
	poly->setSign(sign);
	poly->setPowers(powers);
	std::vector<std::string> recupFactor = poly->getFactors();
	for (std::vector<std::string>::iterator it = recupFactor.begin(); it != recupFactor.end();++ it)
		std::cout << "factors = " << *it << "\n";
	std::vector<char> recupSign = poly->getSign();
	for (std::vector<char>::iterator it = recupSign.begin(); it != recupSign.end();++ it)
		std::cout << "sign = " << *it << "\n";
	std::vector<int> recupPowers = poly->getPowers();
	for (std::vector<int>::iterator it = recupPowers.begin(); it != recupPowers.end();++ it)
		std::cout << "powers = " << *it << "\n";
	std::cout << poly->getExpr();
	return (1);

}

std::vector<std::string> splitStart(std::string str, std::string delim)
{
	size_t start = 0;
	size_t pos_delim = str.find(delim);
	std::vector<std::string> ret;
	while (pos_delim != str.npos)
	{
		ret.push_back(str.substr(start, pos_delim - start));
		start = pos_delim + delim.length();
		pos_delim = str.find(delim, start);
	}
	ret.push_back(str.substr(start, str.length() - start));
	return (ret);
}

void    reducedForm(Poly *polyLeft, Poly *polyRight);

int	main(int ac, char **av)
{
	Poly polyLeft;
	Poly polyRight;
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}
	std::vector<std::string> recupPoly = splitStart(av[1], "=");
	std::cout << "POlY left = " << *(recupPoly.begin()) << "\n";
	if (!checkFormat((char *)(recupPoly.begin())->c_str(), &polyLeft))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	std::vector<std::string>::iterator itEnd = recupPoly.end();
	itEnd--;
	std::cout << "\nPOlY RIGHT = " << (*itEnd) << "\n";
	if (!checkFormat((char *)((*itEnd).c_str()), &polyRight))
	{
		std::cout << "Wrong format\n";
		return (0);
	}
	reducedForm(&polyLeft, &polyRight);
}
