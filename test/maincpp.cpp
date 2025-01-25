#include<bits/stdc++.h>
#include "software.h"
#include "core.h"
#include "algorithm.h"
#include "pugixml.hpp"

using namespace std;

int algo_type = 0;	//0�Ͻ� FCFS, 1�Ͻ� RR
int core_type = 0;	//0�Ͻ� P�ھ�, 1�Ͻ� E�ھ�
int time_quntum = 2;

pugi::xml_document doc_Core;
pugi::xml_node coresNode = doc_Core.append_child("Cores");

// gui�� ���� ������ �޾ƿ��� �κ�
int readXml(vector<Process>& process_list, vector<Core>& core_list, const char* xmlFilePath) {
	pugi::xml_document doc;
	if (!doc.load_file(xmlFilePath)) {
		std::cerr << "Failed to load XML file.\n";
		return 1;
	}
	
	//���μ��� ����(�̸�, �����ð�, ����ð�) ��������
	for (pugi::xml_node process : doc.child("processes").children("process")) {

		string name = process.child("Name").text().as_string();
		int arrive_time = process.child("ArriveTime").text().as_int();
		int burst_time = process.child("BurstTime").text().as_int();

		Process p(name, arrive_time, burst_time);

		process_list.push_back(p);
	}
	
	//�˰��� Ÿ�԰� Ÿ������ ��������
	string algorithm = doc.child("processes").child("algorithm").text().as_string();
	time_quntum = doc.child("processes").child("timeQuntum").text().as_int();

	if (algorithm == "FCFS")
		algo_type = 0;
	else if (algorithm == "RR")
		algo_type = 1;


	//�ھ� Ÿ�� ��������
	for (pugi::xml_node coreType = doc.child("processes").child("coreTypes").child("coreType");
		coreType; coreType = coreType.next_sibling("coreType")) {

		core_type = coreType.text().as_int();

		Core c(core_type, time_quntum, false, "");

		core_list.push_back(c);
	}
}

// gui�� ������ ������ �κ�
void SaveToXml(int time, vector<Core>& core_list) {

	pugi::xml_node timeNode = coresNode.append_child("Time");
	timeNode.append_attribute("Value") = time;

	for (int i = 0; i < core_list.size(); i++) {
		pugi::xml_node coreNode = timeNode.append_child("Core");
		coreNode.append_child("Index").text() = i;
		if(core_list[i].alloc == false)
			coreNode.append_child("Name").text() = "";
		else
			coreNode.append_child("Name").text() = core_list[i].process_name.c_str();
	}
}

int main() {
	vector<Process> process_list;
	vector<Core> core_list;
	queue<Process> que;
	queue<Process> ready_que;
	
	// gui�� ���� �Է¹���
	if (readXml(process_list, core_list, "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/processes.xml") == 1)
		return 1;

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


	sort(process_list.begin(), process_list.end(), [](const Process& a, const Process& b) {
		return a.arrive_time < b.arrive_time; // �������� ����
		});

	for (int i = 0; i < process_list.size(); i++) {
		que.push(process_list[i]);
	}

	int time = 0;
	
	// ���� ��Ŀ����� �ӽ� ť(�ش� �ð��� ���°� ���� �ְ� ���� readyqueue�� ���� ť)
	queue<Process> temp_que;

	while (true) {

		bool end = true;

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

		// �ھ� �ѹ��� ���� ���μ��� �Ҵ� �޾Ҵ��� Ȯ��
		for (int i = 0; i < core_list.size(); i++) {
			if (!ready_que.empty() && !core_list[i].alloc) {
				core_list[i].alloc = true;
				core_list[i].process_name = ready_que.front().name;
				ready_que.pop();
			}
		}
		//gui ȭ�鿡 ����� �κ�
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

		SaveToXml(time, core_list);
		string outFilePath = "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/output.xml";
		doc_Core.save_file(outFilePath.c_str());

		switch (algo_type) {
		case 0 :
			// fcfs �˰���
			processFCFS(core_list, process_list);
			break;
		case 1:
			//����κ� �˰���
			processRR(core_list, process_list, time_quntum, temp_que);
			break;
		default:
			break;
		}
		

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