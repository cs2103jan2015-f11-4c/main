#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <iostream>

class parser
{
public:
	parser(void);
	~parser(void);

	std::string readCommand(std::string);
};

#endif
