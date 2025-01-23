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

	// gui로 부터 입력받음
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
	core_list.push_back({1, time_quntum, false, ""});	// 0일시 P코어,, 1일시 E코어
	core_list.push_back({0, time_quntum, false, "" });	// 0일시 P코어,, 1일시 E코어
	core_list.push_back({ 1, time_quntum, false, "" });	// 0일시 P코어,, 1일시 E코어
	core_list.push_back({ 0, time_quntum, false, "" });	// 0일시 P코어,, 1일시 E코어


	sort(process_list.begin(), process_list.end(), [](const Process& a, const Process& b) {
		return a.arrive_time < b.arrive_time; // 오름차순 정렬
		});

	for (int i = 0; i < process_list.size(); i++) {
		que.push(process_list[i]);
	}

	int time = 0;

	while (true) {

		bool end = true;

		// 큐에서 도착시간이 time과 같아지면 ready_Que에 저장
		while (!que.empty() && que.front().arrive_time <= time) {
			ready_que.push(que.front());
			que.pop();
		}
		// 코어 한바퀴 돌며 프로세스 할당 받았는지 확인
		for (int i = 0; i < core_list.size(); i++) {
			if (!ready_que.empty() && !core_list[i].alloc) {
				core_list[i].alloc = true;
				core_list[i].process_name = ready_que.front().name;
				ready_que.pop();
			}
		}
		//gui 화면에 출력할 부분
		cout << time << "초" << '\n';
		for (int i = 0; i < core_list.size(); i++) {
			if (core_list[i].core_type == 0)
				cout << "p코어 : ";
			else if (core_list[i].core_type == 1)
				cout << "e코어 : ";
			if (!core_list[i].alloc)
				cout << "할당x" << '\n';
			else {
				cout << core_list[i].process_name << '\n';
			}
		}
		cout << '\n';

		// fcfs 알고리즘
		//processFCFS(core_list, process_list);
		
		//라운드로빈 알고리즘
		processRR(core_list, process_list, time_quntum, ready_que);

		// 프로세스 한바퀴 돌면서 끝나면 끝
		for (int i = 0; i < process_list.size(); i++) {
			if (!process_list[i].end) {
				end = false;
			}
		}
		// 시간 증가
		time++;
		if (end)
			break;
	}

	return 0;
}