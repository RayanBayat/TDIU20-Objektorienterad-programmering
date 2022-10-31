#ifndef time_h
#define time_h

// Kommentar: Viktigt att ni är konsekvent med indentering, mellanslag etc. Det blir väldigt jobbigt att läsa koden annars.

#include <string>
#include <iostream>
#include <sstream>

class Time
{
public:

	Time();
	
	Time(int hours, int minutes, int seconds);
	Time(std::string time);
	int hour()const;
	int minute()const;
	int second()const;
	bool is_am()const;
	
	std::string to_string(bool am = false)const;
	operator std::string()const;
	// Komplettering: add och sub ska inte implementeras som funktioner utan som operatorer enl. c++ konventioner. (d.v.s. + och - operator)
	// Kommentar: Era add och sub bör verkligen inte returnera en string utan en Time.
	
	Time operator +(int N);
	Time operator -(int N);
	Time & operator ++();
	Time & operator --();
	Time operator ++(int);
	Time operator --(int);
	bool operator >(Time const & t);
	bool operator <(Time const & t);
	// Komplettering: Likt ovan så ska detta implementeras mha operatorer enligt c++ standard (< > <= >= == !=).
	 bool operator <=(Time const & t);
	 bool operator >=(Time const & t);
	bool operator ==(Time const & t);
	bool operator !=(Time const & t);
private:
	int hours;
	int minutes;
	int seconds;

};
std::ostream & operator <<(std::ostream & os, Time const & t);


#endif
