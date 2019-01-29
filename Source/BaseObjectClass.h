#pragma once
#include <stdlib.h>  
#include <string> 
#include <stdio.h>
#include <iostream>
#include <vector>
//This class acts as the base for all object classes
//All objects should be dirived from this class

//Currently only supports one level of children,
//	once the MoveChildren function is functional it will support infinite levels

class BaseObjectClass
{
public:
	struct position {
	float x;
	float y;
	float z;
	};
	enum ObjectType { Player, Enemie, Projectile, Obstacle };
	std::string Name;
	ObjectType Type;
	position position;
	std::vector<BaseObjectClass> Children;
	//Model model;  //This is placeholder till real models are implimented
	
	BaseObjectClass();
	BaseObjectClass(std::string name);
	void setType(int type);
	void MoveChildren(int direction,int pos);
	void MoveRight(int direction);
	void MoveForward(int direction);
	void PrintPos();
	void PrintChildPos();
	~BaseObjectClass();
};

