#include "Block.h"


Block::Block() {
    Row = 0;
    Col = 4;
    Rotation = 0;
    Type = BlockType::None;
    InitializeCells();
}
Block::Block(BlockType T) 
    : Type(T), Row(0), Col(4), Rotation(0) {
    this->InitializeCells();
}
int Block::GetID() const {
    return static_cast<int>(this->Type);
}
void Block::InitializeCells() {
    switch(this->Type) {
        case BlockType::T: 
            this->cells = {{{0,0},{0,1},{0,2}
                                ,{1,1}}};
            break;
        case BlockType::I: 
            this->cells = {{{0,0},
                            {1,0},
                            {2,0},
                            {3,0}}};
            break;
        case BlockType::O: 
            this->cells = {{{0,0},{0,1},
                            {1,0},{1,1}}};
            break;
        case BlockType::J: 
            this->cells = {{      {0,0},
                                  {1,0},
                            {2,1},{2,0}}};
            break;
        case BlockType::L:
            this->cells = {{{0,0},
                            {1,0},
                            {2,0},{2,1}}};
            break;
        case BlockType::S:
            this->cells = {{      {0,0},{0,1},
                            {1,1},{1,0}}};
            break;
        case BlockType::Z:
            this->cells = {{{0,0},{0,1}
                                 ,{1,1},{1,2}}};
            break;
        default:
            this->cells = {};
    }    
}
int Block::GetRow() const {
    return this->Row;
}
int Block::GetCol() const {
    return this->Col;
}
int Block::GetRotation() const {
    return this->Rotation;
}
BlockType Block::GetType() const {
    return this->Type;
}
std::array<Cell,4> Block::GetCellPositions() const {
    std::array<Cell,4> TemporaryCells = this->cells;
    for(int i=0;i<4;i++) {
        TemporaryCells[i].c += this->Col;
        TemporaryCells[i].r += this->Row;
    }
    return TemporaryCells;
}
void Block::Rotate() {
    int N = 0;
    switch(Type) {
        case BlockType::I:
            N = 4;
            break;
        case BlockType::J:
        case BlockType::L:
        case BlockType::S:
        case BlockType::Z:
        case BlockType::T:
            N = 3;
            break;
        case BlockType::O:
            return;
        default:
            return;
    }
    for(int i=0;i<4;i++) {
        int OldRow = cells[i].r;
        int OldCol = cells[i].c;
        cells[i].r = OldCol;
        cells[i].c = N - 1 - OldRow;
    }
    this->Rotation = (this->Rotation + 1) % 4;
}
void Block::Move(int rowOffset,int colOffset) {
    this->Col += colOffset;
    this->Row += rowOffset;
}
void Block::Reset() {
    this->InitializeCells();
    this->Col=4;
    this->Row=0;
    this->Rotation = 0;
}