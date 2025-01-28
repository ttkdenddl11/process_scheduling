#include<bits/stdc++.h>

#include "algorithm.h"

using namespace std;


int main() {

		vector<Process> process_list;
		vector<Core> core_list;
		queue<Process> que;
		queue<Process> ready_que;

		// 선점 방식에서의 임시 큐(해당 시간에 들어온걸 먼저 넣고 나서 readyqueue에 넣을 큐)
		queue<Process> temp_que;

		int time = 0;

		XmlHandler xml;

		if (xml.readXml(process_list, core_list, "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/processes.xml") == 1)
			return 0;

		Scheduler scheduler(process_list, core_list);

		switch (xml.algo_type) {
		case 0 :
			// fcfs 알고리즘
			scheduler.processFCFS();
			break;
		case 1:
			//라운드로빈 알고리즘
			scheduler.processRR(xml.time_quntum);
			break;
		default:
			break;
		}
	

	return 0;
}