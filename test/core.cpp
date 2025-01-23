#include "core.h"

Core::Core(int c, int t, bool a, string n) {
	core_type = c;
	time_quntum = t;
	alloc = a;
	process_name = "";
}

Process* Core::getProcess(vector<Process>& process_list) {
	for (int i = 0; i < process_list.size(); i++) {
		if (process_name == process_list[i].name)
			return &process_list[i];
	}
}