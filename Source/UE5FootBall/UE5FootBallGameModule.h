#pragma once

#include "CookBookStyle.h"

class FUE5FootBallGameModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		FCookBookStyle::Initialize();
	};
	virtual void ShutdownModule() override
	{
		FCookBookStyle::ShutDown();
	};
};
