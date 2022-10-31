#include <iostream>
#include <initializer_list>
#include <iterator> 
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>

#include "simulate.h"

using namespace std;

//-------------Component-------------------
Component::Component(string const &new_name, Connection& l, Connection& r) 
	: name{new_name}, left{l}, right{r}
{

}


Component::~Component()
{
	// for (Component* c : net)
	// {
	// 	delete c;
	// }
}

double Component::get_voltage()
{
	return (right.charge) - (left.charge);
}

//-------------Battery-------------------
Battery::Battery(string const &new_name, double voltage, Connection& l, Connection& r) 
	: Component{new_name, l, r}, _voltage{voltage}
{

}

double Battery::get_current()
{
	return 0;
}

void Battery::update(double dt)
{
	left.charge = 0.0 * dt; // (* dt) Tar bort varning
	right.charge = _voltage;
}

//-------------Resistor-------------------
Resistor::Resistor(string const &new_name, double resistance, Connection& l, Connection& r)
	: Component{new_name, l, r}, _resistance{resistance}
{

}	

double Resistor::get_current()
{
	double answer = get_voltage() / _resistance;
	//cout << "Res " << _resistance << "Volt" << get_voltage() << endl;
	return answer;
}

void Resistor::update(double dt)
{
	double current = get_current();
	left.charge += (current * dt);
	right.charge  -= (current * dt);
	//cout << "Update:" << left.charge << "  " << right.charge << endl;
}

//-------------Capacitor-------------------
Capacitor::Capacitor(string const &new_name, double capacitance,  
	Connection& l, Connection& r) 
	: Component{new_name, l, r}, _capacitance{capacitance}, _charge{0}
{

}

double Capacitor::get_current()
{
	double answer = (_capacitance * (get_voltage() - _charge));
	return answer;
}

void Capacitor::update(double dt)
{
	double current = get_current();
	_charge += current * dt;
	left.charge += (current * dt);
	right.charge -= (current * dt);
}

void simulate(vector<Component*> const &net, int iterations, int outputs, double dt)
{
	int thingy = iterations/outputs;

	for (Component* c : net)
	{
		cout << setw(12) << c -> name ;
	}

	cout << endl;

	for (Component* c : net)
	{
		 c = c;
		cout << setw(6) << "Volt" << setw(6) << "Curr";
	}

	cout << endl;

	for (int i = 0; i < iterations; ++i)
	{
		thingy--;

		for (Component* c : net)
		{
			c -> update(dt);
		}
		
		if (thingy == 0)
			{
				thingy = iterations/outputs;

				for (Component* c : net)
				{
					cout  << fixed << setprecision(2) << c -> get_voltage() << "  " 
					<< fixed << setprecision(2)  << c -> get_current() << "  ";
					//Varför blir krets 1 batteriets voltage 23.96 ?
				}
				cout << endl;
			}
	}
	
	// Krets 1
	/*for (int i = 0; i < outputs; ++i)
	{
		for (int j = 0; j < iterations; ++j)
		{
			for (Component* c : net)
			{
				c -> update(dt);

				if (j == 0 && c == net.at(0))
				{
					cout  << fixed << setprecision(2) << c -> get_voltage() << "  " 
					<< fixed << setprecision(2)  << c -> get_current() << "  ";
				}
			}			
		}
		
		for (Component* c : net)
		{	if (c != net.at(0))
			{
				cout << fixed << setprecision(2) << c -> get_voltage() << "  " 
				<< fixed << setprecision(2)  << c -> get_current() << "  ";
			}
		}
		
		cout << endl;
	}*/
}






