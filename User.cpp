#include "User.h"

void User::displaySExp() {
    if (sendTimeList.size() == 0) {
        throw("No express sended");
        return;
    }
    unsigned int i = 0;
    for (auto temp : sendTimeList) {
        cout << "[" << i++ << "]" << endl;
        cout << *temp.second ;
    }
}

void User::displayNPExp()
{
    if (notPickedList.size() == 0) {
        throw("No express not picked up");
        return;
    }
    unsigned int i = 0;
    for (auto temp : notPickedList) {
        cout << "[" << i++ << "]" << endl;
        cout << *temp;
    }
}

void User::displayRExp() {
    if (receiveTimeList.size() == 0) {
        throw("No express received");
        return;
    }
    unsigned int i = 0;
    for (auto temp : receiveTimeList) {
        cout << "[" << i++ << "]" << endl;
        cout << *temp.second;
    }
}

void User::displayNSExp()
{
    if (notSendedList.size() == 0) {
        throw("No express not sended");
        return;
    }
    unsigned int i = 0;
    for (auto temp : notSendedList) {
        cout << "[" << i++ << "]" << endl;
        cout << *temp;
    }
}

void User::displayNRExp() {
    if (notReceivedList.size() == 0) {
        throw("No express not received");
        return;
    }
    unsigned int i = 0;
    for (auto temp : notReceivedList) {
        cout << "[" << i++ << "]" << endl;
        cout << *temp;
    }
}

const vector<const Express*> User::searchSendTime(const time_t& begin, const time_t end) {
    vector<const Express*> result;
    for (auto temp = sendTimeList.lower_bound(begin); temp != sendTimeList.end() && temp->first <= end; temp++) {
        result.push_back(temp->second);
    }
    if (result.size() == 0)
        throw("No related express");
    return result;
}

const vector<const Express*> User::searchReceiveTime(const time_t& begin, const time_t end) {
    vector<const Express*> result;
    for (auto temp = receiveTimeList.lower_bound(begin);temp!= receiveTimeList.end() && temp->first <= end; temp++) {
        result.push_back(temp->second);
    }
    if (result.size() == 0)
        throw("No related express");
    return result;
}

const vector<const Express*> User::searchSender(const string& sender)
{
    vector<const Express*> result;
    auto temp = senderList.equal_range(sender);
    for (auto i = temp.first; i != temp.second; i++) {
        result.push_back(i->second);
    }
    if (result.size() == 0)
        throw("No related express");
    return result;
}

const vector<const Express*> User::searchReceiver(const string& receiver)
{
    vector<const Express*> result;
    auto temp = receiverList.equal_range(receiver);
    for (auto i = temp.first; i != temp.second; i++) {
        result.push_back(i->second);
    }
    if (result.size() == 0)
        throw("No related express");
    return result;
}




