#pragma once

enum WaveTableType
{
	wtSine = 0,
	wtSquare = 1,
	wtSawtooth = 2,
	wtTriangle = 3,
	wtExperimental = 4
};

struct WaveTable
{
	WaveTable(WaveTableType type);
	WaveTable(WaveTableType type, double shift);
	~WaveTable();

	void generateSineTable();
	void generateSquareTable();
	void generateSawtoothTable();
	void generateTriangleTable();
	void generateExperimentalTable();
	void normalizeTable();

	double *samples;
	int sampleCount;
	double harmonicFrequency;
	double phaseShift;

	typedef void (WaveTable::*tableGeneratorFunc)();
	tableGeneratorFunc generatorFuncs[5];
};