/**
 * @file		Timer.cpp
 * @date		17-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Timer handler
 */
#pragma once

#include <SDL.h>

class Timer {

private:
	static Timer* sInstance;

	unsigned int mStartTicks;
	unsigned int mElapsedTicks;
	float mDeltaTime;
	float mTimeScale;

public:
	static Timer* Instance();
	static void Release();

	void Reset();
	float DeltaTime();

	void TimeScale(float time);
	float TimeScale();

	void Update();

private:
	Timer();
	~Timer();
};