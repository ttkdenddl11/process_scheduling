#pragma once

#include<string>
#include<vector>
#include<queue>

using namespace std;

class Process {
public:
	string name = "";
	int arrive_time = 0;
	int burst_time = 0;
	int remaining_time = 0;
	bool end = false;

public:

	Process(string n, int at, int bt);

};
