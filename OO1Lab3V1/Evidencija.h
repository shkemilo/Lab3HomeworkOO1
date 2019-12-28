#pragma once
#include "Lista.h"
#include "Korisnik.h"
#include <string>

class Evidencija
{
public:
	Evidencija() = default;
	Evidencija(const Evidencija&) = delete;
	Evidencija(Evidencija&&) = delete;

	Evidencija& operator=(const Evidencija&) = delete;
	Evidencija& operator= (Evidencija&&) = delete;

	Evidencija& operator+=(Korisnik& user);

	Korisnik& operator[](const std::string& username);
	const Korisnik& operator[](const std::string& username) const;

	Evidencija& operator()(const std::string& username);

	void ChangePassword(const std::string& username, const std::string& oldPass, const std::string& newPass);

	~Evidencija() = default;

private:
	int findKorisnik(const Korisnik& user) const;
	int findKorisnik(const std::string& username) const;

	Lista<Korisnik&> users;
};
