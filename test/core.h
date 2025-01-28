#pragma once

#include "software.h"

class Core {
public:
	int core_type = 0;
	int time_quntum = 0;
	bool alloc = false;
	string process_name = "";
public:
	Core(int c, int t, bool a, string n);

	Process* getProcess(vector<Process>& process_list);

	void coreAlloc(queue<Process>& ready_que);

	void progressProcess(vector<Process>& process_list);

	void coreReturn(vector<Process>& process_list);
};