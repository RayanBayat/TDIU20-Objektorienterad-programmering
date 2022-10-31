#include <string>
#include <iostream>
#include <sstream>

#include "catch.hpp"
#include "time.h"

Time::Time()
:hours{0}, minutes{0}, seconds{0}
{}


// Komplettering: Mycket kodupprepning i era konstruktorer, flytta ut till hjälpfuktioner och/eller kasta bara ett exception "Invalid time"
// istället för att kasta ett för varje sak som skulle gå fel, användaren behöver inte veta mer än att tiden blev felaktig, och möjligtvis att 
// ni skriver ut vilken tid som ni fick in t.ex. "25:55:150 Is not a valid time"
Time::Time(int hours, int minutes, int seconds)
:hours{hours}, minutes{minutes}, seconds{seconds}
{
	if(hours< 0 || hours > 23 || minutes < 0 || minutes >59||seconds < 0 || seconds >59)
	{
		throw	std::logic_error("Invalid Time");

	}
}
Time::Time(std::string time)
:hours{(stoi(time.substr(0,2)))}, minutes{(stoi(time.substr(3,2)))}
,seconds{(stoi(time.substr(6,2)))}
{
	if(hours< 0 || hours > 23 || minutes < 0 || minutes >59||seconds < 0 || seconds >59)
	{
		throw	std::logic_error("Invalid Time");

	}
}

int Time::hour()const
{
	if (hours< 0 || hours > 23)
	{
		throw std::logic_error("Wrong hour");
	}
	else{
		return hours;
	}


}
int Time::minute()const
{
	if (minutes< 0 || minutes > 59)
	{
		throw std::logic_error("Wrong minute");
	}
	else
	{
		return minutes;
	}
}
int Time::second()const
{
	if (seconds< 0 || seconds > 59)
	{
		throw std::logic_error("Wrong seconds");
	}
	else
	{
		return seconds;
	}

}
bool Time::is_am()const
{
	if(hours >= 12)
	{
		return false;
	}
	else {
		return true;
	}
}

// Komplettering: Kodupprepning, se kommentar ovan.


// Kommentar: Här kan ni sätta ett standardvärde på inparametern och ta bort funktionen ovan helt och hållet
// blir extrem kodupprepning på detta sätt.

std::string Time::to_string(bool am)const



{
	if(am == true)
	{
		if(hours < 10)
		{
			if(minutes < 10)
			{
				if(seconds < 10)
				{	
					return '0'+ std::to_string(hours-12) +':'+ '0'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds) + " pm";
				}
				else{
					return '0'+ std::to_string(hours-12) +':'+ '0'+std::to_string(minutes)+':'+
					std::to_string(seconds)+ " pm" ;
				}
			}
			else{
				if(seconds < 10)
				{	
					return '0'+ std::to_string(hours-12) +':'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds) + " pm";
				}
				else{
					return '0'+ std::to_string(hours-12) +':'+std::to_string(minutes)+':'+
					std::to_string(seconds) + " pm";
				}
			}
		}
		else
		{

			if(minutes < 10)
			{
				if(seconds < 10)
				{	
					return  std::to_string(hours-12) +':'+ '0'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds) + " pm";
				}
				else{
					return '0'+ std::to_string(hours-12) +':'+ '0'+std::to_string(minutes)+':'+
					std::to_string(seconds)+ " pm" ;
				}
			}
			else{
				if(seconds < 10)
				{	
					return  std::to_string(hours-12) +':'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds) + " pm";
				}
				else{
					return '0'+ std::to_string(hours-12) +':'+std::to_string(minutes)+':'+
					std::to_string(seconds) + " pm";
				}
			}
		}
	}
	else
		
	{
		if(hours < 10)
		{
			if(minutes < 10)
			{
				if(seconds < 10)
				{	
					return  '0'+std::to_string(hours) +':'+ '0'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds) ;
				}
				else{
					return '0'+ std::to_string(hours) +':'+ '0'+std::to_string(minutes)+':'+
					std::to_string(seconds);
				}
			}
			else{
				if(seconds < 10)
				{	
					return  '0'+std::to_string(hours) +':'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds) ;
				}
				else{
					return '0'+ std::to_string(hours) +':'+std::to_string(minutes)+':'+
					std::to_string(seconds) ;
				}
			}
		}
		else
		{

			if(minutes < 10)
			{
				if(seconds < 10)
				{	
					return  std::to_string(hours) +':'+ '0'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds) ;
				}
				else{
					return '0'+ std::to_string(hours) +':'+ '0'+std::to_string(minutes)+':'+
					std::to_string(seconds);
				}
			}
			else{
				if(seconds < 10)
				{	
					return  std::to_string(hours) +':'+std::to_string(minutes)+':'+
					'0'+std::to_string(seconds);
				}
				else{
					return  std::to_string(hours) +':'+std::to_string(minutes)+':'+
					std::to_string(seconds) ;
				}
			}
		}
	}
}
/*std::string Time::astring(Time(int hours, int minutes, int seconds))const
	{
		return  ':';
	}*/

std::ostream & operator <<(std::ostream & os, Time const & t)
{
	os << t.to_string();
	return os;

}
Time::operator std::string()const
{
	return to_string();
}

Time Time::operator +(int N){
{
	int count1 = (hours*60*60)+(minutes*60)+ seconds;
	int count2 = count1 + N;
	int m, h;

	seconds = count2 % 60 ;
	m = count2 / 60;
	minutes = m % 60;
	h = m / 60;
	hours = h % 24;
	count1 = (hours*60*60)+(minutes*60)+seconds;
	if(count1<0){
		count2 = 86400 + count1;
		seconds = count2 % 60 ;
		m = count2 / 60;
		minutes = m % 60;
		h = m / 60;
		hours = h % 24;

	}





	return *this;
}
}

Time Time::operator -(int N){
{
	int count1 = (hours*60*60)+(minutes*60)+ seconds;
	int count2 = count1 - N;
	int m, h;

	seconds = count2 % 60 ;
	m = count2 / 60;
	minutes = m % 60;
	h = m / 60;
	hours = h % 24;
	count1 = (hours*60*60)+(minutes*60)+seconds;
	if(count1<0){
		count2 = 86400 + count1;
		seconds = count2 % 60 ;
		m = count2 / 60;
		minutes = m % 60;
		h = m / 60;
		hours = h % 24;

	}

	return *this;
}
}
Time & Time::operator ++(){
	*this = *this + 1;
		return *this;

}
Time & Time::operator --(){
		*this = *this - 1;
	return *this;;
}
Time Time::operator ++(int){
	Time c{*this+1};
	
	return c;
	
}
Time Time::operator --(int){
	Time c{*this-1};
	
	return c;
}

bool Time::operator >(Time const & t){
	
	bool bigger;
	if(hours > t.hours)
	{
		bigger = true;
	}
	else
	{
		if(minutes > t.minutes)
		{
			bigger = true;
		}
		else
		{
			if(seconds > t.seconds)
			{
				bigger = true;
			}
			else
			{
				bigger = false;
			}
		}
	}
return bigger;
}
bool Time::operator <(Time const & t){
bool smaller;
	if(hours < t.hours)
	{
		smaller = true;
	}
	else
	{
		if(minutes < t.minutes)
		{
			smaller = true;
		}
		else
		{
			if(seconds < t.seconds)
			{
				smaller = true;
			}
			else
			{
				smaller = false;
			}
		}
	}
return smaller;
}
bool Time::operator ==(Time const & t){
	if(!(*this > t) && !(*this < t))
	{
		return true;
	}

	return false;

}
bool Time::operator <=(Time const & t){
	if(!(*this > t))
	{
		return true;
	}
	return false;
}
bool Time::operator >=(Time const & t){
	if(!(*this < t))
	{
		return true;
	}
	return false;
}
bool Time::operator !=(Time const & t){
	if(!(*this == t))
	{
		return true;
	}
		return false;
}


  //   time_t now = time(0);
  //   string dt  = (ctime(&now));
  //   string a   = dt.substr(11,8);

  //   Time t(a);
  //   // CHECK(t.is_am());
  //   CHECK_FALSE(t.is_am());

  // 