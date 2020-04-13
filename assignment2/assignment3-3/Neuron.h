#pragma once
# include <iostream>
# ifndef _NEURON_H
# define _NEURON_H
class Neuron//define Neuron class
{
public:
	int Value;//for keep value
	char* Op;//for keep operation
	Neuron* RightNeuron;//for keep Right Neuron pointer
	Neuron* DownNeuron;//for keep Down Newuron pointer
public:
	Neuron(int v, char* op);//set Neuron
	~Neuron();
	char op_deicde();//operation decide
	void broken(int rnd);//for break liking info of neuron
};
# endif;