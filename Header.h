#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Bag {
public:
	string description;
	int severity;
	float deadline;
	string status;
	string assegnee;

	Bag* next = NULL;
	Bag* previous = NULL;
	Bag(string, int, float, string, string);

	void showSomething() const;
	Bag(Bag& B);
};

class BackLog {
public:
	~BackLog();
	Bag* begin = NULL;
	Bag* end = NULL;
	void insert(Bag* give1);
	void show();
	void showByStatus();
	void shortBySeverity();
};
