#pragma once
class Timer
{
private:
	sf::Clock clock;
public:
	sf::Time GetTime();
	Timer();
	~Timer();
};

