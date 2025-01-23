#pragma once

#ifndef ALGO_H
#define ALGO_H

#include "core.h"  // Core, Process 클래스 포함

void processFCFS(vector<Core>& core_list, vector<Process>& process_list);
void processRR(vector<Core>& core_list, vector<Process>& process_list, int time_quntum, queue<Process>& ready_que);

#endif // ALGO_H