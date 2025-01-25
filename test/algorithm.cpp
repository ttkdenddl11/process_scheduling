#include "algorithm.h"

void processFCFS(vector<Core>& core_list, vector<Process>& process_list) {
	// �ھ� �ѹ��� ���� �ð� ���
	for (int i = 0; i < core_list.size(); i++) {
		if (core_list[i].alloc) {
			//p�ھ� �Ͻ� 2�� �� ó��
			if (core_list[i].core_type == 0)
				core_list[i].getProcess(process_list)->remaining_time -= 2;
			//e�ھ� �Ͻ� 1�� �� ó��
			if (core_list[i].core_type == 1)
				core_list[i].getProcess(process_list)->remaining_time -= 1;

			// ��� �� �� ó��������
			if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
				core_list[i].alloc = false;
				core_list[i].getProcess(process_list)->end = true;
				core_list[i].getProcess(process_list)->name = "";

			}
		}
	}
}

void processRR(vector<Core>& core_list, vector<Process>& process_list, int time_quntum, queue<Process>& temp_que) {
	// �ھ� �ѹ��� ���� �ð� ���
	for (int i = 0; i < core_list.size(); i++) {
		if (core_list[i].alloc) {
			//p�ھ� �Ͻ� 2�� �� ó��
			if (core_list[i].core_type == 0)
				core_list[i].getProcess(process_list)->remaining_time -= 2;
			//e�ھ� �Ͻ� 1�� �� ó��
			if (core_list[i].core_type == 1)
				core_list[i].getProcess(process_list)->remaining_time -= 1;
			//���� �ھ��� �ð� ����
			core_list[i].time_quntum--;
			// ��� �� �� ó��������
			if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
				core_list[i].alloc = false;
				core_list[i].getProcess(process_list)->end = true;
				// ���� ������ �� �ڸ� �����ð� �ʱ�ȭ
				core_list[i].time_quntum = time_quntum;
				//core_list[i].getProcess(process_list)->name = "";

			}
			// ����
			else if (core_list[i].time_quntum <= 0) {
				core_list[i].time_quntum = time_quntum;
				core_list[i].alloc = false;
				Process temp_process = *core_list[i].getProcess(process_list);
				temp_que.push(temp_process);
			}
		}
	}
}