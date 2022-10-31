#ifndef simulate_h
#define simulate_h

#include <iostream>
#include <initializer_list>
#include <iterator> 
#include <vector>
#include <sstream>
#include <string>

//Kommentar komplettering: Vid felaktigt inmatningsargument ska
//programmet avslutas med ett instruktivt felmeddelande. "Fel antal
//argument" ger inte användaren så mycket.

//Kommentar: try och catch bör endast ske i början av programmet då
//inparametrarna kollas. Programmet ska fungera korrekt då dessa har
//hämtas in.

struct Connection
	{
		double charge = 0;
	};

//-------------Component-------------------
class Component
{
public:
	Component(std::string const &new_name, Connection& l, Connection& r);
	virtual ~Component();
	double get_voltage();
	virtual double get_current() = 0;
	virtual void update(double) = 0;

	std::string const name;
	
protected:
	

	Connection& left;
	Connection& right;
};

//-------------Battery-------------------
class Battery : public Component
{
public:
	~Battery() = default;
	Battery(std::string const &new_name, double voltage, Connection& l, Connection& r);
	double get_current() override;
	void update(double) override;

private:
	double _voltage;
};

//-------------Resistor-------------------
class Resistor : public Component
{
public:
	~Resistor() = default;
	Resistor(std::string const &new_name, double resistance, Connection& l, Connection& r);
	double get_current() override;
	void update(double) override;

private:
	double _resistance;
};

//-------------Capacitor-------------------
class Capacitor : public Component
{
public:
	~Capacitor() = default;
	Capacitor(std::string const &new_name, double capacitance, Connection& l, Connection& r);
	double get_current() override;
	void update(double) override;

private:	
	double _capacitance;
	double _charge;
};

void simulate(std::vector<Component*> const & , int, int, double);
#endif
