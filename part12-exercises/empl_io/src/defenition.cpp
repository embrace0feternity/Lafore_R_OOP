#include "main.h"

namespace empl
{

int employee::n = 0;
employee* employee::arr[MAXEM];

void employee::getData()
{
	std::cin.ignore(1,'\n');
	std::cout << "������� ��� ���������: "; std::cin.getline(name, LEN);
	std::cout << "������� ����� ���������: "; std::cin >> number;
	std::cin.ignore(1,'\n');
}

void employee::showData()
{
	std::cout << "��� ���������: " << name << std::endl;
	std::cout << "����� ���������: " << number << std::endl;
}

empl_type employee::getType()
{
	if (typeid(*this) == typeid(manager)) return tmanager;
	else
	if (typeid(*this) == typeid(scientist)) return tscientist;
	else
	if (typeid(*this) == typeid(laborer)) return tlaborer;
	else
		std::cerr << "������������ ��� ���������" << std::endl;
	return tmanager;
}

void employee::add()
{
	char c;
	std::cout << "\'m\' - ��� ���������� ���������\n"
			<< "\'s\' - ��� ���������� �������\n"
			<< "\'l\' - ��� ���������� ��������" << std::endl;
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
		std::cerr << "������ ��������" << std::endl;
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
			std::cout << "���: ��������" << std::endl;		break;
		case 1:
			std::cout << "���: ������" << std::endl;		break;
		case 2:
			std::cout << "���: �������" << std::endl;		break;
		default:
			std::cout << "����������� ���" << std::endl;	break;
		}
		arr[i]->showData();
	}
}

void employee::write()
{
	std::ofstream outfile("empl_io.txt", std::ios::binary | std::ios::app);
	if (!outfile.is_open())
	{
		std::cerr << "�������� � ���������/��������� �����" << std::endl;
		exit(1);
	}
	for (int i=0; i<n; i++)
	{
		int type;
		empl_type temp = arr[i]->getType();
		outfile.write(reinterpret_cast<char*>(&temp),sizeof(temp)); // ������� ��� ���������
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

		outfile.write(reinterpret_cast<char*>(arr[i]), type); // ������� ������ � ���������
	}
	outfile.close();
	std::cout << "���������� �������� � ����" << std::endl;
}

void employee::read(unsigned int number)
{
	std::ifstream infile("empl_io.txt", std::ios::binary);
	if (!infile.is_open())
		std::cerr << "�������� � ���������/��������� �����" << std::endl;

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
					std::cout << "���: ��������" << std::endl;
				else if (temp == 1)
					std::cout << "���: ������" << std::endl;
				else
					std::cout << "���: �������" << std::endl;
				arr[n]->showData();
				break;
			}

		}
		n++;
	}
	infile.close();
	if (number == 0)
	{
		std::cout << "���������� ���������. ";
		std::cout << "����� - " << n << " ����������" << std::endl;
	}
}

void manager::getData()
{
	employee::getData();
	std::cout << "������� �����, ������� �������� �������� �����������: ";	std::cin >> taxes;
}
void manager::showData()
{
	employee::showData();
	std::cout << "�����, ������� �������� �������� �����������: " << taxes << std::endl;
}

void scientist::getData()
{
	employee::getData();
	std::cout << "������� ���-�� ����������: ";	std::cin >> publications;
}
void scientist::showData()
{
	employee::showData();
	std::cout << "������� ���-�� ����������: " << publications << std::endl;
}
} // end of empl





