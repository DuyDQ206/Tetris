#pragma once
#include "Block.h"
#include "Board.h"
#include<random>
class GameLogic {
    private:
        Board board;
        Block currentBlock;
        Block nextBlock;
        bool gameOver;
        float gravityTimer; // time from the last drop
        float gravityInterval; // time between two automatic drops

        // randomizer 
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> dis;
    public:
        GameLogic();

        // Game management
        void StartGame();
        void RestartGame();
        bool IsGameOver() const;

        // Block management
        Block GenerateRandomBlock();
        void SpawnNewBlock();
        const Block& GetCurrentBlock() const;
        const Block& GetNextBlock() const;

        // Data access
        const Board& GetBoard() const;


        // Movement
        bool IsValidPosition(const Block& block) const;
        bool CanMoveDown() const;   
        bool CanMoveLeft() const;
        bool CanMoveRight() const;
        
        void MoveLeft();
        void MoveRight();
        void MoveDown();
        void RotateBlock();
        void HardDrop();

        // Block replacement
        void LockCurrentBlock();
        void HandleBlockLanding();
        
        // Game update
        void Update(float deltaTime);
        void UpdateGravity(float deltaTime);
};