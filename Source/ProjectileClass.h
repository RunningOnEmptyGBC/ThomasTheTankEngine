#pragma once
#include "BaseObjectClass.h"
class ProjectileClass :
	public BaseObjectClass
{
public:
	ProjectileClass(BaseObjectClass host);
	void UpdatePos();
	void Update();
	~ProjectileClass();
};

