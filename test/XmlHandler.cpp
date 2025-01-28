
#include "XmlHandler.h"
#include <iostream>

// gui로 부터 데이터 받아오는 부분
int XmlHandler::readXml(vector<Process>& process_list, vector<Core>& core_list, const char* xmlFilePath) {
	pugi::xml_document doc;
	if (!doc.load_file(xmlFilePath)) {
		std::cerr << "Failed to load XML file.\n";
		return 1;
	}

	//프로세스 정보(이름, 도착시간, 실행시간) 가져오기
	for (pugi::xml_node process : doc.child("processes").children("process")) {

		string name = process.child("Name").text().as_string();
		int arrive_time = process.child("ArriveTime").text().as_int();
		int burst_time = process.child("BurstTime").text().as_int();

		Process p(name, arrive_time, burst_time);

		process_list.push_back(p);
	}

	//알고리즘 타입과 타임퀀텀 가져오기
	string algorithm = doc.child("processes").child("algorithm").text().as_string();
	time_quntum = doc.child("processes").child("timeQuntum").text().as_int();

	if (algorithm == "FCFS")
		algo_type = 0;
	else if (algorithm == "RR")
		algo_type = 1;


	//코어 타입 가져오기
	for (pugi::xml_node coreType = doc.child("processes").child("coreTypes").child("coreType");
		coreType; coreType = coreType.next_sibling("coreType")) {

		core_type = coreType.text().as_int();

		Core c(core_type, time_quntum, false, "");

		core_list.push_back(c);
	}
}


// gui로 데이터 보내는 부분
void XmlHandler::SaveToXml(int time, vector<Core>& core_list) {

	pugi::xml_node timeNode = coresNode.append_child("Time");
	timeNode.append_attribute("Value") = time;

	for (int i = 0; i < core_list.size(); i++) {
		pugi::xml_node coreNode = timeNode.append_child("Core");
		coreNode.append_child("Index").text() = i;
		if (core_list[i].alloc == false)
			coreNode.append_child("Name").text() = "";
		else
			coreNode.append_child("Name").text() = core_list[i].process_name.c_str();
	}
}