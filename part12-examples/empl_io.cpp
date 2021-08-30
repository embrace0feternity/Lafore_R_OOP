#include <iostream>
#include <fstream>
#include <typeinfo>

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
	static void read(); // Прочитать из файла инфу о работниках
	static void write(); // Записать в файл инфу о работниках

	virtual ~employee() { }
};
int employee::n = 0;
employee* employee::arr[MAXEM];



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

namespace empl
{
void employee::getData()
{
	std::cin.ignore(1,'\n');
	std::cout << "Введите имя работника: "; std::cin.getline(name, LEN);
	std::cout << "Введите номер работника: "; std::cin >> number;
	std::cin.ignore(1,'\n');
}

void employee::showData()
{
	std::cout << "Имя работника: " << name << std::endl;
	std::cout << "Номер работника: " << number << std::endl;
}

empl_type employee::getType()
{
	if (typeid(*this) == typeid(manager)) return tmanager;
	else
	if (typeid(*this) == typeid(scientist)) return tscientist;
	else
	if (typeid(*this) == typeid(laborer)) return tlaborer;
	else
		std::cerr << "Неправильный тип работника" << std::endl;
	return tmanager;
}

void employee::add()
{
	char c;
	std::cout << "\'m\' - для добавления менеджера\n"
			<< "\'s\' - для добавления ученого\n"
			<< "\'l\' - для добавления рабочего" << std::endl;
	std::cin >> c;
	switch(c)
	{
	case 'm':
		arr[n] = new manager;
		break;
	case 's':
		arr[n] = new scientist;
		break;
	case 'l':
		arr[n] = new laborer;
		break;
	default:
		std::cerr << "Ошибка создания" << std::endl;
		break;
	}
	arr[n++]->getData();
}

void employee::showAll()
{
	for (int i=0; i<n; i++)
	{
		std::cout << '\n' << i+1 << ".\n";
		empl_type c = arr[i]->getType();

		switch (c)
		{
		case 0:
			std::cout << "Тип: менеджер" << std::endl;		break;
		case 1:
			std::cout << "Тип: учёный" << std::endl;		break;
		case 2:
			std::cout << "Тип: рабочий" << std::endl;		break;
		default:
			std::cout << "Неизвестный тип" << std::endl;	break;
		}
		arr[i]->showData();
	}
}

void manager::getData()
{
	employee::getData();
	std::cout << "Введите сумму, которую работник заплатил организации: ";	std::cin >> taxes;
}
void manager::showData()
{
	employee::showData();
	std::cout << "Сумма, которую работник заплатил организации: " << taxes << std::endl;
}

void scientist::getData()
{
	employee::getData();
	std::cout << "Введите кол-во публикаций: ";	std::cin >> publications;
}
void scientist::showData()
{
	employee::showData();
	std::cout << "Введите кол-во публикаций: " << publications << std::endl;
}
} // end of empl

int main(int argc, char **argv)
{
	empl::employee::add();
	empl::employee::add();
	empl::employee::showAll();
	return 0;
}

