#pragma once
#include "stdafx.h"
#include "Rectangles.h"
class IAnimation
{
public:
	virtual ~IAnimation() {};
	virtual bool IsExpired() const = 0;
	virtual void UpdateRectangles() = 0;
	virtual void Initialize() = 0;
public:

};

