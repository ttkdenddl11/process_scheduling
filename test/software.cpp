#include "software.h"

Process::Process(string n, int at, int bt) {
	name = n;
	arrive_time = at;
	burst_time = bt;
	remaining_time = bt;
	end = false;
}

