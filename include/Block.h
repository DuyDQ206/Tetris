#pragma once
#include <array>

enum class BlockType {
    None = 0,
    T = 1,
    I = 2,
    O = 3,
    J = 4,
    L = 5,
    S = 6,
    Z = 7,
};

struct Cell {
    int r, c;
};

class Block {
    private:
        BlockType Type;
        int Row,Col;
        int Rotation;
        std::array<Cell,4> cells;
        void InitializeCells();
    public:
        Block(BlockType T);
        int GetRow() const;
        int GetCol() const;
        int GetRotation() const;
        int GetID() const;
        BlockType GetType() const;
        std::array<Cell,4> GetCellPositions() const;
        void Rotate();
        void Move(int rowOffset=0,int colOffset=0);
        void Reset();
};