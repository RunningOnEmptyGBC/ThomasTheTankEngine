#include "BaseObjectClass.h"
using namespace std;


BaseObjectClass::BaseObjectClass()
{
	Name = "You really should have given a Name";
	Type = Player;
	position.x = 0;
	position.y = 0;
	position.z = 0;
}

BaseObjectClass::BaseObjectClass(std::string name)
{
	Name = name;
	position.x = 0;
	position.y = 0;
	position.z = 0;
	
}

void BaseObjectClass::setType(int type)
{
	switch (type)
	{
	case 1:
		type = Player;
		break;
	case 2:
		type = Enemie;
		break;
	case 3:
		type = Projectile;
		break;
	case 4: 
		type = Obstacle;
		break;
	default:
		break;
	}
}
//MoveChildren should move all the children of an object, this does not work and i dont know why
void BaseObjectClass::MoveChildren(int direction, int pos)
{
	//direction = x , y, or z
	//pos = + or -
	if (pos == 1) {
		
	switch (direction)
	{
	case 1:
		for (BaseObjectClass x : Children) {
			
			x.MoveForward(1);
		}
		break;
	case 2:
		for (auto x : Children) {
			x.MoveForward(1);
		}
		break;
	case 3:
		for (auto x : Children) {
			x.position.z++;
		}
		break;
	default:
		break;
	}
	
	}
	else {
		switch (direction)
		{
		case 1:
			for (auto x : Children) {
				x.MoveForward(0);
			}
			break;
		case 2:
			for (auto x : Children) {
				x.MoveForward(0);
			}
			break;
		case 3:
			for (auto x : Children) {
				x.position.z--;
			}
			break;
		default:
			break;
		}
	}
	
	
}

//Movment on the x axis, 1 for right 0 for left, should call MoveChildren after every move
void BaseObjectClass::MoveRight(int direction)
{
	if (direction == 1) {
		position.x++;
		MoveChildren(1,1);
	}
	else {
		position.x--;
		MoveChildren(1, 0);
	}
}

void BaseObjectClass::MoveForward(int direction)
{
	
	if (direction == 1) {
		//cout << "Heck";
		position.y++;
		MoveChildren(2, 1);
	}
	else {
		position.y--;
		MoveChildren(2,0);
	}
}

void BaseObjectClass::PrintPos()
{
	cout << Name << ": [" << position.x << "," << position.y << "," << position.z << "]" << endl;
}

void BaseObjectClass::PrintChildPos()
{
	for (BaseObjectClass x : Children) {

		cout << Name <<"'s child " << x.Name << ": [" << x.position.x << "," << x.position.y << "," << x.position.z << "]" << endl;
	}
}


BaseObjectClass::~BaseObjectClass()
{
}
