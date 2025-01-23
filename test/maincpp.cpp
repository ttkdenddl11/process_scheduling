#include<bits/stdc++.h>
#include "software.h"
#include "core.h"
#include "algorithm.h"

using namespace std;

int main() {
	vector<Process> process_list;
	vector<Core> core_list;
	queue<Process> que;
	queue<Process> ready_que;

	// gui�� ���� �Է¹���
	int time_quntum = 2;

	process_list.push_back({ "p1", 5, 6 });
	process_list.push_back({ "p2", 0, 7 });
	process_list.push_back({ "p3", 3, 2 });
	process_list.push_back({ "p4", 4, 9 });
	process_list.push_back({ "p5", 2, 8 });
	process_list.push_back({ "p6", 2, 7 });
	process_list.push_back({ "p7", 11, 5 });
	process_list.push_back({ "p8", 12, 3 });
	process_list.push_back({ "p9", 10, 7 });
	core_list.push_back({1, time_quntum, false, ""});	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�
	core_list.push_back({0, time_quntum, false, "" });	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�
	core_list.push_back({ 1, time_quntum, false, "" });	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�
	core_list.push_back({ 0, time_quntum, false, "" });	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�


	sort(process_list.begin(), process_list.end(), [](const Process& a, const Process& b) {
		return a.arrive_time < b.arrive_time; // �������� ����
		});

	for (int i = 0; i < process_list.size(); i++) {
		que.push(process_list[i]);
	}

	int time = 0;

	while (true) {

		bool end = true;

		// ť���� �����ð��� time�� �������� ready_Que�� ����
		while (!que.empty() && que.front().arrive_time <= time) {
			ready_que.push(que.front());
			que.pop();
		}
		// �ھ� �ѹ��� ���� ���μ��� �Ҵ� �޾Ҵ��� Ȯ��
		for (int i = 0; i < core_list.size(); i++) {
			if (!ready_que.empty() && !core_list[i].alloc) {
				core_list[i].alloc = true;
				core_list[i].process_name = ready_que.front().name;
				ready_que.pop();
			}
		}
		//gui ȭ�鿡 ����� �κ�
		cout << time << "��" << '\n';
		for (int i = 0; i < core_list.size(); i++) {
			if (core_list[i].core_type == 0)
				cout << "p�ھ� : ";
			else if (core_list[i].core_type == 1)
				cout << "e�ھ� : ";
			if (!core_list[i].alloc)
				cout << "�Ҵ�x" << '\n';
			else {
				cout << core_list[i].process_name << '\n';
			}
		}
		cout << '\n';

		// fcfs �˰���
		//processFCFS(core_list, process_list);
		
		//����κ� �˰���
		processRR(core_list, process_list, time_quntum, ready_que);

		// ���μ��� �ѹ��� ���鼭 ������ ��
		for (int i = 0; i < process_list.size(); i++) {
			if (!process_list[i].end) {
				end = false;
			}
		}
		// �ð� ����
		time++;
		if (end)
			break;
	}

	return 0;
}