#include "GameEntity.h"

GameEntity::GameEntity(Vector2 pos) {
	mPos = pos;
	mRotation = 0.0f;
	mActive = true;
	mParent = NULL;
	mScale = VEC2_ONE;
}

GameEntity::~GameEntity() {
	mParent = NULL;
}

void GameEntity::Pos(Vector2 pos) {
	mPos = pos;
}

Vector2 GameEntity::Pos(SPACE space) {
	if (space == local || mParent == NULL)
		return mPos;

	Vector2 parentScale = mParent->Scale(world);
	Vector2 rotPos = RotateVector(mPos, mParent->Rotation(local));
	
	return mParent->Pos(world) + Vector2(rotPos.x * parentScale.x, rotPos.y * parentScale.y);
}

void GameEntity::Rotation(float r) {
	mRotation = r;

	// Wraps the angle between 0 and 360 degrees, addition and subtraction is sed to avoid snapping
	// Updated to deal with degrees higher than 360 and -360
	if (mRotation > 360.0f) {
		int mul = mRotation / 360;
		mRotation -= 360.0f * mul;
	} else if (mRotation < 0.0f) {
		int mul = (mRotation / 360) - 1;
		mRotation -= 360.0f * mul;
	}
}

float GameEntity::Rotation(SPACE space) {
	if (space == local || mParent == NULL)
		return mRotation;

	return mParent->Rotation(world) + mRotation;
}

void GameEntity::Scale(Vector2 scale) {
	mScale = scale;
}

Vector2 GameEntity::Scale(SPACE space) {
	if (space == local || mParent == NULL)
		return mScale;

	Vector2 scale = mParent->Scale(world);
	scale.x *= mScale.x;
	scale.y *= mScale.y;

	return scale;
}

void GameEntity::Active(bool active) {
	mActive = active;
}

bool GameEntity::Active() {
	return mActive;
}

void GameEntity::Parent(GameEntity* parent) {
	// If the parent is removed, The Position/Rotation/Scale are the GameEntity's world values, to keep the object looking the same after the removal of the parent;
	if (parent == NULL) {
		mPos = Pos(world);
		mScale = Scale(world);
		mRotation = Rotation(world);
	} else {
		// If the object already has a parent, remove the current parent to get it ready to be the child for the new parent
		if (mParent != NULL)
			Parent(NULL);

		Vector2 parentScale = parent->Scale(world);

		// Setting the local position to be relative to the new parent (while maintaining the same world position as before)
		Vector2 normalBack(Pos(world) - parent->Pos(world));
		mPos = RotateVector(normalBack, (-parent->Rotation(world)));
		mPos.x /= parentScale.x;
		mPos.y /= parentScale.y;

		// Setting the local rotation to be relative to the new parent (while maintaining the same world rotation as before)
		mRotation = mRotation - parent->Rotation(world);

		// Setting the new scale to be relative to the new parent (while maintaining the same world scale as before)
		mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
	}

	mParent = parent;
}

GameEntity* GameEntity::Parent() {
	return mParent;
}

void GameEntity::Translate(Vector2 vec) {
	mPos += vec;
}

void GameEntity::Rotate(float amount) {
	mRotation += amount;
}

void GameEntity::Update() {

}

void GameEntity::Render() {

}