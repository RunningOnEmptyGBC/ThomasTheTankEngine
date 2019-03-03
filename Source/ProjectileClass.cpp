#include "ProjectileClass.h"



ProjectileClass::ProjectileClass(BaseObjectClass host)
{
	position.x = host.position.x;
	position.y = host.position.y;
	position.z = host.position.z;
}

void ProjectileClass::UpdatePos()
{
	this->MoveForward(1);
}

void ProjectileClass::Update()
{
	UpdatePos();
}




ProjectileClass::~ProjectileClass()
{
}
