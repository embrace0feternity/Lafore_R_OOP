#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string>


#ifndef INC_MAIN_H_
#define INC_MAIN_H_ 1

namespace empl
{
const int LEN = 32;  // ����� �����
const int MAXEM = 100; // ���� ����� ����������

enum empl_type { tmanager, tscientist, tlaborer };

class employee
{
private:
	char name[LEN];			// ������� ��� ���������
	unsigned int number;	// ��� ������� �����
	static int n;			// ���-�� ���� �������
	static employee* arr[]; // ������ ���������� �� ����� ����������
public:
	virtual void getData();
	virtual void showData();
	virtual empl_type getType();  // �������� ��� ���������

	static void add(); // �������� ���������
	static void showAll(); // ������� ������ ��� ���� ����������
	static void read(unsigned int number = 0); // ��������� �� ����� ���� � ����������
	static void write(); // �������� � ���� ���� � ����������

	virtual ~employee() { }
};



class manager : public employee
{
private:
	double taxes;  // ������ � ����������
public:
	void getData();
	void showData();
};

class scientist : public employee
{
private:
	int publications;  // ���-�� ����������
public:
	void getData();
	void showData();
};

class laborer : public employee
{
};

} // end of empl


#endif /* INC_MAIN_H_ */
