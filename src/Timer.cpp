#include "Timer.h"

// Initializing sInstance to NULL
Timer* Timer::sInstance = NULL;

Timer* Timer::Instance() {
	// Create a new instance of Timer if no instance was created before
	if (sInstance == NULL)
		sInstance = new Timer();

	return sInstance;
}

void Timer::Release() {
	delete sInstance;
	sInstance = NULL;
}

Timer::Timer() {
	// Using Reset to initialize all the values beside mTimeScale
	Reset();
	mTimeScale = 1.0f;
}

Timer::~Timer() {

}

void Timer::Reset() {
	mStartTicks = SDL_GetTicks();
	mElapsedTicks = 0;
	mDeltaTime = 0.0f;
}

float Timer::DeltaTime() {
	return mDeltaTime;
}

void Timer::TimeScale(float time) {
	mTimeScale = time;
}

float Timer::TimeScale() {
	return mTimeScale;
}

void Timer::Update() {
	mElapsedTicks = SDL_GetTicks() - mStartTicks;
	mDeltaTime = mElapsedTicks * 0.001f; // Convert ticks(ms) to float(sec)
}