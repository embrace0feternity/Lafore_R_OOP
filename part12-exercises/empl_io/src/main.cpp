#include "main.h"

inline void menu()
{
	std::cout << "\'a\' - Добавить работника\n"
			<< "\'s\' - Показать список работников\n"
			<< "\'w\' - Записать работников в файл\n"
			<< "\'r\' - Прочитать из файла\n"
			<< "\'f\' - Поиск работника по уникальному номеру\n"
			<< "\'d\' - Удалить файл\n"
			<< "\'smth else\' - Выход из программы" << std::endl;
}

int main(int argc, char **argv)
{
	using namespace empl;
	char ch = '1';
	while(ch != 'e')
	{
		menu();
		//ch = 'f';
		std::cin >> ch;
		switch (ch)
		{
		case 'a':
			employee::add();		break;
		case 's':
			employee::showAll();	break;
		case 'w':
			employee::write();		break;
		case 'r':
			employee::read();		break;
		case 'f':
			int number;
			std::cout << "Введите номер работника" << std::endl;
			//number = 23;
			std::cin >> number;
			employee::read(number);	break;
		case 'd':
			remove("empl_io.txt");	break;
		default:
			std::cout << "Пока" << std::endl;
			exit(0);
		}
	}
	return 0;
}
