#pragma once
/*********************************************************
Materia: Gr�ficas Computacionales
Fecha: 21 de agosto del 2017
Autor: A01376121 Luis Ricardo Guti�rrez
*********************************************************/

#pragma once
#include <string>

class InputFile
{
public:
	bool Read(std::string);
	std::string GetContents();
private:
	std::string _contents;
};