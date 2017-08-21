#pragma once
#include <string>
class Employee{
	public:
		Employee(int id, std::string firstName, std::string lastName, int salary);
		int GetID();
		std::string GetFirstname();
		std::string GetLastname();
		std::string GetName();
		int GetSalary();
		void setSalary(int salary);
		int GetAnnualSalary();
		int RaiseSalary(int percent);
		std::string Print();
	private:	
		int _id;
		std::string _firstName;
		std::string _lastName;
		int _salary;

};