#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <iostream>

#include "Interface.h"
#include "Outlook.h"
#include "DataBase.h"

void Init(std::string inputFileName, std::string outputFileName)
{
	Outlook outlook;
	Setup(outlook, inputFileName);
	MainMenu(outlook);
	RecordData(outlook, outputFileName);
}

void PrintMainInfo(Outlook outlook)
{
	Initials myIn;
	myIn = outlook.GetMyInitials();
	myIn.GetInfo();
	std::cout << outlook.GetMyWorkPlace() << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	std::cout << "1 - Контакты" << std::endl;
	std::cout << "2 - Группы контактов" << std::endl;
	std::cout << "3 - Дела" << std::endl;
	std::cout << "4 - Напоминания" << std::endl;
	std::cout << "5 - Поиск мероприятий" << std::endl;
	std::cout << "Esc - Выйти из программы" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void PrintContactsInfo(Outlook outlook)
{
	std::cout << "Контакты: " << std::endl;
	for (int i = 0; i < outlook.GetContactsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetContact(i + 1).GetInfo();
	}
	std::cout << "1.1 - Добавить новый контакт" << std::endl;
	std::cout << "1.2 - Удалить контакт" << std::endl;
	std::cout << "Esc - Вернуться в главное меню" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void MainMenu(Outlook& outlook)
{
	PrintMainInfo(outlook);
	bool isBreak = true;
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49:
				ContactsMenu(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 50:
				ContactsGroupsMenu(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 51:
				AffairsMenu(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 52:
				GetReminders(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 53:
				FindEvents(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 27:
				isBreak = false;
				break;
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void ContactsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintContactsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "Введите ФИО нового контакта: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "Введите дату рождения нового контакта: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "Введите номер телефона нового контакта: ";
				std::cin >> con.phone;
				try
				{
					outlook.AddContact(con);
				}
				catch (std::domain_error ex)
				{
					system("cls");
					std::cout << "Данный контакт уже присутсвует в вашей контактной книге!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintContactsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "Контакт успешно добавлен!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintContactsInfo(outlook);
				break;
			}
			case 50: {  //2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемый контакт: ";
				std::cin >> index;
				try {
					outlook.RemoveContact(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "Контакт успешно удалён!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintContactsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void ContactsGroupsMenu(Outlook& outlook)
{
	system("cls");
	PrintContactsGroupsInfo(outlook);
	bool isBreak = true;
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49:
				FriendsMenu(outlook);
				system("cls");
				PrintContactsGroupsInfo(outlook);
				break;
			case 50:
				ColleaguesMenu(outlook);
				system("cls");
				PrintContactsGroupsInfo(outlook);
				break;
			case 51:
				RelativesMenu(outlook);
				system("cls");
				PrintContactsGroupsInfo(outlook);
				break;
			case 27:
				isBreak = false;
				break;
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintContactsGroupsInfo(Outlook outlook)
{
	std::cout << "Группы: " << std::endl;
	std::cout << "2.1 - Друзья" << std::endl;
	std::cout << "2.2 - Коллеги" << std::endl;
	std::cout << "2.3 - Родственники" << std::endl;
	std::cout << "Esc - Вернуться в главное меню" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void FriendsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintFriendsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "Введите ФИО нового контакта: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "Введите дату рождения нового контакта: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "Введите номер телефона нового контакта: ";
				std::cin >> con.phone;
				try {
					outlook.AddFriend(con);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "Данный контакт уже присутсвует в вашей контактной книге!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintFriendsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "Контакт успешно добавлен!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintFriendsInfo(outlook);
				break;
			}
			case 50: {  //2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемый контакт: ";
				std::cin >> index;
				try {
					outlook.RemoveFriend(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "Контакт успешно удалён!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintFriendsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintFriendsInfo(Outlook outlook)
{
	std::cout << "Друзья: " << std::endl;
	for (int i = 0; i < outlook.GetFriendsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetFriend(i + 1).GetInfo();
	}
	std::cout << "2.1.1 - Добавить новый контакт" << std::endl;
	std::cout << "2.1.2 - Удалить контакт" << std::endl;
	std::cout << "Esc - Вернуться к группам" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void ColleaguesMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintColleaguesInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "Введите ФИО нового контакта: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "Введите дату рождения нового контакта: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "Введите номер телефона нового контакта: ";
				std::cin >> con.phone;
				try {
					outlook.AddColleague(con);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "Данный контакт уже присутсвует в вашей контактной книге!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintColleaguesInfo(outlook);
					break;
				}
				std::cout << "Контакт успешно добавлен!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintColleaguesInfo(outlook);
				break;
			}
			case 50: {  //2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемый контакт: ";
				std::cin >> index;
				try {
					outlook.RemoveColleague(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "Контакт успешно удалён!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintColleaguesInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintColleaguesInfo(Outlook outlook)
{
	std::cout << "Коллеги: " << std::endl;
	for (int i = 0; i < outlook.GetColleaguesSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetColleague(i + 1).GetInfo();
	}
	std::cout << "2.2.1 - Добавить новый контакт" << std::endl;
	std::cout << "2.2.2 - Удалить контакт" << std::endl;
	std::cout << "Esc - Вернуться к группам" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void RelativesMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintRelativesInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "Введите ФИО нового контакта: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "Введите дату рождения нового контакта: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "Введите номер телефона нового контакта: ";
				std::cin >> con.phone;
				try {
					outlook.AddRelative(con);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "Данный контакт уже присутсвует в вашей контактной книге!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintRelativesInfo(outlook);
					break;
				}
				std::cout << "Контакт успешно добавлен!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintRelativesInfo(outlook);
				break;
			}
			case 50: {  // 2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемый контакт: ";
				std::cin >> index;
				try {
					outlook.RemoveRelative(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "Контакт успешно удалён!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintRelativesInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintRelativesInfo(Outlook outlook)
{
	std::cout << "Родственники: " << std::endl;
	for (int i = 0; i < outlook.GetRelativesSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetRelative(i + 1).GetInfo();
	}
	std::cout << "2.3.1 - Добавить новый контакт" << std::endl;
	std::cout << "2.3.2 - Удалить контакт" << std::endl;
	std::cout << "Esc - Вернуться к группам" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void AffairsMenu(Outlook& outlook)
{
	system("cls");
	PrintAffairsInfo(outlook);
	bool isBreak = true;
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49:
				CallsMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 50:
				MeetingsMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 51:
				AssignmentsMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 52:
				NotesMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 27:
				isBreak = false;
				break;
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintAffairsInfo(Outlook outlook)
{
	std::cout << "Дела: " << std::endl;
	std::cout << "3.1 - Звонки" << std::endl;
	std::cout << "3.2 - Встречи" << std::endl;
	std::cout << "3.3 - Задания" << std::endl;
	std::cout << "3.4 - Пометки" << std::endl;
	std::cout << "Esc - Вернуться в главное меню" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void CallsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintCallsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Call call;
				Initials in;
				Contact con;
				int day, month, year;
				std::cout << "Введите тему звонка: ";
				std::cin.ignore(); // РАЗОБРАТЬСЯ С CIN.IGNORE
				std::getline(std::cin, call.affair);
				std::cout << "Введите дату, на которую нужно совершить звонок: ";
				std::cin >> day >> month >> year;
				call.date.tm_mday = day;
				call.date.tm_mon = month - 1;
				call.date.tm_year = year - 1900;
				std::cout << "Введите время, когда необходимо позвонить: ";
				std::cin >> call.date.tm_hour >> call.date.tm_min;
				std::cout << "Введите ФИО контакта, которому необходимо позвонить: ";
				std::cin >> in.surname >> in.name >> in.patronymic;
				try {
					con = outlook.FindContact(in);
				}
				catch (std::domain_error ex) {
					std::cout << "Данного контакта нет в вашей контактной книге, хотите его добавить?" << std::endl;
					std::cout << "1 - Да" << std::endl;
					std::cout << "2 - Нет" << std::endl;
					std::cout << "Нажмите необходимую клавишу...";
					bool isBreak = true;
					while (isBreak) {
						if (_kbhit()) {
							switch (_getch()) {
							case 49:
								int bDay, bMonth, bYear, phone;
								std::cout << "\nВведите дату рождения нового контакта: ";
								std::cin >> bDay >> bMonth >> bYear;
								std::cout << "Введите номер телефона нового контакта: ";
								std::cin >> phone;
								con = Contact(in.surname, in.name, in.patronymic, bDay, bMonth, bYear, phone);
								outlook.AddContact(con);
								std::cout << "Контакт успешно добавлен!" << std::endl;
								Sleep(1000);
								isBreak = false;
								break;
							case 50:
								con = Contact(in.surname, in.name, in.patronymic, 1, 1, 1900, 1111111);
								isBreak = false;
								break;
							default:
								std::cout << "\nНеверный ввод, повторите заново: ";
								break;
							}
						}
					}
				}
				call.contact = con;
				try {
					outlook.AddCall(call);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "Данный звонок уже записан!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintCallsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "Звонок успешно добавлен!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintCallsInfo(outlook);
				break;
			}
			case 50: {  // 2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемый звонок: ";
				std::cin >> index;
				try {
					outlook.RemoveCall(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "Звонок успешно удалён!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintCallsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintCallsInfo(Outlook outlook)
{
	std::cout << "Звонки: " << std::endl;
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetCall(i + 1).GetInfo();
	}
	std::cout << "3.1.1 - Добавить новый звонок" << std::endl;
	std::cout << "3.1.2 - Удалить звонок" << std::endl;
	std::cout << "Esc - Вернуться к делам" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void MeetingsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintMeetingsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Meeting meeting;
				int day, month, year;
				std::cout << "Введите цель встречи: ";
				std::cin.ignore(1);
				std::getline(std::cin, meeting.affair);
				std::cout << "Введите дату, когда необходимо встретиться: ";
				std::cin >> day >> month >> year;
				meeting.date.tm_mday = day;
				meeting.date.tm_mon = month - 1;
				meeting.date.tm_year = year - 1900;
				std::cout << "Введите время, когда необходимо встретиться: ";
				std::cin >> meeting.date.tm_hour >> meeting.date.tm_min;
				std::cout << "Введите место встречи: ";
				std::cin.ignore(1);
				std::getline(std::cin, meeting.location);
				std::cout << "Введите предположительную продолжительность встречи: ";
				std::cin >> meeting.duration;
				try {
					outlook.AddMeeting(meeting);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "Данная встреча уже записана!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintMeetingsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "Встреча успешно добавлена!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintMeetingsInfo(outlook);
				break;
			}
			case 50: { // 2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемая встреча: ";
				std::cin >> index;
				try {
					outlook.RemoveMeeting(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "Встреча успешно удалёна!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintMeetingsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintMeetingsInfo(Outlook outlook)
{
	std::cout << "Встречи: " << std::endl;
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetMeeting(i + 1).GetInfo();
	}
	std::cout << "3.2.1 - Добавить новую встречу" << std::endl;
	std::cout << "3.2.2 - Удалить встречу" << std::endl;
	std::cout << "Esc - Вернуться к делам" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void AssignmentsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintAssigmentsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Assignment assignment;
				int day, month, year;
				std::cout << "Введите задание: ";
				std::cin.ignore(1);
				std::getline(std::cin, assignment.affair);
				std::cout << "Введите дату, когда необходимо выполнить задание: ";
				std::cin >> day >> month >> year;
				assignment.date.tm_mday = day;
				assignment.date.tm_mon = month - 1;
				assignment.date.tm_year = year - 1900;
				std::cout << "Введите предположительную продолжительность встречи: ";
				std::cin >> assignment.duration;
				try {
					outlook.AddAssignment(assignment);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "Данное задание уже записано!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintAssigmentsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "Задание успешно добавлено!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintAssigmentsInfo(outlook);
				break;
			}
			case 50: { // 2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемое задание: ";
				std::cin >> index;
				try {
					outlook.RemoveAssignment(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: ";
					break;
				}
				system("cls");
				std::cout << "Задание успешно удалёно!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintAssigmentsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintAssigmentsInfo(Outlook outlook)
{
	std::cout << "Задания: " << std::endl;
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetAssignment(i + 1).GetInfo();
	}
	std::cout << "3.3.1 - Добавить новое задание" << std::endl;
	std::cout << "3.3.2 - Удалить задание" << std::endl;
	std::cout << "Esc - Вернуться к делам" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void NotesMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintNotesInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Note note;
				int day, month, year;
				std::cout << "Введите название пометки: ";
				std::cin.ignore(1);
				std::getline(std::cin, note.affair);
				std::cout << "Введите дату, когда необходимо напомнить о пометке: ";
				std::cin >> day >> month >> year;
				note.date.tm_mday = day;
				note.date.tm_mon = month - 1;
				note.date.tm_year = year - 1900;
				try {
					outlook.AddNote(note);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "Данная пометка уже записана!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintNotesInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "Пометка успешно добавлена!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintNotesInfo(outlook);
				break;
			}
			case 50: { // 2
				int index;
				std::cout << "\nВведите номер, которому соотвествует удаляемая встреча: ";
				std::cin >> index;
				try {
					outlook.RemoveNote(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "Вы ввели неверный номер, попробуйте ещё раз: ";
					break;
				}
				system("cls");
				std::cout << "Пометка успешно удалёна!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintNotesInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\nНеверный ввод, повторите заново: ";
				break;
			}
		}
	}
}

void PrintNotesInfo(Outlook outlook)
{
	std::cout << "Пометки: " << std::endl;
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetNote(i + 1).GetInfo();
	}
	std::cout << "3.4.1 - Добавить новую пометку" << std::endl;
	std::cout << "3.4.2 - Удалить пометку" << std::endl;
	std::cout << "Esc - Вернуться к делам" << std::endl;
	std::cout << "Нажмите необходимую клавишу...";
}

void GetReminders(Outlook outlook)
{
	system("cls");
	std::time_t t = std::time(0);
	tm* local = std::localtime(&t);
	Contact con;
	Call call;
	Meeting meeting;
	Assignment assignment;
	Note note;
	std::cout << "Сегодня необходимо поздравить с Днём Рождения следующих людей из вашей контактной книги: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetContactsSize(); ++i) {
		con = outlook.GetContact(i + 1);
		if (con.date.tm_mon == (*local).tm_mon
			&& con.date.tm_mday == (*local).tm_mday)
			con.GetInfo();
	}
	std::cout << "Сегодня необходимо совершить следующие звонки: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		call = outlook.GetCall(i + 1);
		if (call.date.tm_year == (*local).tm_year
			&& call.date.tm_mon == (*local).tm_mon
			&& call.date.tm_mday == (*local).tm_mday)
			call.GetInfo();
	}
	std::cout << "Сегодня вас ожидают следующие встречи: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		meeting = outlook.GetMeeting(i + 1);
		if (meeting.date.tm_year == (*local).tm_year
			&& meeting.date.tm_mon == (*local).tm_mon
			&& meeting.date.tm_mday == (*local).tm_mday)
			meeting.GetInfo();
	}
	std::cout << "Сегодня выполнить следующие задания: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		assignment = outlook.GetAssignment(i + 1);
		if (assignment.date.tm_year == (*local).tm_year
			&& assignment.date.tm_mon == (*local).tm_mon
			&& assignment.date.tm_mday == (*local).tm_mday)
			assignment.GetInfo();
	}
	std::cout << "Сегодня выполнить следующие задания: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		note = outlook.GetNote(i + 1);
		if (note.date.tm_year == (*local).tm_year
			&& note.date.tm_mon == (*local).tm_mon
			&& note.date.tm_mday == (*local).tm_mday)
			note.GetInfo();
	}
	std::cout << "Нажмите любую клавишу для продолжения...";
	_getch();
}

void FindEvents(Outlook outlook)
{
	system("cls");
	tm local = { 0 };
	Call call;
	Meeting meeting;
	Assignment assignment;
	Note note;
	int day, month, year;
	std::cout << "Введите дату, на которую хотите просмотреть мероприятия: ";
	std::cin >> day >> month >> year;
	local.tm_mday = day;
	local.tm_mon = month - 1;
	local.tm_year = year - 1900;
	system("cls");
	std::cout << "На заданную дату запланированы следующие мероприятия: " << std::endl << std::endl;
	std::cout << "Необходимо совершить следующие звонки: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		call = outlook.GetCall(i + 1);
		if (call.date.tm_year == local.tm_year
			&& call.date.tm_mon == local.tm_mon
			&& call.date.tm_mday == local.tm_mday)
			call.GetInfo();
	}
	std::cout << "Вас ожидают следующие встречи: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		meeting = outlook.GetMeeting(i + 1);
		if (meeting.date.tm_year == local.tm_year
			&& meeting.date.tm_mon == local.tm_mon
			&& meeting.date.tm_mday == local.tm_mday)
			meeting.GetInfo();
	}
	std::cout << "Выполнить следующие задания: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		assignment = outlook.GetAssignment(i + 1);
		if (assignment.date.tm_year == local.tm_year
			&& assignment.date.tm_mon == local.tm_mon
			&& assignment.date.tm_mday == local.tm_mday)
			assignment.GetInfo();
	}
	std::cout << "Выполнить следующие задания: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		note = outlook.GetNote(i + 1);
		if (note.date.tm_year == local.tm_year
			&& note.date.tm_mon == local.tm_mon
			&& note.date.tm_mday == local.tm_mday)
			note.GetInfo();
	}
	std::cout << "Нажмите любую клавишу для продолжения...";
	_getch();
}