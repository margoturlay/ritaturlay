#pragma once

#include "Outlook.h"

void Init(std::string inputFileName, std::string outputFileName);

void PrintMainInfo(Outlook outlook);

void PrintContactsInfo(Outlook outlook);

void MainMenu(Outlook& outlook);

void ContactsMenu(Outlook& outlook);

void ContactsGroupsMenu(Outlook& outlook);

void PrintContactsGroupsInfo(Outlook outlook);

void FriendsMenu(Outlook& outlook);

void PrintFriendsInfo(Outlook outlook);

void ColleaguesMenu(Outlook& outlook);

void PrintColleaguesInfo(Outlook outlook);

void RelativesMenu(Outlook& outlook);

void PrintRelativesInfo(Outlook outlook);

void AffairsMenu(Outlook& outlook);

void PrintAffairsInfo(Outlook outlook);

void CallsMenu(Outlook& outlook);

void PrintCallsInfo(Outlook outlook);

void MeetingsMenu(Outlook& outlook);

void PrintMeetingsInfo(Outlook outlook);

void AssignmentsMenu(Outlook& outlook);

void PrintAssigmentsInfo(Outlook outlook);

void NotesMenu(Outlook& outlook);

void PrintNotesInfo(Outlook outlook);

void GetReminders(Outlook outlook);

void FindEvents(Outlook outlook);
