#include "GameLogic.h"
#include "Block.h"
#include "Board.h"
#include<random>

GameLogic::GameLogic() : currentBlock(BlockType::None), 
                        nextBlock(BlockType::None),
                        gameOver(false),gravityTimer(0.0f),
                        gravityInterval(1.0f), gen(rd()),dis(1,7) {}

// Game management
void GameLogic::StartGame() {
    board.ResetBoard();
    gameOver = false;
    gravityTimer = 0.0f;
    currentBlock = GenerateRandomBlock();
    nextBlock = GenerateRandomBlock();
}
void GameLogic::RestartGame() {
    StartGame();
}
bool GameLogic::IsGameOver() const {
    if(gameOver) return true;
    return false;
}

// Block management
Block GameLogic::GenerateRandomBlock() {
    int randomId = dis(gen);
    BlockType Type = static_cast<BlockType>(randomId);
    return Block(Type);
}
void GameLogic::SpawnNewBlock() {
    currentBlock = nextBlock;
    if(!IsValidPosition(currentBlock)) {
        gameOver = true;
        return;
    }
    nextBlock = GenerateRandomBlock();
}
const Block& GameLogic::GetCurrentBlock() const {
    return currentBlock;
}
const Block& GameLogic::GetNextBlock() const {
    return nextBlock;
}

// Data access
const Board& GameLogic::GetBoard() const {
    return board;
}


// Movement
bool GameLogic::IsValidPosition(const Block& block) const {
    const auto& positions = block.GetCellPositions();
    for(const auto& position : positions) {
        if(!board.IsInside(position.r,position.c)) return false;
        if(!board.IsCellEmpty(position.r,position.c)) return false;
    }
    return true;
}
bool GameLogic::CanMoveDown() const {
    Block temp = currentBlock;
    temp.Move(1,0);
    if(IsValidPosition(temp)) {
        return true;
    }
    return false;
}   
bool GameLogic::CanMoveLeft() const {
    Block temp = currentBlock;
    temp.Move(0,-1);
    if(IsValidPosition(temp)) {
        return true;
    }
    return false;
}
bool GameLogic::CanMoveRight() const {
    Block temp = currentBlock;
    temp.Move(0,1);
    if(IsValidPosition(temp)) {
        return true;
    }
    return false;
}
        
void GameLogic::MoveLeft() {
    if(CanMoveLeft()) {
        currentBlock.Move(0,-1);
    }
}
void GameLogic::MoveRight() {
    if(CanMoveRight()) {
        currentBlock.Move(0,1);
    }
}
void GameLogic::MoveDown() {
    if(CanMoveDown()) {
        currentBlock.Move(1,0);
    }
}
void GameLogic::RotateBlock() {
    Block temp = currentBlock;
    temp.Rotate();
    if(IsValidPosition(temp)) {
        currentBlock.Rotate();
    }
}
void GameLogic::HardDrop() {
    while(true) {
        Block temp = currentBlock;
        temp.Move(1,0);
        while(CanMoveDown()) {
            MoveDown();
        }
        HandleBlockLanding();
    }
}

// Block replacement
void GameLogic::LockCurrentBlock() {
    board.PlaceBlock(currentBlock);
}
void GameLogic::HandleBlockLanding() {
    LockCurrentBlock();
    board.ClearFullRows();
    SpawnNewBlock();
}
        
// Game update
void GameLogic::Update(float deltaTime) {
    UpdateGravity(deltaTime);
}
void GameLogic::UpdateGravity(float deltaTime) {
    gravityTimer += deltaTime;
    if(gravityTimer < gravityInterval) return;
    else {
        if(CanMoveDown()) {
            MoveDown();
        }
        else HandleBlockLanding();
    }
    gravityTimer -= gravityInterval;
}