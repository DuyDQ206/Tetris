#include "InputHandler.h"
#include "GameLogic.h"

/* Some important functions:
1.IsKeyPressed(KEY_A): kiem tra xem phim A co duoc nhan khong
2.IsKeyDown(KEY_A): kiem tra xem phim A co dang duoc de xuong khong
3.IsKeyReleased(KEY_A): kiem tra xem phim A co phai vua duoc tha ra khong
4.IsKeyUp(KEY_A): kiem tra xem phim A hien khong duoc nhan

*/

void HandleInput(GameLogic& game) {
    if(game.IsGameOver()) {
        HandleRestart(game);
        return;
    }
    HandleMovement(game);
    HandleRotation(game);
    HandleHardDrop(game);
}
void HandleMovement(GameLogic& game) {
    if(IsKeyPressed(KEY_A)||IsKeyPressed(KEY_LEFT)) {
        game.MoveLeft();
    }
    if(IsKeyPressed(KEY_D)||IsKeyPressed(KEY_RIGHT)) {
        game.MoveRight();
    }
    if(IsKeyPressed(KEY_S)||IsKeyPressed(KEY_DOWN)) {
        game.MoveDown();
    }
}
void HandleRotation(GameLogic& game) {
    if(IsKeyPressed(KEY_W)||IsKeyPressed(KEY_UP)) {
        game.RotateBlock();
    }
}
void HandleHardDrop(GameLogic& game) {
    if(IsKeyPressed(KEY_SPACE)) {
        game.HardDrop();
    }
}
void HandleRestart(GameLogic& game) {
    if(IsKeyPressed(KEY_R)) {
        game.RestartGame();
    }
}