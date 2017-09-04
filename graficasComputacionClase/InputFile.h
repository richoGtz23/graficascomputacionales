#pragma once
/*********************************************************
Materia: Gr�ficas Computacionales
Fecha: 21 de agosto del 2017
Autor: A01376121 Luis Ricardo Guti�rrez
*********************************************************/

#include <string>

class InputFile
{
public:
	bool Read(const std::string& filename);
	const std::string GetContents() const;

private:
	std::string _contents;
};