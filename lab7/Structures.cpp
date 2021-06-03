#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <time.h>
#include <string.h>

#include "Structures.h"

Initials::Initials()
{
	surname = "";
	name = "";
	patronymic = "";
}

Initials::Initials(std::string surname, std::string name, std::string patronymic)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
}

void Initials::GetInfo()
{
	std::cout << surname << " " << name << " " << patronymic << std::endl;
}

Initials& Initials::operator=(Initials initials)
{
	this->surname = initials.surname;
	this->name = initials.name;
	this->patronymic = initials.patronymic;
	return *this;
}

bool Initials::operator==(Initials initials)
{
	if (this->name == initials.name
		&& this->surname == initials.surname
		&& this->patronymic == initials.patronymic)
		return true;
	return false;
}

Contact::Contact() : Initials()
{
	phone = 0;
	date = { 0 };
}

Contact::Contact(std::string surname, std::string name, std::string patronymic, int day, int mon, int year, int phone) : Initials(surname, name, patronymic)
{
	date.tm_mday = day;
	date.tm_mon = mon;
	date.tm_year = year;
	this->phone = phone;
}

void Contact::GetInfo()
{
	Initials::GetInfo();
	strftime(dateToString, 40, "%d.%m.%Y", &date);
	std::cout << "Номер телефона: " << phone << std::endl;
	std::cout << "День рождения: " << dateToString << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
}

Contact& Contact::operator=(Contact contact)
{
	Initials::operator=(contact);
	this->phone = contact.phone;
	this->date = contact.date;
	return *this;
}

bool Contact::operator==(Contact contact)
{
	if (Initials::operator==(contact)) {
		if (this->phone == contact.phone
			&& this->date.tm_year == contact.date.tm_year
			&& this->date.tm_mon == contact.date.tm_mon
			&& this->date.tm_mday == contact.date.tm_mday)
			return true;
	}
	return false;
}


Affair::Affair()
{
	affair = "";
	date = { 0 };
}

Affair::Affair(std::string affair, int day, int mon, int year)
{
	this->affair = affair;
	date.tm_mday = day;
	date.tm_mon = mon;
	date.tm_year = year;
}

void Affair::GetInfo()
{
	strftime(dateToString, 100, "Число: %d.%m.%Y", &date);
	std::cout << "Тема: " << affair << std::endl;
	std::cout << dateToString << std::endl;
}

Affair& Affair::operator=(Affair affair)
{
	this->affair = affair.affair;
	this->date = affair.date;
	return *this;
}

bool Affair::operator==(Affair affair)
{

	if (this->affair == affair.affair
		&& this->date.tm_year == affair.date.tm_year
		&& this->date.tm_mon == affair.date.tm_mon
		&& this->date.tm_mday == affair.date.tm_mday)
		return true;
	return false;
}

Call::Call() : Affair() {	}

Call::Call(std::string affair, int day, int mon, int year, int min, int hour, Contact contact) : Affair(affair, day, mon, year)
{
	this->contact = contact;
	date.tm_hour = hour;
	date.tm_min = min;
}

void Call::GetInfo()
{
	Affair::GetInfo();
	char buff[40];
	strftime(buff, 40, "Время: %H:%M", &date);
	strncat(dateToString, buff, 40);
	std::cout << buff << std::endl;
	std::cout << "Кому: " << contact.surname << " " << contact.name << " " << contact.patronymic << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
}

Call& Call::operator=(Call call)
{
	Affair::operator=(call);
	this->contact = call.contact;
	return *this;
}

bool Call::operator==(Call call)
{
	if (Affair::operator==(call)
		&& this->contact == call.contact
		&& this->date.tm_hour == call.date.tm_hour
		&& this->date.tm_min == call.date.tm_min)
		return true;
	return false;
}

Meeting::Meeting() : Affair()
{
	location = "";
	duration = 0;
}

Meeting::Meeting(std::string affair, int day, int mon, int year, int min, int hour, std::string location, int duration) : Affair(affair, day, mon, year)
{
	this->location = location;
	this->duration = duration;
	date.tm_hour = hour;
	date.tm_min = min;
}

void Meeting::GetInfo()
{
	Affair::GetInfo();
	char buff[40];
	strftime(buff, 40, "Время: %H:%M", &date);
	strncat(dateToString, buff, 40);
	std::cout << buff << std::endl;
	if (duration >= 60) {
		int hours = duration / 60;
		int minutes = duration % 60;
		if (minutes)
			std::cout << "Продолжительность: " << hours << " ч " << minutes << " мин" << std::endl;
		else
			std::cout << "Продолжительность: " << hours << " ч" << std::endl;
	}
	else
		std::cout << "Продолжительность: " << duration << " мин" << std::endl;
	std::cout << "Место проведения: " << location << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
}

Meeting& Meeting::operator=(Meeting meeting)
{
	Affair::operator=(meeting);
	this->location = meeting.location;
	this->duration = meeting.duration;
	return *this;
}

bool Meeting::operator==(Meeting meeting)
{
	Affair::operator==(meeting);
	if (this->location == meeting.location
		&& this->date.tm_hour == meeting.date.tm_hour
		&& this->date.tm_min == meeting.date.tm_min)
		return true;
	return false;
}

Assignment::Assignment() : Affair()
{
	duration = 0;
}

Assignment::Assignment(std::string affair, int day, int mon, int year, int duration) : Affair(affair, day, mon, year)
{
	this->duration = duration;
}

void Assignment::GetInfo()
{
	Affair::GetInfo();
	if (duration >= 60) {
		int hours = duration / 60;
		int minutes = duration % 60;
		if (minutes)
			std::cout << "Продолжительность: " << hours << " ч " << minutes << " мин" << std::endl;
		else
			std::cout << "Продолжительность: " << hours << " ч" << std::endl;
	}
	else
		std::cout << "Продолжительность: " << duration << " мин" << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
}

Assignment& Assignment::operator=(Assignment assignment)
{
	Affair::operator=(assignment);
	this->duration = assignment.duration;
	return *this;
}

bool Assignment::operator==(Assignment assignment)
{
	Affair::operator==(assignment);
	if (this->duration == assignment.duration
		&& this->date.tm_hour == assignment.date.tm_hour
		&& this->date.tm_min == assignment.date.tm_min)
		return true;
	return false;
}

Note::Note() : Affair() {	}

Note::Note(std::string affair, int day, int mon, int year) : Affair(affair, day, mon, year) {	}

void Note::GetInfo()
{
	Affair::GetInfo();
	std::cout << "_______________________________________________________" << std::endl;
}

Note& Note::operator=(Note note)
{
	Affair::operator=(note);
	return *this;
}

bool Note::operator==(Note note)
{
	return Affair::operator==(note);
}