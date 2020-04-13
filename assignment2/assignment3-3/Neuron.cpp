# include "Neuron.h"
Neuron::Neuron(int v,char* op)//contructor of neuron class
{
	Value = v;//set value
	Op = op;//set operation
	RightNeuron = NULL;
	DownNeuron  = NULL;
}
Neuron::~Neuron()
{
}
void Neuron::broken(int rnd)//for breaking Neuron
{
	if (rnd == 0)//rnd == 0 neurong break
	{
		RightNeuron = NULL;
	}
}
char Neuron::op_deicde()//funct for operation decide because oepration value is string
{
	if (strcmp(Op, "add") == 0)//decide add
	{
		return '+';
	}
	else if(strcmp(Op, "sub") == 0)//decide sub
	{
		return '-';
	}
	else if (strcmp(Op, "mul") == 0)//decide mul
	{
		return '*';
	}
	else if (strcmp(Op, "div") == 0)//decide division
	{ 
		return '/';
	}
	else
	{ 
		return NULL;
	}
}