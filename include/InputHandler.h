#pragma once
#include "raylib.h"

class GameLogic;

void HandleInput(GameLogic& game);
void HandleMovement(GameLogic& game);
void HandleRotation(GameLogic& game);
void HandleHardDrop(GameLogic& game);
void HandleRestart(GameLogic& game);