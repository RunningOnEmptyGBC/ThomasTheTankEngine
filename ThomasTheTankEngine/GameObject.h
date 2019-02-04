#pragma once
#include<vector>
class GameObject {
public:
	GameObject() { parent = nullptr; }
	~GameObject(void);
	void SetTransform(const Matrix4 &matrix) { transform = matrix; }
	Matrix4 GetTransform() { return transform; }
	Matrix4 GetWorldTransform() { return worldTransform; }
	void SetParent(GameObject& p) { parent = s; }
	void AddChild(GameObject* s);
	virtual void Update(float msec);
Protected:
	GameObject* parent;
	Matrix4 worldTransform;
	Matrix4 transform;
	std::vector<GameObject*> children;
};