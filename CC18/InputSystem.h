#pragma once

#include "ISystem.h"
#include "SFML\Graphics.hpp"

class Bubble;

class InputSystem : public ISystem
{
public:
	InputSystem(CCState *state) :
		ISystem{ state }
	{}
	void update() override;
private:
	
};