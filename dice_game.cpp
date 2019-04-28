#include<iostream>
#include <cstdlib>
#include <ctime>

unsigned int random_integer()
{
	static bool is_seeded;
	
	if (!is_seeded) {
		std::srand(std::time(0));
		is_seeded = true;
	}
	return std::rand();
}
unsigned int roll_die()
{
	return (random_integer() % 6 + 1);
}

int main()
{
	unsigned int coins = 30;
	unsigned int pay, die1, die2, gain;

	while (coins > 0) {
		std::cout << "You have " << coins << " coins" << std::endl;
		std::cout << "Pay 0-3 coins: ";
		if (!(std::cin >> pay) || pay == 0) break;
		if (pay > 3 || pay > coins) continue;
		coins -= pay;
		die1 = roll_die();
		die2 = roll_die();
		std::cout << "Dice landed on: " << die1 << ' ' << die2 << std::endl;
		if (die1 == die2) {
			gain = pay * 3;
			coins += gain;
			std::cout << "You won " << gain << " coins" << std::endl;
		}
	}
	return 0;
}