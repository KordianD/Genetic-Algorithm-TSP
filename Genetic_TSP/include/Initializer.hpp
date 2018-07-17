#pragma once

class Initializer
{
public:
	virtual ~Initializer() = default;
	virtual double getNumber() = 0;
};
