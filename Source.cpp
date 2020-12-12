#include "Header.h"

Bug::Bug(string description, int severity, float deadline, string status, string assignee)
{
    this->description = description;
    this->deadline = deadline;
    this->assignee = assignee;
    this->severity = severity;
    this->status = status;
}
Bug::Bug(Bug& other) {
    this->previous = NULL;
    this->next = NULL;
    this->description = other.description;
    this->severity = other.severity;
    this->deadline = other.deadline;
    this->status = other.status;
    this->assignee = other.assignee;
}
void Bug::showSomething() const {
    cout << "Description - " << description << "\nDifficalty - " << severity << "\nDeadline - " << deadline << "\nStatus - " << status << "\nAssegnee  - " << assignee;
}


void BackLog::insert(Bug* beforeTemporaryChange) {
    Bug* temporaryÑhange = new Bug(*beforeTemporaryChange);
    if (begin == NULL) {
        begin = temporaryÑhange;
        end = temporaryÑhange;
        return;
    }
    if (begin == end) {
        begin->next = temporaryÑhange;
        end = begin->next;
        end->previous = begin;
        return;
    }
    end->next = temporaryÑhange;
    end->next->previous = end;
    end = end->next;
}

void BackLog::show() {
    Bug* someBug = begin;
    while (someBug != NULL) {
        someBug->showSomething();
        someBug = someBug->next;
    }
}

BackLog :: ~BackLog() {
    Bug* someBug = begin;
    while (someBug != NULL) {
        Bug* temp = someBug;
        someBug = someBug->next;
        temp->showSomething();
        delete temp;
    }
}

void BackLog::showByStatus() {
    Bug* kol = begin;
    while (kol != NULL) {
        if (kol->status == "Resolved") {
            kol->showSomething();
        }
        kol = kol->next;
    }
}
void BackLog::shortBySeverity() {
    Bug* someBug = begin;
    while (someBug != end) {
        Bug* someBugTwo = someBug->next;
        Bug* smallNumber = someBug;
        while (someBugTwo != NULL) {
            if (someBugTwo->severity < smallNumber->severity) {
                smallNumber = someBugTwo;
            }
            someBugTwo = someBugTwo->next;
        }
        if (smallNumber != someBug){
            Bug* temp_previous;
            Bug* temp_next;
            someBug->previous->next = smallNumber;
            someBug->next->previous = smallNumber;
            smallNumber->previous->next = someBug;
            smallNumber->next->previous = someBug;
            temp_previous = someBug->previous;
            temp_next = someBug->next;
            someBug->previous = smallNumber->previous;
            someBug->next = smallNumber->next;
            smallNumber->previous = temp_previous;
            smallNumber->next = temp_next;
            someBug = smallNumber;
        }
        someBug = someBug->next;
    }
}