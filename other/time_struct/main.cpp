#include <iostream>
#include <conio.h>
using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

void in_flow(time *watch1,const int flag=1)
{
	char ch='a', cArr[8]; 			int temp=8; // length of 00:00:00 - 8 symbols
	while((ch = getch())!=13 && temp)
	{
		if ((ch>='0' && ch<='9')|| ch == ':') 
		{
			temp--;
			cArr[temp]=ch;
			cout << ch;
		}
		else continue;
	} 
	
	watch1->hours = (cArr[7]-'0')*10+(cArr[6]-'0'); // обратный порядок потому что я темп начал с 8 а не с 0
	watch1->minutes = (cArr[4]-'0')*10+(cArr[3]-'0');
	watch1->seconds = (cArr[1]-'0')*10+(cArr[0]-'0');	
	
}

int main(int argc, char **argv)
{
	time watch1, watch2;
	cout << "Hi, what time shows your watch?\n Write time like this \"00:00:00\"" << endl;
	in_flow(&watch1);
	cout << endl << watch1.hours << ':' << watch1.minutes << ':' << watch1.seconds << endl;
	in_flow(&watch2);
	cout << endl << watch2.hours << ':' << watch2.minutes << ':' << watch2.seconds << endl;
	
	int sec1, sec2, res;
	sec1 = watch1.hours * 3600 + watch1.minutes * 60 + watch1.seconds;
	sec2 = watch2.hours * 3600 + watch2.minutes * 60 + watch2.seconds;
	res = sec1 + sec2;

	watch1.hours = res/3600;		watch1.minutes = (res - (watch1.hours*3600))/60;		
	watch1.seconds = res - watch1.hours*3600 - watch1.minutes*60;

	cout << "New time";
	cout << endl << watch1.hours << ':' << watch1.minutes << ':' << watch1.seconds << endl;
	return 0;
}


