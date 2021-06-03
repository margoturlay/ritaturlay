#include <algorithm>
#include <iostream>

#include "Outlook.h"

Initials& Outlook::GetMyInitials()
{
	return m_myInitials_;
}

void Outlook::SetMyInitials(Initials initials)
{
	m_myInitials_.name = initials.name;
	m_myInitials_.surname = initials.surname;
	m_myInitials_.patronymic = initials.patronymic;
}

std::string Outlook::GetMyWorkPlace()
{
	return m_workPlace_;
}

void Outlook::SetMyWorkPlace(std::string workPlace)
{
	m_workPlace_ = workPlace;
}

Contact& Outlook::GetContact(int index)
{
	int counter = 1;
	auto it = m_contacts_.begin();
	while (counter < index) {
		++it;
		++counter;
	}
	return *it;
}

Contact& Outlook::FindContact(Initials initials)
{
	for (auto it = m_contacts_.begin(); it != m_contacts_.end(); ++it) {
		if ((*it).surname == initials.surname && (*it).name == initials.name && (*it).patronymic == initials.patronymic)
			return *it;
	}
	throw std::domain_error("contact not found");
}

void Outlook::AddContact(Contact contact)
{
	auto it = std::find(m_contacts_.begin(), m_contacts_.end(), contact);
	if (it == m_contacts_.end())
		m_contacts_.push_back(contact);
	else
		throw std::domain_error("the contact has already been recorded");
}

void Outlook::RemoveContact(int index)
{
	if (index > 0 && index <= m_contacts_.size()) {
		int counter = 1;
		Contact buff;
		for (auto it = m_contacts_.begin(); it != m_contacts_.end(); ++it) {
			if (counter == index) {
				buff = *it;
				m_contacts_.erase(it);
				break;
			}
			++counter;
		}
		bool isErase = true;
		auto it = std::find(m_friends_.begin(), m_friends_.end(), buff);
		if (it != m_friends_.end()) {
			m_friends_.erase(it);
			isErase = false;
		}
		if (isErase) {
			auto it = std::find(m_colleagues_.begin(), m_colleagues_.end(), buff);
			if (it != m_colleagues_.end()) {
				m_colleagues_.erase(it);
				isErase = false;
			}
		}
		if (isErase) {
			auto it = std::find(m_relatives_.begin(), m_relatives_.end(), buff);
			if (it != m_relatives_.end()) {
				m_relatives_.erase(it);
			}
		}
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetContactsSize()
{
	return m_contacts_.size();
}

Contact& Outlook::GetFriend(int index)
{
	if (index > 0 && index <= m_friends_.size()) {
		int counter = 1;
		auto it = m_friends_.begin();
		while (counter < index) {
			++it;
			++counter;
		}
		return *it;
	}
	else
		throw std::invalid_argument("incorrect index");
}

void Outlook::AddFriend(Contact contact)
{
	auto it = std::find(m_contacts_.begin(), m_contacts_.end(), contact);
	if (it == m_contacts_.end()) {
		m_contacts_.push_back(contact);
		m_friends_.push_back(contact);
	}
	else {
		auto it = std::find(m_friends_.begin(), m_friends_.end(), contact);
		if (it == m_friends_.end()) {
			m_friends_.push_back(contact);
		}
		else
			throw std::domain_error("the contact has already been recorded");
	}
}

void Outlook::RemoveFriend(int index)
{
	if (index > 0 && index <= m_friends_.size()) {
		int counter = 1;
		Contact buff;
		for (auto it = m_friends_.begin(); it != m_friends_.end(); ++it) {
			if (counter == index) {
				buff = *it;
				m_friends_.erase(it);
				break;
			}
			++counter;
		}
		auto it = std::find(m_contacts_.begin(), m_contacts_.end(), buff);
		m_contacts_.erase(it);
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetFriendsSize()
{
	return m_friends_.size();
}

Contact& Outlook::GetColleague(int index)
{
	int counter = 1;
	auto it = m_colleagues_.begin();
	while (counter < index) {
		++it;
		++counter;
	}
	return *it;
}

void Outlook::AddColleague(Contact contact)
{
	auto it = std::find(m_contacts_.begin(), m_contacts_.end(), contact);
	if (it == m_contacts_.end()) {
		m_contacts_.push_back(contact);
		m_colleagues_.push_back(contact);
	}
	else {
		auto it = std::find(m_colleagues_.begin(), m_colleagues_.end(), contact);
		if (it == m_colleagues_.end()) {
			m_colleagues_.push_back(contact);
		}
		else
			throw std::domain_error("the contact has already been recorded");
	}
}

void Outlook::RemoveColleague(int index)
{
	if (index > 0 && index <= m_colleagues_.size()) {
		int counter = 1;
		Contact buff;
		for (auto it = m_colleagues_.begin(); it != m_colleagues_.end(); ++it) {
			if (counter == index) {
				buff = *it;
				m_colleagues_.erase(it);
				break;
			}
			++counter;
		}
		auto it = std::find(m_contacts_.begin(), m_contacts_.end(), buff);
		m_contacts_.erase(it);
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetColleaguesSize()
{
	return m_colleagues_.size();
}

Contact& Outlook::GetRelative(int index)
{
	int counter = 1;
	auto it = m_relatives_.begin();
	while (counter < index) {
		++it;
		++counter;
	}
	return *it;
}

void Outlook::AddRelative(Contact contact)
{
	auto it = std::find(m_contacts_.begin(), m_contacts_.end(), contact);
	if (it == m_contacts_.end()) {
		m_contacts_.push_back(contact);
		m_relatives_.push_back(contact);
	}
	else {
		auto it = std::find(m_relatives_.begin(), m_relatives_.end(), contact);
		if (it == m_relatives_.end()) {
			m_relatives_.push_back(contact);
		}
		else
			throw std::domain_error("the contact has already been recorded");
	}
}

void Outlook::RemoveRelative(int index)
{
	if (index > 0 && index <= m_relatives_.size()) {
		int counter = 1;
		Contact buff;
		for (auto it = m_relatives_.begin(); it != m_relatives_.end(); ++it) {
			if (counter == index) {
				buff = *it;
				m_relatives_.erase(it);
				break;
			}
			++counter;
		}
		auto it = std::find(m_contacts_.begin(), m_contacts_.end(), buff);
		m_contacts_.erase(it);
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetRelativesSize()
{
	return   m_relatives_.size();
}

Call& Outlook::GetCall(int index)
{
	int counter = 1;
	auto it = m_calls_.begin();
	while (counter < index) {
		++it;
		++counter;
	}
	return *it;
}

void Outlook::AddCall(Call call)
{
	auto it = std::find(m_calls_.begin(), m_calls_.end(), call);
	if (it == m_calls_.end())
		m_calls_.push_back(call);
	else
		throw std::domain_error("the call has already been recorded");
}

void Outlook::RemoveCall(int index)
{
	if (index > 0 && index <= m_calls_.size()) {
		int counter = 1;
		for (auto it = m_calls_.begin(); it != m_calls_.end(); ++it) {
			if (counter == index) {
				m_calls_.erase(it);
				break;
			}
			++counter;
		}
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetCallsSize()
{
	return m_calls_.size();
}

Meeting& Outlook::GetMeeting(int index)
{
	int counter = 1;
	auto it = m_meetings_.begin();
	while (counter < index) {
		++it;
		++counter;
	}
	return *it;
}

void Outlook::AddMeeting(Meeting meeting)
{
	auto it = std::find(m_meetings_.begin(), m_meetings_.end(), meeting);
	if (it == m_meetings_.end())
		m_meetings_.push_back(meeting);
	else
		throw std::domain_error("the meeting has already been recorded");
}

void Outlook::RemoveMeeting(int index)
{
	if (index > 0 && index <= m_meetings_.size()) {
		int counter = 1;
		for (auto it = m_meetings_.begin(); it != m_meetings_.end(); ++it) {
			if (counter == index) {
				m_meetings_.erase(it);
				break;
			}
			++counter;
		}
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetMeetingsSize()
{
	return m_meetings_.size();
}

Assignment& Outlook::GetAssignment(int index)
{
	int counter = 1;
	auto it = m_assignments_.begin();
	while (counter < index) {
		++it;
		++counter;
	}
	return *it;
}

void Outlook::AddAssignment(Assignment assignment)
{
	auto it = std::find(m_assignments_.begin(), m_assignments_.end(), assignment);
	if (it == m_assignments_.end())
		m_assignments_.push_back(assignment);
	else
		throw std::domain_error("the assignment has already been recorded");
}

void Outlook::RemoveAssignment(int index)
{
	if (index > 0 && index <= m_assignments_.size()) {
		int counter = 1;
		for (auto it = m_assignments_.begin(); it != m_assignments_.end(); ++it) {
			if (counter == index) {
				m_assignments_.erase(it);
				break;
			}
			++counter;
		}
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetAssignmentsSize()
{
	return m_assignments_.size();
}

Note& Outlook::GetNote(int index)
{
	int counter = 1;
	auto it = m_notes_.begin();
	while (counter < index) {
		++it;
		++counter;
	}
	return *it;
}

void Outlook::AddNote(Note note)
{
	auto it = std::find(m_notes_.begin(), m_notes_.end(), note);
	if (it == m_notes_.end())
		m_notes_.push_back(note);
	else
		throw std::domain_error("the note has already been recorded");
}

void Outlook::RemoveNote(int index)
{
	if (index > 0 && index <= m_notes_.size()) {
		int counter = 1;
		for (auto it = m_notes_.begin(); it != m_notes_.end(); ++it) {
			if (counter == index) {
				m_notes_.erase(it);
				break;
			}
			++counter;
		}
	}
	else
		throw std::invalid_argument("incorrect index");
}

int Outlook::GetNotesSize()
{
	return m_notes_.size();
}
