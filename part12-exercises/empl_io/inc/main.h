#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>


#ifndef INC_MAIN_H_
#define INC_MAIN_H_ 1

namespace empl
{
const int LEN = 32;  // Длина имени
const int MAXEM = 100; // Макс число работников

enum empl_type { tmanager, tscientist, tlaborer };

class employee
{
private:
	char name[LEN];			// Фамилия имя работника
	unsigned int number;	// Его рабочий номер
	static int n;			// Кол-во всех рабочих
	static employee* arr[]; // Массив указателей на класс работников
public:
	virtual void getData();
	virtual void showData();
	virtual empl_type getType();  // Получить тип работника

	static void add(); // Добавить работника
	static void showAll(); // Вывести данные обо всех работниках
	static void read(unsigned int number = 0); // Прочитать из файла инфу о работниках
	static void write(); // Записать в файл инфу о работниках

	virtual ~employee() { }
};



class manager : public employee
{
private:
	double taxes;  // Налоги в организацю
public:
	void getData();
	void showData();
};

class scientist : public employee
{
private:
	int publications;  // Кол-во публикаций
public:
	void getData();
	void showData();
};

class laborer : public employee
{
};

} // end of empl


#endif /* INC_MAIN_H_ */
