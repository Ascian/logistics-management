#pragma once
#include<iostream>
using namespace std;
class DateTime{
private:
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
public:
	DateTime(const unsigned char year, const unsigned char month, const unsigned char day,
		const unsigned char hour, const unsigned char minute) {
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
		this->minute = minute;
	}

	inline const bool operator<(const DateTime& dateTime) {
		if (this->year < dateTime.year) return true;
		if (this->year > dateTime.year) return false;
		if (this->month < dateTime.month) return true;
		if (this->month > dateTime.month) return false;
		if (this->day < dateTime.day) return true;
		if (this->day > dateTime.day) return false;
		if (this->hour < dateTime.hour) return true;
		if (this->hour > dateTime.hour) return false;
		if (this->minute < dateTime.minute) return true;
		if (this->minute > dateTime.minute) return false;
	}

	inline const bool operator>(const DateTime& dateTime) {
		if (this->year > dateTime.year) return true;
		if (this->year < dateTime.year) return false;
		if (this->month > dateTime.month) return true;
		if (this->month < dateTime.month) return false;
		if (this->day > dateTime.day) return true;
		if (this->day < dateTime.day) return false;
		if (this->hour > dateTime.hour) return true;
		if (this->hour < dateTime.hour) return false;
		if (this->minute > dateTime.minute) return true;
		if (this->minute < dateTime.minute) return false;
	}

	inline bool isZero() { return year == 0 && month == 0 && day == 0 && hour == 0 && minute == 0; }

	inline const 

	friend ostream& operator<<(ostream& Ostr, const DateTime& time);
};
inline ostream& operator<<(ostream& Ostr, const DateTime& time) {
	return Ostr << (unsigned int)time.year << "." << (unsigned int)time.month << "." << (unsigned int)time.day <<
		" " << (unsigned int) time.hour << ":" << (unsigned int)time.minute;
}

