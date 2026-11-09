#pragma once
#include <array>

class Block;

class Board {
    private:
        static constexpr int ROW = 20;
        static constexpr int COL = 10;
        std::array<std::array<int,COL>,ROW> grid;
    public:
        Board();
        void ResetBoard();
        bool IsInside(int row,int col) const;
        bool IsCellEmpty(int row,int col) const;
        int GetCell(int row,int col) const;
        int ClearFullRows();
        void PlaceBlock(const Block& block);
        const std::array<std::array<int, COL>, ROW>& GetGrid() const;
};