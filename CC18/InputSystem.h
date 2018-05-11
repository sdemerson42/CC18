#pragma once

#include "ISystem.h"

class InputSystem : public ISystem
{
public:
	InputSystem(CCState *state) :
		ISystem{ state }
	{}
	void update() override;
};