#include "algorithm.h"

Scheduler::Scheduler(vector<Process> process_list, vector<Core> core_list) {
	this->process_list = process_list;
	this->core_list = core_list;
}

void Scheduler::sort_push() {
	sort(process_list.begin(), process_list.end(), [](const Process& a, const Process& b) {
		return a.arrive_time < b.arrive_time; // �������� ����
		});

	for (int i = 0; i < process_list.size(); i++) {	// ���� �� ť�� ��� (ready_que ���� ť)
		que.push(process_list[i]);
	}
}

void Scheduler::readyQueSet() {
	// ť���� �����ð��� time�� �������� ready_Que�� ����
	while (!que.empty() && que.front().arrive_time <= time) {
		ready_que.push(que.front());
		que.pop();
	}

	// ��������� �ӽ� ť
	while (!temp_que.empty()) {
		ready_que.push(temp_que.front());
		temp_que.pop();
	}
}

bool Scheduler::completeScheduling() {
	bool end = true;
	// ���μ��� �ѹ��� ���鼭 ������ ��
	for (int i = 0; i < process_list.size(); i++) {
		if (!process_list[i].end) {
			end = false;
		}
	}
	return end;
}

void Scheduler::processFCFS() {
	// gui�� ���� �Է¹���
	/*if (xml.readXml(process_list, core_list, "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/processes.xml") == 1)
		return;*/

	// cli�� �Է¹޴� ����
	//process_list.push_back({ "p1", 5, 6 });
	//process_list.push_back({ "p2", 0, 7 });
	//process_list.push_back({ "p3", 3, 2 });
	//process_list.push_back({ "p4", 4, 9 });
	//process_list.push_back({ "p5", 2, 8 });
	//process_list.push_back({ "p6", 2, 7 });
	//process_list.push_back({ "p7", 11, 5 });
	//process_list.push_back({ "p8", 12, 3 });
	//process_list.push_back({ "p9", 10, 7 });
	//core_list.push_back({1, time_quntum, false, ""});	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�
	//core_list.push_back({0, time_quntum, false, "" });	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�
	//core_list.push_back({ 1, time_quntum, false, "" });	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�
	//core_list.push_back({ 0, time_quntum, false, "" });	// 0�Ͻ� P�ھ�,, 1�Ͻ� E�ھ�

	
	sort_push();	// ���� �� ť�� ����

	while (true) {

		readyQueSet();	// ready_que ���� (fcfs, RR ����-> �켱����ť�� �ƴ϶�)

		
		// �ھ� �ѹ��� ���� ���μ��� �Ҵ� �޾Ҵ��� Ȯ�� �� ready_que�� �ִ°� �Ҵ� (�ھ� �Ҵ�)
		for (int i = 0; i < core_list.size(); i++) {
			core_list[i].coreAlloc(ready_que);
		}
		//gui ȭ�鿡 ����� �κ� -> ������ xml�� �ʸ��� ����
		/*cout << time << "��" << '\n';
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
		cout << '\n';*/

		xml.SaveToXml(time, core_list);
		string outFilePath = "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/output.xml";
		xml.doc_Core.save_file(outFilePath.c_str());

		// �ھ� �ѹ��� ���� �ð� ���
		for (int i = 0; i < core_list.size(); i++) {
			if (core_list[i].alloc) {
				
				// �� �ھ�� �� ó�� ����
				core_list[i].progressProcess(process_list);

				// ��� �� �� ó��������
				if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
					core_list[i].coreReturn(process_list);
					//core_list[i].getProcess(process_list)->name = "";

				}
			}
		}

		// ��� ���μ��� �Ϸ������� ����
		if (completeScheduling())
			break;

		// �ð� ����
		time++;
	}
	return;
}

void Scheduler::processRR(int time_quntum) {

	sort_push();	// ���� �� ť�� ����

	while (true) {

		readyQueSet();	// ready_que ���� (fcfs, RR ����-> �켱����ť�� �ƴ϶�)


		// �ھ� �ѹ��� ���� ���μ��� �Ҵ� �޾Ҵ��� Ȯ�� �� ready_que�� �ִ°� �Ҵ� (�ھ� �Ҵ�)
		for (int i = 0; i < core_list.size(); i++) {
			core_list[i].coreAlloc(ready_que);
		}
		//gui ȭ�鿡 ����� �κ� -> ������ xml�� �ʸ��� ����

		xml.SaveToXml(time, core_list);
		string outFilePath = "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/output.xml";
		xml.doc_Core.save_file(outFilePath.c_str());

		// �ھ� �ѹ��� ���� �ð� ���
		for (int i = 0; i < core_list.size(); i++) {
			if (core_list[i].alloc) {

				// �� �ھ�� �� ó�� ����
				core_list[i].progressProcess(process_list);

				//���� �ھ��� �ð� ����
				core_list[i].time_quntum--;

				// ��� �� �� ó��������
				if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
					core_list[i].coreReturn(process_list);
					core_list[i].time_quntum = time_quntum;
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

		// ��� ���μ��� �Ϸ������� ����
		if (completeScheduling())
			break;

		// �ð� ����
		time++;
	}
	return;
}