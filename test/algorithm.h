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

	// ���� ��Ŀ����� �ӽ� ť(�ش� �ð��� ���°� ���� �ְ� ���� readyqueue�� ���� ť)
	queue<Process> temp_que;

	int time = 0;

	XmlHandler xml;

public:
	Scheduler(vector<Process> process_list, vector<Core> core_list);	// ������

	void sort_push();
	void readyQueSet();
	bool completeScheduling();

	// �˰���
	void processFCFS();
	void processRR(int time_quntum);

};


#endif // ALGO_H