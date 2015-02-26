#include "logic.h"
#include <iostream>

logic::logic(void)
{
}

logic::~logic(void)
{
}

logic::logic(std::string command, std::string title, std::string time, std::string date, 
	  std::string location, std::string description){
		  _command = command;
		  _title = title;
		  _time = time;
		  _date = date;
		  _location = location;
		  _description = description;
}

void logic::setCommand(std::string command){
	_command = command;
}

void logic::setTitle(std::string title){
	_title = title;
}

void logic::setTime(std::string time){
	_time = time;
}

void logic::setDate(std::string date){
	_date = date;
}

void logic::setLocation(std::string location){
	_location = location;
}

void logic::setDescription(std::string description){
	_description = description;
}

std::string logic::getCommand(){
	return _command;
}

std::string logic::getTitle(){
	return _title;
}

std::string logic::getTime(){
	return _time;
}
std::string logic::getDate(){
	return _date;
}
std::string logic::getLocation(){
	return _location;
}
std::string logic::getDescription(){
	return _description;
}

void logic::readCommand(std::string command){


}
