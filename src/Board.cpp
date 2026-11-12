#include "Board.h"
#include "Block.h"

Board::Board() {
    ResetBoard();
}

void Board::ResetBoard() {
    for(int r=0;r<ROW;r++) {
        for(int c=0;c<COL;c++) {
            grid[r][c]=0;
        }
    }
}
bool Board::IsInside(int row,int col) const {
    if((row>=0&&row<ROW)&&(col>=0&&col<COL)) 
        return true;
    return false;
}
bool Board::IsCellEmpty(int row,int col) const {
    if(!IsInside(row,col)) 
        return false;
    return grid[row][col]==0 ;
}
int Board::GetCell(int row,int col) const {
    if(IsInside(row,col)) 
        return grid[row][col];
    return -1;
}
int Board::ClearFullRows() {
    int count = 0;
    int row = ROW-1;
    while(row>=0) {
        int Full = 0;
        for(int col=0;col<COL;col++) {
            if(!IsCellEmpty(row,col))
                Full += 1;
        }
        if(Full==COL) {
            count += 1;
            for(int r = row;r>0;r--)
                grid[r] = grid[r-1];
            grid[0].fill(0);
        }
        else row -=1;
    }
    return count;
}
bool Board::PlaceBlock(const Block& block) {
    std::array<Cell,4> positions = block.GetCellPositions();
    for(const auto& position : positions) {
        if(!IsInside(position.r, position.c))
            return false;
    }
    int id = block.GetID();
    for(const auto& position : positions) {
        int row = position.r;
        int col = position.c;
        grid[row][col] = id;
    }
    return true;
}
const std::array<std::array<int, Board::COL>, Board::ROW>& Board::GetGrid() const {
    return grid;
}