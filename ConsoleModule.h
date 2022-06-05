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
	User* user;//已登录用户
	Courier* courier;//已登录快递员

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
	vector<string> commands;//命令
	vector<ConsoleModule*> subModules;//子模块
	vector<set<int>> ban;//子模块中禁止使用的命令序号
	int currentModule;//当前子模块
public:
	ConsoleModule(const string& name) {
		this->name = name;
		currentModule = -1;
	}

	virtual ~ConsoleModule() {
		for (auto temp : subModules)
			delete(temp);
	}

	//分析命令
	virtual inline bool parse(Main& main, const string& command, const set<int>& ban) {
		if (currentModule != -1) {
			//交给子模块执行
			if (subModules.at(currentModule)->parse(main, command, this->ban.at(currentModule)))
				currentModule = -1;
			return false;
		}
		return execute(main, command, ban);
	}

	//执行命令
	virtual bool execute(Main& main,const string& command, const set<int>& ban) = 0;

	//获取当前模块名字
	virtual inline string getModuleName() {
		if (currentModule != -1) {
			return name + "$" + subModules.at(currentModule)->getModuleName();
		}
		return name;
	}

	//获取当前模块命令
	virtual vector<string> getModuleCommand(const set<int>& ban);
};

