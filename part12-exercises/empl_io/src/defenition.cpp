#include "main.h"

namespace empl
{

int employee::n = 0;
employee* employee::arr[MAXEM];

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

void employee::write()
{
	std::ofstream outfile("empl_io.txt", std::ios::binary | std::ios::app);
	if (!outfile.is_open())
	{
		std::cerr << "Проблема с созданием/открытием файла" << std::endl;
		exit(1);
	}
	for (int i=0; i<n; i++)
	{
		int type;
		empl_type temp = arr[i]->getType();
		outfile.write(reinterpret_cast<char*>(&temp),sizeof(temp)); // записал тип работника
		switch (temp)
		{
		case 0:
			type = sizeof(manager);
			break;
		case 1:
			type = sizeof(scientist);
			break;
		case 2:
			type = sizeof(laborer);
			break;
		}

		outfile.write(reinterpret_cast<char*>(arr[i]), type); // записал данные о работнике
	}
	outfile.close();
	std::cout << "Информация записана в файл" << std::endl;
}

void employee::read(unsigned int number)
{
	std::ifstream infile("empl_io.txt", std::ios::binary);
	if (!infile.is_open())
		std::cerr << "Проблема с созданием/открытием файла" << std::endl;

	empl_type temp;	int type;
	n = 0;
	while(true)
	{
		infile.read(reinterpret_cast<char*>(&temp),sizeof(temp));
		if (infile.eof()) break;
		switch (temp)
		{
		case 0:
			arr[n] = new manager;
			type = sizeof(manager);
			break;
		case 1:
			arr[n] = new scientist;
			type = sizeof(scientist);
			break;
		case 2:
			arr[n] = new laborer;
			type = sizeof(laborer);
			break;
		}

		infile.read(reinterpret_cast<char*>(arr[n]), type);
		if (number != 0)
		{
			unsigned int arrNumber = arr[n]->number;
			if (number == arrNumber)
			{
				if (temp == 0)
					std::cout << "Тип: менеджер" << std::endl;
				else if (temp == 1)
					std::cout << "Тип: учёный" << std::endl;
				else
					std::cout << "Тип: рабочий" << std::endl;
				arr[n]->showData();
				break;
			}

		}
		n++;
	}
	infile.close();
	if (number == 0)
	{
		std::cout << "Информация прочитана. ";
		std::cout << "Итого - " << n << " работников" << std::endl;
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





