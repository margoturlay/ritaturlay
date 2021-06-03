#include <fstream>
#include <time.h>

#include "DataBase.h"

void Setup(Outlook& outlook, std::string fileName)
{
	std::ifstream fin(fileName);
	GetMyInitials(fin, outlook);
	GetMyWorkplace(fin, outlook);
	GetContacts(fin, outlook);
	GetFriends(fin, outlook);
	GetColleagues(fin, outlook);
	GetRelatives(fin, outlook);
	GetCalls(fin, outlook);
	GetMeetings(fin, outlook);
	GetAssignments(fin, outlook);
	GetNotes(fin, outlook);
	fin.close();
}

void GetMyInitials(std::ifstream& fin, Outlook& outlook)
{
	Initials in;
	fin >> in.surname >> in.name >> in.patronymic;
	outlook.SetMyInitials(in);
}

void GetMyWorkplace(std::ifstream& fin, Outlook& outlook)
{
	std::string temp;
	fin.ignore(1);
	std::getline(fin, temp);
	outlook.SetMyWorkPlace(temp);
}

void GetContacts(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Contact con;
	for (int i = 0; i < amount; ++i) {
		fin >> con.surname >> con.name >> con.patronymic;
		fin >> con.phone;
		fin >> day >> mon >> year;
		con.date.tm_mday = day;
		con.date.tm_mon = mon - 1;
		con.date.tm_year = year - 1900;
		try {
			outlook.AddContact(con);
		}
		catch (std::domain_error ex) {}
	}
}

void GetFriends(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Contact con;
	for (int i = 0; i < amount; ++i) {
		fin >> con.surname >> con.name >> con.patronymic;
		fin >> con.phone;
		fin >> day >> mon >> year;
		con.date.tm_mday = day;
		con.date.tm_mon = mon - 1;
		con.date.tm_year = year - 1900;
		try {
			outlook.AddFriend(con);
		}
		catch (std::domain_error ex) {}
	}
}

void GetColleagues(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Contact con;
	for (int i = 0; i < amount; ++i) {
		fin >> con.surname >> con.name >> con.patronymic;
		fin >> con.phone;
		fin >> day >> mon >> year;
		con.date.tm_mday = day;
		con.date.tm_mon = mon - 1;
		con.date.tm_year = year - 1900;
		try {
			outlook.AddColleague(con);
		}
		catch (std::domain_error ex) {}
	}
}

void GetRelatives(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Contact con;
	for (int i = 0; i < amount; ++i) {
		fin >> con.surname >> con.name >> con.patronymic;
		fin >> con.phone;
		fin >> day >> mon >> year;
		con.date.tm_mday = day;
		con.date.tm_mon = mon - 1;
		con.date.tm_year = year - 1900;
		try {
			outlook.AddRelative(con);
		}
		catch (std::domain_error ex) {}
	}
}

void GetCalls(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Call call;
	Initials in;
	for (int i = 0; i < amount; ++i) {
		fin.ignore(1);
		std::getline(fin, call.affair);
		fin >> day >> mon >> year >> call.date.tm_hour >> call.date.tm_min;
		call.date.tm_mday = day;
		call.date.tm_mon = mon - 1;
		call.date.tm_year = year - 1900;
		fin >> in.surname >> in.name >> in.patronymic;
		try {
			call.contact = outlook.FindContact(in);
		}
		catch (std::domain_error ex) {
			call.contact = Contact(in.surname, in.name, in.patronymic, 1, 1, 1900, 1111111);
		}
		try {
			outlook.AddCall(call);
		}
		catch (std::domain_error ex) {}
	}
}

void GetMeetings(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Meeting meeting;
	for (int i = 0; i < amount; ++i) {
		fin.ignore(1);
		std::getline(fin, meeting.affair);
		fin >> day >> mon >> year >> meeting.date.tm_hour >> meeting.date.tm_min;
		meeting.date.tm_mday = day;
		meeting.date.tm_mon = mon - 1;
		meeting.date.tm_year = year - 1900;
		fin >> meeting.duration;
		fin.ignore(1);
		std::getline(fin, meeting.location);
		try {
			outlook.AddMeeting(meeting);
		}
		catch (std::domain_error ex) {}
	}
}

void GetAssignments(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Assignment assignment;
	for (int i = 0; i < amount; ++i) {
		fin.ignore(1);
		std::getline(fin, assignment.affair);
		fin >> day >> mon >> year;
		assignment.date.tm_mday = day;
		assignment.date.tm_mon = mon - 1;
		assignment.date.tm_year = year - 1900;
		fin >> assignment.duration;
		try {
			outlook.AddAssignment(assignment);
		}
		catch (std::domain_error ex) {}
	}
}

void GetNotes(std::ifstream& fin, Outlook& outlook)
{
	int amount, day, mon, year;
	fin >> amount;
	Note note;
	for (int i = 0; i < amount; ++i) {
		fin.ignore(1);
		std::getline(fin, note.affair);
		fin >> day >> mon >> year;
		note.date.tm_mday = day;
		note.date.tm_mon = mon - 1;
		note.date.tm_year = year - 1900;
		try {
			outlook.AddNote(note);
		}
		catch (std::domain_error ex) {}
	}
}

void RecordData(Outlook outlook, std::string fileName)
{
	std::ofstream fout(fileName);
	RecordMyInitials(fout, outlook);
	RecordMyWorkplace(fout, outlook);
	RecordContacts(fout, outlook);
	RecordFriends(fout, outlook);
	RecordColleagues(fout, outlook);
	RecordRelatives(fout, outlook);
	RecordCalls(fout, outlook);
	RecordMeetings(fout, outlook);
	RecordAssignments(fout, outlook);
	RecordNotes(fout, outlook);
	fout.close();
}

void RecordMyInitials(std::ofstream& fout, Outlook outlook)
{
	Initials in = outlook.GetMyInitials();
	fout << in.surname << " " << in.name << " " << in.patronymic << "\n";
}

void RecordMyWorkplace(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetMyWorkPlace() << "\n";
}

void RecordContacts(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetContactsSize() << '\n';
	Contact con;
	for (int i = 0; i < outlook.GetContactsSize(); ++i) {
		con = outlook.GetContact(i + 1);
		fout << con.surname << " " << con.name << " " << con.patronymic << "\n";
		fout << con.phone << "\n";
		fout << con.date.tm_mday << " " << con.date.tm_mon + 1 << " " << con.date.tm_year + 1900 << "\n";
	}
}

void RecordFriends(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetFriendsSize() << '\n';
	Contact con;
	for (int i = 0; i < outlook.GetFriendsSize(); ++i) {
		con = outlook.GetFriend(i + 1);
		fout << con.surname << " " << con.name << " " << con.patronymic << "\n";
		fout << con.phone << "\n";
		fout << con.date.tm_mday << " " << con.date.tm_mon + 1 << " " << con.date.tm_year + 1900 << "\n";
	}
}

void RecordColleagues(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetColleaguesSize() << '\n';
	Contact con;
	for (int i = 0; i < outlook.GetColleaguesSize(); ++i) {
		con = outlook.GetColleague(i + 1);
		fout << con.surname << " " << con.name << " " << con.patronymic << "\n";
		fout << con.phone << "\n";
		fout << con.date.tm_mday << " " << con.date.tm_mon + 1 << " " << con.date.tm_year + 1900 << "\n";
	}
}

void RecordRelatives(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetRelativesSize() << '\n';
	Contact con;
	for (int i = 0; i < outlook.GetRelativesSize(); ++i) {
		con = outlook.GetRelative(i + 1);
		fout << con.surname << " " << con.name << " " << con.patronymic << "\n";
		fout << con.phone << "\n";
		fout << con.date.tm_mday << " " << con.date.tm_mon + 1 << " " << con.date.tm_year + 1900 << "\n";
	}
}

void RecordCalls(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetCallsSize() << '\n';
	Call call;
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		call = outlook.GetCall(i + 1);
		fout << call.affair << "\n";
		fout << call.date.tm_mday << " " << call.date.tm_mon + 1 << " " << call.date.tm_year + 1900 << " " << call.date.tm_hour << " " << call.date.tm_min << "\n";
		fout << call.contact.surname << " " << call.contact.name << " " << call.contact.patronymic << "\n";
	}
}

void RecordMeetings(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetMeetingsSize() << '\n';
	Meeting meeting;
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		meeting = outlook.GetMeeting(i + 1);
		fout << meeting.affair << "\n";
		fout << meeting.date.tm_mday << " " << meeting.date.tm_mon + 1 << " " << meeting.date.tm_year + 1900 << " " << meeting.date.tm_hour << " " << meeting.date.tm_min << "\n";
		fout << meeting.duration << "\n";
		fout << meeting.location << "\n";
	}
}

void RecordAssignments(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetAssignmentsSize() << '\n';
	Assignment assignment;
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		assignment = outlook.GetAssignment(i + 1);
		fout << assignment.affair << "\n";
		fout << assignment.date.tm_mday << " " << assignment.date.tm_mon + 1 << " " << assignment.date.tm_year + 1900 << "\n";
		fout << assignment.duration << "\n";
	}
}

void RecordNotes(std::ofstream& fout, Outlook outlook)
{
	fout << outlook.GetNotesSize() << '\n';
	Note note;
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		note = outlook.GetNote(i + 1);
		fout << note.affair << "\n";
		fout << note.date.tm_mday << " " << note.date.tm_mon + 1 << " " << note.date.tm_year + 1900 << "\n";
	}
}