#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "simulate.h"

using namespace std;

int main(int argc, char *argv[])
{
	int iterations, outputs;
	double dt, voltage;

	try
	{
		if (argc == 5)
		{
			iterations = stoi(argv[1]);
			outputs = stoi(argv[2]);
			dt = stod(argv[3]);
			voltage = stod(argv[4]);
		}
		else
		{
			throw 5;
		}
	
	

		
		//Krets 1
		vector<Component*> net;
		Connection A, B, Q124, Q23;
		net.push_back(new Battery("Bat", voltage, B, A));
		net.push_back(new Resistor("R1", 6.0, Q124, A));
		net.push_back(new Resistor("R2", 4.0, Q23, Q124));
		net.push_back(new Resistor("R3", 8.0, B, Q23));
		net.push_back(new Resistor("R4", 12.0, B, Q124));
		simulate(net, iterations, outputs, dt);
		cout << endl;

		// Krets 2
		vector<Component*> net1;
		Connection P, R, N, L;
		net1.push_back(new Battery("Bat", voltage, N, P));
		net1.push_back(new Resistor("R1", 150.0, L, P));
		net1.push_back(new Resistor("R2", 50.0, R, P));
		net1.push_back(new Resistor("R3", 100.0, L, R));
		net1.push_back(new Resistor("R4", 300.0, N, L));
		net1.push_back(new Resistor("R5", 250.0, N, R));
		simulate(net1, iterations, outputs, dt);
		cout << endl;

		//Krets 3
		vector<Component*> net2;
		Connection E, F, G, H;
		net2.push_back(new Battery("Bat", voltage, G, E));
		net2.push_back(new Resistor("R1", 150.0, H, E));
		net2.push_back(new Resistor("R2", 50.0, F, E));	
		net2.push_back(new Capacitor("C3", 1.0, H, F));
		net2.push_back(new Resistor("R4", 300.0, G, H));
		net2.push_back(new Capacitor("C5", 0.75, G, F));
		simulate(net2, iterations, outputs, dt);

		for (Component* c : net)
		{
			delete c;
		}
		for (Component* c : net1)
		{
			delete c;
		}
		for (Component* c : net2)
		{
			delete c;
		}
	}
	catch(int e)
	{
		cout << "Fel antal argument";
	}
	return 0;
}