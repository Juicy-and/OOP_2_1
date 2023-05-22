#include <iostream>
#include <fstream>
#include <string>

class Address
{
private:
	std::string city_;
	std::string street_;
	int numHouse_ = 0;
	int apartNum_ = 0;
public:
	Address(std::string city, std::string street, int numHouse, int apartNum) : city_(city),street_(street),numHouse_(numHouse),apartNum_(apartNum){}
	std::string get_output_address() 
	{
		return (city_ + ", " + street_ + ", " + std::to_string(numHouse_) + ", " + std::to_string(apartNum_) + "\n");
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	std::string s;
	std::string city;
	std::string street;
	int numHouse;
	int apartNum;
	std::ifstream file("in.txt");
	file >> s;
	const int a = stoi(s);
	Address** address = new Address*[a];
	for (int i = 0; i < a; i++)
	{
		file >> city;
		file >> street;
		file >> numHouse;
		file >> apartNum;
		address[i] = new Address(city, street, numHouse, apartNum);
	}
	file.close();
	std::ofstream file_out("out.txt");
	file_out << std::to_string(a) + "\n";
	for (int i = a - 1; i >= 0; i--)
	{
		file_out << address[i]->get_output_address();
	}
	file_out.close();
	delete[] address;
}