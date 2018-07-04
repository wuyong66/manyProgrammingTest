#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define REST_START 45000    //60*60*12 + 30*60 ， 12：30--2：00
#define REST_END 50400      //60*60*14 ,    14：00
#define START 10800         //60*60*3 ，
#define END 86400           //60*60*24，
#define REST 5400           //REST_END - REST_START

void main()
{
/*	int N;      //一共有n条打卡纪录
	vector<int > dayRecord[32];
	int workTime[32];
	cin >> N;
	if (getchar() == '\n');     //把键盘缓冲区的回车数据读走
	for (int i = 0; i < N; ++i)
	{
		int day = 0, hour = 0, min = 0, sec = 0;
		string line;
		getline(cin, line);
		sscanf(line.c_str(), "08.%d %d:%d:%d", &day, &hour, &min, &sec);
		int time = hour * 60 * 60 + min * 60 + sec;
		if (time < START);
	}

	*/
	int a = 0xf0;
	int b = 0xf1;
	int c = 1 << ((a & b) ^ (a | b));
	cout << c << endl;
	system("pause");

}

