#pragma once

//#include <iostream>
//#include <string>
#include "Person.h"

class Student : public Person
{
private:
	//std::string m_name;
	int m_intel; // intelligence

public:
	Student(const std::string& name_in = "No Name", const int& intel_in = 0)
		//: m_name(name_in), m_intel(intel_i)
		: Person(name_in), m_intel(intel_in)
	{}

	void setIntel(const int& intel_in)
	{
		m_intel = intel_in;
	}

	int getIntel() const
	{
		return m_intel;
	}

	void study()
	{
		std::cout << getName() << " is studying " << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Student& student)
	{
		out << student.getName() << " " << student.getIntel(); 
		return out;
	}
};