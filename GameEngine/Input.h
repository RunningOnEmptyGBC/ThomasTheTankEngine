#pragma once
//#ifndef_INPUT_H_
//#define_INPUT_H_

class Input
{
public:
	Input();
	Input(const Input&);
	~Input();

	void Init();

	void KeyDown(unsigned int);
	void KeyUp(unsigned int);

	bool IsKeyDown(unsigned int);

private:
	bool m_keys[256];
};

//#endif