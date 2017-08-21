/*********************************************************
Materia: Gráficas Computacionales
Fecha: 21 de agosto del 2017
Autor: A01376121 Luis Ricardo Gutiérrez
*********************************************************/
#include "InputFile.h"
#include <string>
#include <iostream>
#include <fstream>

bool InputFile::Read(std::string fName) {
	_contents = "";
	std::ifstream f;
	f.open(fName);
	if (f){
		std::string str;
		while (std::getline(f, str)){
			_contents = _contents + str + "\n";
		}
		return true;
	}
	return false;
}

std::string InputFile::GetContents() {
	return _contents;
}