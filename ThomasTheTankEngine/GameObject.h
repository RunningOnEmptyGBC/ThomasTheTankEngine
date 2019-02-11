#pragma once
#include<vector>
class GameObject {
public:
	GameObject() { parent = nullptr; }
	~GameObject(void);
	void SetTransform(const Matrix4 &matrix);
	Matrix4 GetTransform();
	Matrix4 GetWorldTransform();
	void SetParent(GameObject& p);
	void AddChild(GameObject* s);
	virtual void Update(float msec);
protected:
	GameObject* parent;
	Matrix4 worldTransform;
	Matrix4 transform;
	std::vector<GameObject*> children;
};