#pragma once
#include <iostream>
#include <exception>
#include <string>

class Korisnik
{
public:
	Korisnik(const std::string& username, const std::string& password);

	std::string GetUsername() const;
	std::string GetPassword() const;

	void ChangePassword(const std::string& oldPass, const std::string& newPass);

	friend bool operator==(const Korisnik& k1, const Korisnik& k2);

	friend std::ostream& operator<<(std::ostream& os, const Korisnik& k);

private:
	static const std::string& validPassword(const std::string& password);

	std::string username;
	std::string password;
};
