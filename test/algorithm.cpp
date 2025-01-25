#include "algorithm.h"

void processFCFS(vector<Core>& core_list, vector<Process>& process_list) {
	// 코어 한바퀴 돌며 시간 계산
	for (int i = 0; i < core_list.size(); i++) {
		if (core_list[i].alloc) {
			//p코어 일시 2의 양 처리
			if (core_list[i].core_type == 0)
				core_list[i].getProcess(process_list)->remaining_time -= 2;
			//e코어 일시 1의 양 처리
			if (core_list[i].core_type == 1)
				core_list[i].getProcess(process_list)->remaining_time -= 1;

			// 모든 일 다 처리했으면
			if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
				core_list[i].alloc = false;
				core_list[i].getProcess(process_list)->end = true;
				core_list[i].getProcess(process_list)->name = "";

			}
		}
	}
}

void processRR(vector<Core>& core_list, vector<Process>& process_list, int time_quntum, queue<Process>& temp_que) {
	// 코어 한바퀴 돌며 시간 계산
	for (int i = 0; i < core_list.size(); i++) {
		if (core_list[i].alloc) {
			//p코어 일시 2의 양 처리
			if (core_list[i].core_type == 0)
				core_list[i].getProcess(process_list)->remaining_time -= 2;
			//e코어 일시 1의 양 처리
			if (core_list[i].core_type == 1)
				core_list[i].getProcess(process_list)->remaining_time -= 1;
			//선점 코어의 시간 빼기
			core_list[i].time_quntum--;
			// 모든 일 다 처리했으면
			if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
				core_list[i].alloc = false;
				core_list[i].getProcess(process_list)->end = true;
				// 일이 끝나면 그 자리 선점시간 초기화
				core_list[i].time_quntum = time_quntum;
				//core_list[i].getProcess(process_list)->name = "";

			}
			// 선점
			else if (core_list[i].time_quntum <= 0) {
				core_list[i].time_quntum = time_quntum;
				core_list[i].alloc = false;
				Process temp_process = *core_list[i].getProcess(process_list);
				temp_que.push(temp_process);
			}
		}
	}
}