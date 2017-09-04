#pragma once
/*********************************************************
Materia: Gráficas Computacionales
Fecha: 21 de agosto del 2017
Autor: A01376121 Luis Ricardo Gutiérrez
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