#pragma once

#include <list>
#include <string>

#include "Structures.h"

class Outlook
{
public:
	Initials& GetMyInitials();

	void SetMyInitials(Initials initials);

	std::string GetMyWorkPlace();

	void SetMyWorkPlace(std::string workPlace);

	Contact& GetContact(int index);

	Contact& FindContact(Initials initials);

	void AddContact(Contact contact);

	void RemoveContact(int index);

	int GetContactsSize();

	Contact& GetFriend(int index);

	void AddFriend(Contact contact);

	void RemoveFriend(int index);

	int GetFriendsSize();

	Contact& GetColleague(int index);

	void AddColleague(Contact contact);

	void RemoveColleague(int index);

	int GetColleaguesSize();

	Contact& GetRelative(int index);

	void AddRelative(Contact contact);

	void RemoveRelative(int index);

	int GetRelativesSize();

	Call& GetCall(int index);

	void AddCall(Call call);

	void RemoveCall(int index);

	int GetCallsSize();

	Meeting& GetMeeting(int index);

	void AddMeeting(Meeting meeting);

	void RemoveMeeting(int index);

	int GetMeetingsSize();

	Assignment& GetAssignment(int index);

	void AddAssignment(Assignment affair);

	void RemoveAssignment(int index);

	int GetAssignmentsSize();

	Note& GetNote(int index);

	void AddNote(Note note);

	void RemoveNote(int index);

	int GetNotesSize();

private:
	Initials m_myInitials_;
	std::string m_workPlace_;
	std::list<Contact> m_contacts_;
	std::list<Contact> m_friends_;
	std::list<Contact> m_colleagues_;
	std::list<Contact> m_relatives_;
	std::list<Call> m_calls_;
	std::list<Meeting> m_meetings_;
	std::list<Assignment> m_assignments_;
	std::list<Note> m_notes_;
};

