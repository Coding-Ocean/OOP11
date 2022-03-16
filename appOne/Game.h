#pragma once
#include <vector>
#include "VECTOR2.h"
class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	// UI
	void PushUI(class UIScreen* uiScreen);
	enum GameState
	{
		EGameplay,
		EPaused,
		EQuit
	};
	void SetState(GameState gameState) { mGameState = gameState; }
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	std::vector<class Actor*>mActors;
	std::vector<class SpriteComponent*>mSprites;

	// UI
	std::vector<class UIScreen*>mUIStack;
	GameState mGameState;

	// Update中フラッグ
	bool mUpdatingActors;
	std::vector<class Actor*> mPendingActors;

	//このGame固有の記述
public:
	void AddUfo(class Ufo* ufo);
	void RemoveUfo(class Ufo* ufo);
	std::vector<class Ufo*>& GetUfos() { return mUfos; }
	void SetShip(class Ship* ship) { mShip = ship; }
	class Ship* GetShip() { return mShip; }
private:
	std::vector<class Ufo*> mUfos;
	class Ship* mShip;
};

