#include "Header.h"

Bag::Bag(string description, int severity, float deadline, string status, string assegnee)
{
    this->description = description;
    this->deadline = deadline;
    this->assegnee = assegnee;
    this->severity = severity;
    this->status = status;
    //cout << "Description - " << description << "\nDifficalty - " << severity << "\nDeadline - " << deadline << "\nStatus - " << status << "\nAssegnee  - " << assegnee;
}
Bag::Bag(Bag& B) {
    this->previous = NULL;
    this->next = NULL;
    this->description = B.description;
    this->severity = B.severity;
    this->deadline = B.deadline;
    this->status = B.status;
    this->assegnee = B.assegnee;
}
void Bag::showSomething() const {
    cout << "Description - " << description << "\nDifficalty - " << severity << "\nDeadline - " << deadline << "\nStatus - " << status << "\nAssegnee  - " << assegnee;
}


void BackLog::insert(Bag* give1) {
    Bag* give = new Bag(*give1);
    if (begin == NULL) {
        begin = give;
        end = give;
        return;
    }
    if (begin == end) {
        begin->next = give;
        end = begin->next;
        end->previous = begin;
        return;
    }
    end->next = give;
    end->next->previous = end;
    end = end->next;
}

void BackLog::show() {
    Bag* kol = begin;
    while (kol != NULL) {
        kol->showSomething();
        kol = kol->next;
    }
}

BackLog :: ~BackLog() {
    Bag* kol = begin;
    while (kol != NULL) {
        Bag* temp = kol;

        kol = kol->next;

        temp->showSomething();
        delete temp;
    }
}

void BackLog::showByStatus() {

    Bag* kol = begin;
    while (kol != NULL) {
        if (kol->status == "Resolved") {
            kol->showSomething();
        }
        kol = kol->next;
    }
}
void BackLog::shortBySeverity() {
    Bag* kol = begin;
    while (kol != end) {
        Bag* kol2 = kol->next;
        Bag* smallnumber = kol;
        while (kol2 != NULL) {
            if (kol2->severity < smallnumber->severity) {
                smallnumber = kol2;

            }
            kol2 = kol2->next;
        }
        if (smallnumber != kol)
        {
            Bag* temp_previous;
            Bag* temp_next;
            kol->previous->next = smallnumber;
            kol->next->previous = smallnumber;
            smallnumber->previous->next = kol;
            smallnumber->next->previous = kol;
            temp_previous = kol->previous;
            temp_next = kol->next;
            kol->previous = smallnumber->previous;
            kol->next = smallnumber->next;
            smallnumber->previous = temp_previous;
            smallnumber->next = temp_next;
            kol = smallnumber;

        }
        kol = kol->next;
    }
}