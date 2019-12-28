#pragma once
#include "Multimedija.h"
#include <iostream>
#include <string>

class Slika : public Multimedija
{
public:
	Slika(const std::string& name, int width, int height, int pixelSize);

	virtual int Size() const override;
	virtual std::string Description() const override;

protected:

private:
	int width;
	int height;
	int pixelSize;
};
