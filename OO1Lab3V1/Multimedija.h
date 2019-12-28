#pragma once
#include <iostream>
#include <string>

class Multimedija
{
public:
	Multimedija(const std::string& name);

	virtual int Size() const = 0;
	virtual std::string Description() const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Multimedija& mm);

	virtual ~Multimedija() { }

protected:
	virtual std::ostream& output(std::ostream& os) const;

private:
	std::string name;
};
