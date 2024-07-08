#pragma once
#include <string>
#include <vector>
#include <sstream>



std::string trim(const std::string& string)
{
	std::string finalString(string);
	int position = finalString.find_first_not_of(" ");
	if (position != -1)
	{
		finalString.erase(0, position);
	}
	position = finalString.find_last_not_of(" ");
	if (position != std::string::npos)
	{
		finalString.erase(position + 1);
	}
	return finalString;
}


std::vector<std::string> tokens(const std::string& string, char delimiter)
{
	std::vector<std::string> tokens;

	std::stringstream s(string);
	std::string token;
	while (std::getline(s, token, delimiter))
		tokens.push_back(token);

	return tokens;
}