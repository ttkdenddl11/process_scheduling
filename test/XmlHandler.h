#pragma once

#include "pugixml.hpp"
#include "software.h"
#include "core.h"

class XmlHandler {

public:
	int algo_type;	//0일시 FCFS, 1일시 RR
	int core_type;	//0일시 P코어, 1일시 E코어
	int time_quntum;

	pugi::xml_document doc_Core;
	pugi::xml_node coresNode = doc_Core.append_child("Cores");

public:
	// gui로 부터 데이터 받아오는 부분
	int readXml(vector<Process>& process_list, vector<Core>& core_list, const char* xmlFilePath);

	// gui로 데이터 보내는 부분
	void SaveToXml(int time, vector<Core>& core_list);
};