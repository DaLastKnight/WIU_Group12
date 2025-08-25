#pragma once
#include <iostream>
class Materials
{
protected:
	int materialAmount;
	std::string materialName;

public:
	Materials();
	~Materials();

	int getMaterialAmount() const;
	void setMaterialAmount(int total);
};

