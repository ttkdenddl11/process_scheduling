#include "algorithm.h"

Scheduler::Scheduler(vector<Process> process_list, vector<Core> core_list) {
	this->process_list = process_list;
	this->core_list = core_list;
}

void Scheduler::sort_push() {
	sort(process_list.begin(), process_list.end(), [](const Process& a, const Process& b) {
		return a.arrive_time < b.arrive_time; // 오름차순 정렬
		});

	for (int i = 0; i < process_list.size(); i++) {	// 정렬 후 큐에 담기 (ready_que 전의 큐)
		que.push(process_list[i]);
	}
}

void Scheduler::readyQueSet() {
	// 큐에서 도착시간이 time과 같아지면 ready_Que에 저장
	while (!que.empty() && que.front().arrive_time <= time) {
		ready_que.push(que.front());
		que.pop();
	}

	// 선점방식의 임시 큐
	while (!temp_que.empty()) {
		ready_que.push(temp_que.front());
		temp_que.pop();
	}
}

bool Scheduler::completeScheduling() {
	bool end = true;
	// 프로세스 한바퀴 돌면서 끝나면 끝
	for (int i = 0; i < process_list.size(); i++) {
		if (!process_list[i].end) {
			end = false;
		}
	}
	return end;
}

void Scheduler::processFCFS() {
	// gui로 부터 입력받음
	/*if (xml.readXml(process_list, core_list, "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/processes.xml") == 1)
		return;*/

	// cli로 입력받는 예시
	//process_list.push_back({ "p1", 5, 6 });
	//process_list.push_back({ "p2", 0, 7 });
	//process_list.push_back({ "p3", 3, 2 });
	//process_list.push_back({ "p4", 4, 9 });
	//process_list.push_back({ "p5", 2, 8 });
	//process_list.push_back({ "p6", 2, 7 });
	//process_list.push_back({ "p7", 11, 5 });
	//process_list.push_back({ "p8", 12, 3 });
	//process_list.push_back({ "p9", 10, 7 });
	//core_list.push_back({1, time_quntum, false, ""});	// 0일시 P코어,, 1일시 E코어
	//core_list.push_back({0, time_quntum, false, "" });	// 0일시 P코어,, 1일시 E코어
	//core_list.push_back({ 1, time_quntum, false, "" });	// 0일시 P코어,, 1일시 E코어
	//core_list.push_back({ 0, time_quntum, false, "" });	// 0일시 P코어,, 1일시 E코어

	
	sort_push();	// 정렬 후 큐에 넣음

	while (true) {

		readyQueSet();	// ready_que 세팅 (fcfs, RR 같음-> 우선순위큐가 아니라서)

		
		// 코어 한바퀴 돌며 프로세스 할당 받았는지 확인 후 ready_que에 있는거 할당 (코어 할당)
		for (int i = 0; i < core_list.size(); i++) {
			core_list[i].coreAlloc(ready_que);
		}
		//gui 화면에 출력할 부분 -> 데이터 xml로 초마다 저장
		/*cout << time << "초" << '\n';
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
		cout << '\n';*/

		xml.SaveToXml(time, core_list);
		string outFilePath = "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/output.xml";
		xml.doc_Core.save_file(outFilePath.c_str());

		// 코어 한바퀴 돌며 시간 계산
		for (int i = 0; i < core_list.size(); i++) {
			if (core_list[i].alloc) {
				
				// 각 코어에서 일 처리 진행
				core_list[i].progressProcess(process_list);

				// 모든 일 다 처리했으면
				if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
					core_list[i].coreReturn(process_list);
					//core_list[i].getProcess(process_list)->name = "";

				}
			}
		}

		// 모든 프로세스 완료했으면 종료
		if (completeScheduling())
			break;

		// 시간 증가
		time++;
	}
	return;
}

void Scheduler::processRR(int time_quntum) {

	sort_push();	// 정렬 후 큐에 넣음

	while (true) {

		readyQueSet();	// ready_que 세팅 (fcfs, RR 같음-> 우선순위큐가 아니라서)


		// 코어 한바퀴 돌며 프로세스 할당 받았는지 확인 후 ready_que에 있는거 할당 (코어 할당)
		for (int i = 0; i < core_list.size(); i++) {
			core_list[i].coreAlloc(ready_que);
		}
		//gui 화면에 출력할 부분 -> 데이터 xml로 초마다 저장

		xml.SaveToXml(time, core_list);
		string outFilePath = "C://Users/user/source/repos/test/winformProcessSceheduling/bin/Debug/output.xml";
		xml.doc_Core.save_file(outFilePath.c_str());

		// 코어 한바퀴 돌며 시간 계산
		for (int i = 0; i < core_list.size(); i++) {
			if (core_list[i].alloc) {

				// 각 코어에서 일 처리 진행
				core_list[i].progressProcess(process_list);

				//선점 코어의 시간 빼기
				core_list[i].time_quntum--;

				// 모든 일 다 처리했으면
				if (core_list[i].getProcess(process_list)->remaining_time <= 0) {
					core_list[i].coreReturn(process_list);
					core_list[i].time_quntum = time_quntum;
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

		// 모든 프로세스 완료했으면 종료
		if (completeScheduling())
			break;

		// 시간 증가
		time++;
	}
	return;
}