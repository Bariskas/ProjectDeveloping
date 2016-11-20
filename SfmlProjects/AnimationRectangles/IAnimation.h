#pragma once
#include "stdafx.h"

class IAnimation
{
public:
	virtual ~IAnimation() = 0;
	virtual bool IsExpired() const = 0;
	virtual void UpdateRectangles(RecVector&) = 0;
	virtual void Initialize() = 0;
public:

};

