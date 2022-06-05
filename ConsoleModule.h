#pragma once
#include<string>
#include<vector>
#include<iostream>
#include <regex>
#include<climits>
#include<set>

#include"Logistics.h"

#define STRING_MAX_SIZE 30

using namespace std;

class Main {
public:
	Logistics* logistics;
	User* user;//�ѵ�¼�û�
	Courier* courier;//�ѵ�¼���Ա

	Main() {
		logistics = new Logistics();
		user = NULL;
		courier = NULL;
	}

	~Main() {
		delete(logistics);
	}
};

class ConsoleModule
{
protected:
	string name;
	vector<string> commands;//����
	vector<ConsoleModule*> subModules;//��ģ��
	vector<set<int>> ban;//��ģ���н�ֹʹ�õ��������
	int currentModule;//��ǰ��ģ��
public:
	ConsoleModule(const string& name) {
		this->name = name;
		currentModule = -1;
	}

	virtual ~ConsoleModule() {
		for (auto temp : subModules)
			delete(temp);
	}

	//��������
	virtual inline bool parse(Main& main, const string& command, const set<int>& ban) {
		if (currentModule != -1) {
			//������ģ��ִ��
			if (subModules.at(currentModule)->parse(main, command, this->ban.at(currentModule)))
				currentModule = -1;
			return false;
		}
		return execute(main, command, ban);
	}

	//ִ������
	virtual bool execute(Main& main,const string& command, const set<int>& ban) = 0;

	//��ȡ��ǰģ������
	virtual inline string getModuleName() {
		if (currentModule != -1) {
			return name + "$" + subModules.at(currentModule)->getModuleName();
		}
		return name;
	}

	//��ȡ��ǰģ������
	virtual vector<string> getModuleCommand(const set<int>& ban);
};

