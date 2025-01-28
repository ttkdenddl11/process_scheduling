#pragma once

#ifndef ALGO_H
#define ALGO_H

#include<bits/stdc++.h>
#include "XmlHandler.h"

class Scheduler {
public:
	vector<Process> process_list;
	vector<Core> core_list;
	queue<Process> que;
	queue<Process> ready_que;

	// 선점 방식에서의 임시 큐(해당 시간에 들어온걸 먼저 넣고 나서 readyqueue에 넣을 큐)
	queue<Process> temp_que;

	int time = 0;

	XmlHandler xml;

public:
	Scheduler(vector<Process> process_list, vector<Core> core_list);	// 생성자

	void sort_push();
	void readyQueSet();
	bool completeScheduling();

	// 알고리즘
	void processFCFS();
	void processRR(int time_quntum);

};


#endif // ALGO_H