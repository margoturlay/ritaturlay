#define _CRT_SECURE_NO_WARNINGS

#pragma once

struct Initials
{
	Initials();

	Initials(std::string surname, std::string name, std::string patronymic);

	virtual void GetInfo();

	Initials& operator=(Initials initials);

	bool operator==(Initials initials);

	std::string name;

	std::string surname;

	std::string patronymic;
};

struct Contact : Initials
{
	Contact();

	Contact(std::string surname, std::string name, std::string patronymic, int day, int mon, int year, int phone);

	virtual void GetInfo();

	Contact& operator=(Contact contact);

	bool operator==(Contact contact);

	int phone;

	tm date;

	char dateToString[40] = "0";
};

struct Affair
{
	Affair();

	Affair(std::string affair, int day, int mon, int year);

	void GetInfo();

	Affair& operator=(Affair affair);

	bool operator==(Affair affair);

	char dateToString[100] = "0";

	std::string affair;

	tm date;
};

struct Call : Affair
{
	Call();

	Call(std::string affair, int day, int mon, int year, int min, int hour, Contact contact);

	void virtual GetInfo();

	virtual Call& operator=(Call call);

	virtual bool operator==(Call call);

	Contact contact;
};

struct Meeting : Affair
{
	Meeting();

	Meeting(std::string affair, int day, int mon, int year, int min, int hour, std::string location, int duration);

	void GetInfo();

	Meeting& operator=(Meeting meeting);

	bool operator==(Meeting meeting);

	std::string location;

	int duration;
};

struct Assignment : Affair
{
	Assignment();

	Assignment(std::string affair, int day, int mon, int year, int duration);

	void GetInfo();

	Assignment& operator=(Assignment assignment);

	bool operator==(Assignment assignment);

	int duration;
};

struct Note : Affair
{
	Note();

	Note(std::string affair, int day, int mon, int year);

	void GetInfo();

	Note& operator=(Note note);

	bool operator==(Note note);
};
