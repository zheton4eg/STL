#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <map>
#include <list>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define delimiter "\n------------------------------------------------------------------------------------\n"

const std::map<int, std::string> VIOLATION =
{
	{1,"Ремень безопасности"},
	{2,"Парковка в неположеном месте"},
	{3,"Пересечение сплошной"},
	{4,"Превышение скорости"},
	{5,"Отсутсвие права управления ТС"},
	{6,"Отсутсвие страховки"},
	{7,"Проезд на красный"},
	{8,"Выезд на встречную полосу"},
	{9,"Дрифт на перекрестке"},
	{10,"Езда в нетрезвом состояниии"},
	{11,"Оскорбление офицера"},
	{12,"Изменение конструкции ТС "},
	{13,"Перевозка негабаритного груза"},
	{14,"Превышение максимальной нагрузки на ось"},
	{15,"Перевозка ребенка без кресла"},
};
class Crime
{
	//std::string license_plate; //Номерной знак
	int violation;            //Нарушение
	std::string place;       //Место    
	int id;
	tm time;//Время
public:
	/*const std::string& get_license_plate()const
	{
		return license_plate;
	}*/
	 int get_violation_id()const
	{
		return id;
	}

	const std::string& get_violation()const
	{
		return VIOLATION.at(id);
	}
	const std::string get_place()const
	{
		return place;
	}
	const std::string get_time()const
	{
		/*std::string result = asctime(&time);
		result.pop_back();
		return result;*/
		const int SIZE= 256;
		char formatted[SIZE]{};
		strftime(formatted, SIZE, "%R %e.%m.%Y", &time);
		return formatted;
	}
	const time_t get_timestamp()const
	{
		tm copy = time;
		return mktime(&copy);
	}
	/*void set_license_plate(const std::string& license_plate)
	{
		this->license_plate = license_plate;
	}*/
	void set_violation_id(int id)
	{
		this->id = id;
	}
	void set_place(const std::string& place)
	{
		this->place = place;
	}
	void set_time(const std::string& time)
	{
		char* time_buffer = new char[time.size() + 1] {};
		strcpy(time_buffer, time.c_str());
		int time_elements[5]{};
		int i = 0;
		char delimiters[] = ":./ ";
		for (char* pch = strtok(time_buffer, delimiters); pch; pch = strtok(NULL, delimiters))
			time_elements[i++] = std::atoi(pch);
		delete[]time_buffer;
		this->time.tm_hour = time_elements[0];
		this->time.tm_min = time_elements[1];
		this->time.tm_mday = time_elements[2];
		this->time.tm_mon = time_elements[3];
		this->time.tm_year = time_elements[4]-1900;

		//this->time = 
	//Constructors:time;
	}
	Crime(int violation_id, const std::string& place, const std::string& time)
	{
		//set_license_plate(license_plate);
		this->time={};
		set_violation_id(violation_id);
		set_place(place);
		set_time(time);
#ifdef DEBUG
		cout << "Constructor: \t" << this << endl;
#endif // DEBUG
	}
	~Crime()
	{
#ifdef DEBUG
		cout << "Destructor: \t" << this << endl;
#endif // DEBUG
	}
};
std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << obj.get_time()<<":\t " << obj.get_place() << " - " << obj.get_violation() << " " << endl;
}

std::ofstream& operator<<(std::ofstream& os, const Crime& obj)
{
	 os << obj.get_violation_id() << " " << obj.get_timestamp() << " " << obj.get_place();
	 return os;
}
	
void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);

void main()
{
	setlocale(LC_ALL, "");

	/*Crime crime(1, "Ул.Ленина", "18:10 1.09.2024");
	cout << crime << endl;*/

	std::map<std::string, std::list<Crime>>base =
	{
		{"а777бб",{Crime(1, "Ул.Ленина", "18:10 1.09.2024"), Crime(2,"пл. Свободы","12:25 20.08.2024")}},
		{"а000бб",{Crime(6, "Ул.Космоновтов", "17:50 1.08.2024"), Crime(8,"пл. Космонавтов","17:45 01.08.2024")}},
		{"а001аа",{Crime(10, "Ул.Пролетарская", "21:50 1.08.2024"), Crime(9,"пл. Пролетарская","21:50 01.08.2024"),Crime(11,"пл. Пролетарская","21:50 01.08.2024"),Crime(12,"пл. Пролетарская","22:05 01.08.2024")}},
	};
	print(base);
	save(base, "base.txt");
	

}
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator map_it = base.begin(); map_it != base.end(); ++map_it)
	{
		cout << delimiter << endl;
		cout << map_it->first << ":\n";
		for (std::list<Crime>::const_iterator it = map_it->second.begin(); it != map_it->second.end(); ++it)
		{
			cout << "\t" << *it << endl;
		}
	
	}
}
void save(const std::map<std::string, std::list<Crime>>& base, const std:: string& filename)
{
	std::ofstream fout(filename);
	

	for (std::map<std::string, std::list<Crime>>::const_iterator map_it = base.begin(); map_it != base.end(); ++map_it)
	{
		

		fout << map_it->first << ":\t";
		for (std::list<Crime>::const_iterator it = map_it->second.begin(); it != map_it->second.end(); ++it)
		{
			
			fout << *it << ",";
		}
		fout.seekp(-1, std::ios::cur);
		fout <<";\n";
		
	}
	fout.close();
	std::string command =  filename;
	system(command.c_str());
}