#pragma once

#include "Outlook.h"

void Setup(Outlook& outlook, std::string fileName);

void GetMyInitials(std::ifstream& fin, Outlook& outlook);

void GetMyWorkplace(std::ifstream& fin, Outlook& outlook);

void GetContacts(std::ifstream& fin, Outlook& outlook);

void GetFriends(std::ifstream& fin, Outlook& outlook);

void GetColleagues(std::ifstream& fin, Outlook& outlook);

void GetRelatives(std::ifstream& fin, Outlook& outlook);

void GetCalls(std::ifstream& fin, Outlook& outlook);

void GetMeetings(std::ifstream& fin, Outlook& outlook);

void GetAssignments(std::ifstream& fin, Outlook& outlook);

void GetNotes(std::ifstream& fin, Outlook& outlook);

void RecordData(Outlook outlook, std::string fileName);

void RecordMyInitials(std::ofstream& fout, Outlook outlook);

void RecordMyWorkplace(std::ofstream& fout, Outlook outlook);

void RecordContacts(std::ofstream& fout, Outlook outlook);

void RecordFriends(std::ofstream& fout, Outlook outlook);

void RecordColleagues(std::ofstream& fout, Outlook outlook);

void RecordRelatives(std::ofstream& fout, Outlook outlook);

void RecordCalls(std::ofstream& fout, Outlook outlook);

void RecordMeetings(std::ofstream& fout, Outlook outlook);

void RecordAssignments(std::ofstream& fout, Outlook outlook);

void RecordNotes(std::ofstream& fout, Outlook outlook);
