#include "Courier.h"

void Courier::displayNPExp() {
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

void Courier::displayNRExp() {
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

void Courier::displayRExp()
{
    if (receivedList.size() == 0) {
        throw("No express received");
        return;
    }
    unsigned int i = 0;
    for (auto temp : receivedList) {
        cout << "[" << i++ << "]" << endl;
        cout << *temp;
    }
}

const vector<const Express*> Courier::searchPickTime(const time_t& begin, const time_t end) {
    vector<const Express*> result;
    for (auto temp = pickTimeList.lower_bound(begin); temp != pickTimeList.end() && temp->first <= end; temp++) {
        result.push_back(temp->second);
    }
    if (result.size() == 0)
        throw("No related express");
    return result;
}

const vector<const Express*> Courier::searchSender(const string& sender)
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

const vector<const Express*> Courier::searchReceiver(const string& receiver)
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