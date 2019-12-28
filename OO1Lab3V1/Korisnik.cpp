#include "Korisnik.h"
#include "Exceptions.h"
#include <string>
#include <iostream>
#include <ctype.h>

Korisnik::Korisnik(const std::string& username, const std::string& password) : username(username), password(validPassword(password))
{
}

std::string Korisnik::GetUsername() const
{
	return username;
}

std::string Korisnik::GetPassword() const
{
	return password;
}

void Korisnik::ChangePassword(const std::string& oldPass, const std::string& newPass)
{
	if (oldPass != password)
		throw InvalidPasswordException("Current password does not match!");

	password = validPassword(newPass);
}

const std::string& Korisnik::validPassword(const std::string& password)
{
	if (password.length() < 8)
		throw InvalidPasswordException("Password too short, must be over 8 characters long");

	bool number = false, letter = false;
	for (int i = 0; i < password.length(); i++)
	{
		if (isalpha(password[i]))
			letter = true;
		else if (isdigit(password[i]))
			number = true;

		if (letter && number)
			break;
	}

	if (!number || !letter)
		throw InvalidPasswordException("Password must containt at least one letter and one number!");

	return password;
}

bool operator==(const Korisnik& k1, const Korisnik& k2)
{
	return k1.username == k2.username;
}

std::ostream& operator<<(std::ostream& os, const Korisnik& k)
{
	return os << k.username;
}