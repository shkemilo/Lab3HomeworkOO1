#include "Evidencija.h"
#include "Korisnik.h"
#include "Lista.h"
#include "Exceptions.h"

#include <string>
#include <exception>

Evidencija& Evidencija::operator+=(Korisnik& user)
{
	if (findKorisnik(user) != -1)
		throw UserException("User allready exsists!");

	users += user;

	return *this;
}

Korisnik& Evidencija::operator[](const std::string& username)
{
	int index = findKorisnik(username);
	if (index == -1)
		throw UserException("User with that username does not exsist!");

	return users[index];
}

const Korisnik& Evidencija::operator[](const std::string& username) const
{
	int index = findKorisnik(username);
	if (index == -1)
		throw UserException("User with that username does not exsist!");

	return users[index];
}

Evidencija& Evidencija::operator()(const std::string& username)
{
	int index = findKorisnik(username);
	if (index == -1)
		throw UserException("User with that username does not exsist!");

	users(index);

	return *this;
}

void Evidencija::ChangePassword(const std::string& username, const std::string& oldPass, const std::string& newPass)
{
	(*this)[username].ChangePassword(oldPass, newPass);
}

int Evidencija::findKorisnik(const Korisnik& user) const
{
	for (int i = 0; i < users.Count(); i++)
		if (users[i] == user)
			return i;

	return -1;
}

int Evidencija::findKorisnik(const std::string& username) const
{
	for (int i = 0; i < users.Count(); i++)
		if (users[i].GetUsername() == username)
			return i;

	return -1;
}