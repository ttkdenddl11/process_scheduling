#include<bits/stdc++.h>

#include "algorithm.h"

using namespace std;


int main() {

		vector<Process> process_list;
		vector<Core> core_list;
		queue<Process> que;
		queue<Process> ready_que;

		// ���� ��Ŀ����� �ӽ� ť(�ش� �ð��� ���°� ���� �ְ� ���� readyqueue�� ���� ť)
		queue<Process> temp_que;

		int time = 0;

		XmlHandler xml;

		if (xml.readXml(process_list, core_list, "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/processes.xml") == 1)
			return 0;

		Scheduler scheduler(process_list, core_list);

		switch (xml.algo_type) {
		case 0 :
			// fcfs �˰���
			scheduler.processFCFS();
			break;
		case 1:
			//����κ� �˰���
			scheduler.processRR(xml.time_quntum);
			break;
		default:
			break;
		}
	

	return 0;
}