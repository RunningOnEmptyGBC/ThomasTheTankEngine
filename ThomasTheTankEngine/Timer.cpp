#include "Timer.h"
#include<SFML/System/Clock.hpp>


sf::Time Timer::GetTime()
{
	return sf::Time();
}

Timer::Timer()
{
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		updateGame(elapsed);
	}
}
sf::Time GetTime()
{
	return clock.getElapsedTime();
}

Timer::~Timer()
{
}
