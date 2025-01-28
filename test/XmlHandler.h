#pragma once

#include "pugixml.hpp"
#include "software.h"
#include "core.h"

class XmlHandler {

public:
	int algo_type;	//0�Ͻ� FCFS, 1�Ͻ� RR
	int core_type;	//0�Ͻ� P�ھ�, 1�Ͻ� E�ھ�
	int time_quntum;

	pugi::xml_document doc_Core;
	pugi::xml_node coresNode = doc_Core.append_child("Cores");

public:
	// gui�� ���� ������ �޾ƿ��� �κ�
	int readXml(vector<Process>& process_list, vector<Core>& core_list, const char* xmlFilePath);

	// gui�� ������ ������ �κ�
	void SaveToXml(int time, vector<Core>& core_list);
};