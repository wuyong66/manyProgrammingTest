//目前改题还是有些问题，稍后解决
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define REST_START 45000    //60*60*12 + 30*60 ， 12：30--2：00
#define REST_END 50400      //60*60*14 ,    14：00
#define START 10800         //60*60*3 ，
#define END 86400           //60*60*24，
#define REST 5400           //REST_END - REST_START

int main()
{
	int N;                //一共有n条打卡纪录
	vector<int > dayRecord[32];
	int workTime[32];
	cin >> N;            //不会舍弃回车符
	char c = getchar();
	for (int i = 0; i < N; ++i)
	{
		int day = 0, hour = 0, min = 0, sec = 0;
		string line;
		getline(cin, line);
		sscanf_s(line.c_str(), "08.%d %d:%d:%d", &day, &hour, &min, &sec);
		int time = hour * 60 * 60 + min * 60 + sec;
		if (time < START)
		{
			dayRecord[day - 1].push_back(time);
		}
		else
		{
			dayRecord[day].push_back(time);
		}
	}
	for (int i = 1; i < 32; ++i)         //
	{
		sort(dayRecord[i].begin(), dayRecord[i].end());
		for (unsigned int j = 2; j <= dayRecord[i].size(); j = j + 2)
		{
			if (dayRecord[i][j] > REST_START && dayRecord[i][j] < REST_END)
			{
				workTime[i] += (REST_START - dayRecord[i][j - 1]);
			}
			else if (dayRecord[i][j - 1] > REST_START && dayRecord[i][j - 1] < REST_END)
			{
				workTime[i] += (dayRecord[i][j] - REST_END);
			}
			else
			{
				workTime[i] += (dayRecord[i][j] - dayRecord[i][j - 1]);
			}
		}

	}
	for (int i = 1; i < 32; ++i)
	{
		printf("day%d : %d s\n", i, workTime[i]);
	}
	system("pause");
	return 0;
}

