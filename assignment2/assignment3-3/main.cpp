# include <iostream>
# include <string.h>
# include <stdlib.h>
# include "Neuron.h"
using namespace std;
void layer_print(Neuron* L_h)//fuct for printing layer neurno info
{
	Neuron* Cur = L_h;//Cur is Layer head point
	int value;
	value = Cur->Value;
	while (Cur != NULL)//loop layer
	{
		cout << Cur->Value;//print layer value
		if (Cur->RightNeuron == NULL)//if Right neuro is broken 
		{
			break;//break
		}
		else//if there is Right Neuron
		{
			cout << " ";
			if (Cur->op_deicde() == NULL)
			{
				break;
			}
			else//printing Neuron
			{
				cout << Cur->op_deicde();//cout neuron operation info
				if (Cur->op_deicde() == '+')//if +
				{
					value = value + Cur->RightNeuron->Value;
				}
				else if (Cur->op_deicde() == '-')//if -
				{
					value = value - Cur->RightNeuron->Value;
				}
				else if (Cur->op_deicde() == '*')//if *
				{
					value = value * Cur->RightNeuron->Value;
				}
				else if (Cur->op_deicde() == '/')//if /
				{
					value = value / Cur->RightNeuron->Value;
				}
			}
		}
		Cur = Cur->RightNeuron;
	}
	cout << " = ";
	if (Cur->Value == L_h->Value)
	{
		cout << Cur->Value<<endl;
	}
	else
	{
		cout << value << endl;
	}
}
int main(void)
{
	Neuron* Cur = NULL;
	Neuron* tmp = NULL;
	int rnd;
////////////////////////step 1///////////////////////////
	/////////////Layer1
	char Op[6][4];
	strcpy(Op[0], "add");
	Neuron N1(9, Op[0]);//////9
	strcpy(Op[1], "div");
	Neuron N2(5, Op[1]);//////5
	strcpy(Op[2], "add");
	Neuron N3(1, Op[2]);//////1
	/////////////Layer2
	strcpy(Op[3], "mul");
	Neuron N4(0, Op[3]);//////0
	strcpy(Op[4], "sub");
	Neuron N5(3, Op[4]);//////3
	strcpy(Op[5], "div");
	Neuron N6(7, Op[5]);//////7
	/////////////Layer 3
	Neuron N7(6, NULL);//////6
	Neuron N8(2, NULL);//////2
	Neuron N9(4, NULL);//////4
	////////////link neuron
	N1.RightNeuron = &N4;//N1 = 9 N4 = 0
	N4.RightNeuron = &N7;//N4 = 0 N7 = 6
	N1.DownNeuron = &N2;// N1 = 9 N2 = 5
	N2.RightNeuron = &N5;//N2 = 5 N5 = 3
	N5.RightNeuron = &N8;//N5 = 3 N8 = 2
	N2.DownNeuron = &N3;// N2 = 5 N3 = 1
	N3.RightNeuron = &N6;//N3 = 1 N6 = 7
	N6.RightNeuron = &N9;//N6 = 7 N9 = 4
////////////////////////End of step 1 ///////////////////////////
		srand(1);
//////////////////////step 2 & 3 //////////////////////////
	for (int i = 0; i < 2; i++)//loop for make random number
	{//if rnd ==0 that neuron break
		rnd = rand() % 10;
		N1.broken(rnd);//0~10 random number 
		rnd = rand() % 10;
		N2.broken(rnd);//0~10 random number 
		rnd = rand() % 10;
		N3.broken(rnd);//0~10 random number 
		rnd = rand() % 10;
		N4.broken(rnd);//0~10 random number 
		rnd = rand() % 10;
		N5.broken(rnd);//0~10 random number 
		rnd = rand() % 10;
		N6.broken(rnd);//0~10 random number
		rnd = rand() % 10;
		N7.broken(rnd);//0~10 random number 
		rnd = rand() % 10;
		N8.broken(rnd);//0~10 random number 
		rnd = rand() % 10;
		N9.broken(rnd);//0~10 random number 
	}
	
/////////////////////End of step 2 & 3///////////////////
	Cur = &N1;
	while (Cur != NULL)
	{
		layer_print(Cur);
		Cur = Cur->DownNeuron;
	}
	return 0;
}