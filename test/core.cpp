#include "core.h"

// 생성자
Core::Core(int c, int t, bool a, string n) {
	core_type = c;
	time_quntum = t;
	alloc = a;
	process_name = "";
}

// 프로세스 이름 같은거 가져오기
Process* Core::getProcess(vector<Process>& process_list) {
	for (int i = 0; i < process_list.size(); i++) {
		if (process_name == process_list[i].name)
			return &process_list[i];
	}
}

void Core::coreAlloc(queue<Process>& ready_que) {
	if (!ready_que.empty() && !alloc) {
		alloc = true;
		process_name = ready_que.front().name;
		ready_que.pop();
	}
}

void Core::progressProcess(vector<Process>& process_list) {
	// p코어 일시 2의 양 처리
	if (core_type == 0)
		getProcess(process_list)->remaining_time -= 2;
	//e코어 일시 1의 양 처리
	if (core_type == 1)
		getProcess(process_list)->remaining_time -= 1;
}

void Core::coreReturn(vector<Process>& process_list) {
	alloc = false;
	getProcess(process_list)->end = true;
}