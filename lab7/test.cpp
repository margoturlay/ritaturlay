#include <cassert>
#include <iomanip>

#include "DataBase.h"

void test()
{
	setlocale(LC_ALL, "ru");
	std::string inputFileName = "testInput.txt";
	std::string outputFileName = "testOutput.txt";
	Outlook outlook;
	Setup(outlook, inputFileName);
	RecordData(outlook, outputFileName);
	Outlook testOutlook;
	Setup(testOutlook, outputFileName);

	assert(outlook.GetMyInitials() == testOutlook.GetMyInitials());

	assert(outlook.GetMyWorkPlace() == testOutlook.GetMyWorkPlace());

	Contact outlookCon;
	Contact testOutlookCon;

	assert(outlook.GetContactsSize() == testOutlook.GetContactsSize());
	for (int i = 0; i < outlook.GetContactsSize(); ++i) {
		outlookCon = outlook.GetContact(i + 1);
		testOutlookCon = testOutlook.GetContact(i + 1);
		assert(outlookCon == testOutlookCon);
	}

	assert(outlook.GetFriendsSize() == testOutlook.GetFriendsSize());
	for (int i = 0; i < outlook.GetFriendsSize(); ++i) {
		outlookCon = outlook.GetFriend(i + 1);
		testOutlookCon = testOutlook.GetFriend(i + 1);
		assert(outlookCon == testOutlookCon);
	}

	assert(outlook.GetColleaguesSize() == testOutlook.GetColleaguesSize());
	for (int i = 0; i < outlook.GetColleaguesSize(); ++i) {
		outlookCon = outlook.GetColleague(i + 1);
		testOutlookCon = testOutlook.GetColleague(i + 1);
		assert(outlookCon == testOutlookCon);
	}

	assert(outlook.GetRelativesSize() == testOutlook.GetRelativesSize());
	for (int i = 0; i < outlook.GetRelativesSize(); ++i) {
		outlookCon = outlook.GetRelative(i + 1);
		testOutlookCon = testOutlook.GetRelative(i + 1);
		assert(outlookCon == testOutlookCon);
	}

	Call outlookCall;
	Call testOutlookCall;

	assert(outlook.GetCallsSize() == testOutlook.GetCallsSize());
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		outlookCall = outlook.GetCall(i + 1);
		testOutlookCall = testOutlook.GetCall(i + 1);
		assert(outlookCall == testOutlookCall);
	}

	Meeting outlookMeeting;
	Meeting testOutlookMeeting;

	assert(outlook.GetMeetingsSize() == testOutlook.GetMeetingsSize());
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		outlookMeeting = outlook.GetMeeting(i + 1);
		testOutlookMeeting = testOutlook.GetMeeting(i + 1);
		assert(outlookMeeting == testOutlookMeeting);
	}

	Assignment outlookAssignment;
	Assignment testOutlookAssignment;

	assert(outlook.GetAssignmentsSize() == testOutlook.GetAssignmentsSize());
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		outlookAssignment = outlook.GetAssignment(i + 1);
		testOutlookAssignment = testOutlook.GetAssignment(i + 1);
		assert(outlookAssignment == testOutlookAssignment);
	}

	Note outlookNote;
	Note testOutlookNote;

	assert(outlook.GetNotesSize() == testOutlook.GetNotesSize());
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		outlookNote = outlook.GetNote(i + 1);
		testOutlookNote = testOutlook.GetNote(i + 1);
		assert(outlookNote == testOutlookNote);
	}
}

#undef main

int main()
{
	test();
	return 0;
}