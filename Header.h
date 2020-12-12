#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Bug {
public:
	string description;
	int severity;
	float deadline;
	string status;
	string assignee;

	Bug* next = NULL;
	Bug* previous = NULL;
	Bug(string, int, float, string, string);

	void showSomething() const;
	Bug(Bug& B);
};

class BackLog {
public:
	  ~BackLog();
	Bug* begin = NULL;
	Bug* end = NULL;
	void insert(Bug* give1);
	void show();
	void showByStatus();
	void shortBySeverity();
};
