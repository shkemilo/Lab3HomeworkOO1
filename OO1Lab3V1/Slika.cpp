#include "Slika.h"
#include "Exceptions.h"

Slika::Slika(const std::string& name, int width, int height, int pixelSize) : Multimedija(name), width(width), height(height), pixelSize(pixelSize)
{
	if (width <= 0 || height <= 0)
		throw NegativeException("Width and height");
}

int Slika::Size() const
{
	return width * height * pixelSize;
}

std::string Slika::Description() const
{
	return "[" + std::to_string(width) + "x" + std::to_string(height) + "->" + std::to_string(Size()) + "B]";
}