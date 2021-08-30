#include "main.h"

inline void menu()
{
	std::cout << "\'a\' - �������� ���������\n"
			<< "\'s\' - �������� ������ ����������\n"
			<< "\'w\' - �������� ���������� � ����\n"
			<< "\'r\' - ��������� �� �����\n"
			<< "\'f\' - ����� ��������� �� ����������� ������\n"
			<< "\'d\' - ������� ����\n"
			<< "\'smth else\' - ����� �� ���������" << std::endl;
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
			std::cout << "������� ����� ���������" << std::endl;
			//number = 23;
			std::cin >> number;
			employee::read(number);	break;
		case 'd':
			remove("empl_io.txt");	break;
		default:
			std::cout << "����" << std::endl;
			exit(0);
		}
	}
	return 0;
}
