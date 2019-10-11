// SoundSynthesizer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "olcNoiseMaker.h"

// Converts frequency (Hz) to angular velocity
double w(double dHertz)
{
	return dHertz * 2.0 * PI;
}

double osc(double dHertz, double dTime, int nType)
{

	switch (nType)
	{
	case 0: // Sine Wave
		return sin(w(dHertz) * dTime);
	case 1: // Square Wave
		return sin(w(dHertz) * dTime) > 0.0 ? 1.0 : -1.0;
	case 2: // Triangle Wave
		return asin(sin(w(dHertz) * dTime)) * 2.0 / PI;
	case 3: // Saw wave (analogue / warm / slow)
	{
		double dOutput = 0.0;

		for (double n = 1.0; n < 100.0; n++)
			dOutput += (sin(n * w(dHertz) * dTime)) / n;

		return dOutput * (2.0 / PI);
	}
	case 4: // Saw Wave (optimised / harsh / fast)
		return (2.0 / PI) * (dHertz * PI * fmod(dTime, 1.0 / dHertz) - (PI / 2.0));
	default:
		return 0.0;
	}
}

atomic<double> dFrequencyOutput = 0.0;
double dOctaveBaseFrequency = 110.0; // A2
double d12thRootOf2 = pow(2.0, 1.0 / 12.0);

double MakeNoise(double dTime)
{
	double dOutput = osc(dFrequencyOutput, dTime, 1);
	
	return dOutput * 0.5;

	/*
	if (dOutput > 0.0)		return 0.2;
	else					return -0.2;
	*/
}

int main()
{
    std::cout << "Synthesizer Tutorial" << endl;

	// Get all sound hardware
	vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

	// Display findings
	for (auto d : devices) wcout << "Found Output Device:" << d << endl;

	// Create sound machine!!
	olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

	// Link noise function with sound machine
	sound.SetUserFunction(MakeNoise);

	double dOctaveBaseFrequency = 110.0; // A2
	double d12thRootOf2 = pow(2.0, 1.0 / 12.0);

	while (1)
	{
		// Add a keyboard like a piano

		bool bKeyPressed = false;
		for (int k = 0; k < 15; k++)
		{
			if (GetAsyncKeyState((unsigned char)("ZSXCFVGBNJMK\xbcL\xbe\xbf"[k])) & 0x8000)
			{
				dFrequencyOutput = dOctaveBaseFrequency * pow(d12thRootOf2, 12);
				bKeyPressed = true;
			}
		}

		if (!bKeyPressed)
		{
			dFrequencyOutput = 0.0;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
