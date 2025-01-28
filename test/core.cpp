#include "core.h"

// ������
Core::Core(int c, int t, bool a, string n) {
	core_type = c;
	time_quntum = t;
	alloc = a;
	process_name = "";
}

// ���μ��� �̸� ������ ��������
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
	// p�ھ� �Ͻ� 2�� �� ó��
	if (core_type == 0)
		getProcess(process_list)->remaining_time -= 2;
	//e�ھ� �Ͻ� 1�� �� ó��
	if (core_type == 1)
		getProcess(process_list)->remaining_time -= 1;
}

void Core::coreReturn(vector<Process>& process_list) {
	alloc = false;
	getProcess(process_list)->end = true;
}