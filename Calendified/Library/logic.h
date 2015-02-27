#pragma once
#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include "parser.h"

class logic
{
private:
	std::string _command;
	std::string _title;
	std::string _time;
	std::string _date;
	std::string _location;
	std::string _description;

public:

	logic(std::string command, std::string title, std::string time,
				std::string date, std::string location, std::string description);

	void setCommand(std::string command);
	void setTitle(std::string title);
	void setTime(std::string time);
	void setDate(std::string date);
	void setLocation(std::string location);
	void setDescription(std::string description);

	std::string getCommand();
	std::string getTitle();
	std::string getTime();
	std::string getDate();
	std::string getLocation();
	std::string getDescription();

	logic(void);
	~logic(void);


};

#endif