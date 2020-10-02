#ifndef PRO
#define PRO
#pragma once
#include <iostream>
using namespace std;

class R_P_S
{
	private:
		double random;
		bool win, tie;
		double player_choice;
	public:
		R_P_S()
		{
			random = 0;
			win = false;
			player_choice = 0;
			tie = false;
		}
		void set_user(double);
		void set_random();
		void test_win(double);
		void display();
		bool input_val(double);
		double get_random();
		bool get_Tie();
		bool get_Win();
		
		
};








#endif
