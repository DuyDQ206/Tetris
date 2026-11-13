#pragma once
#include "raylib.h"

enum class BlockType;
// struct SpriteInfo {
//     Rectangle source; 
// };

class VisualManager {
    private:
        Texture2D BlockTexture;
        Color BackgroundColor;
        Color GridColor;
        Color GhostColor;
        Rectangle Sprite[8][4]; // stores sprites of each Block with 8 BlockType and 4 Rotations 
        void InitializeSprites(); 
    public:
        VisualManager();
        bool LoadAssets();
        void UnloadAssets();
        const Texture2D& GetBlockTexture() const;
        Rectangle GetBlockSourceRectangle(BlockType type,int rotation) const;
        Color GetBackgroundColor() const;
        Color GetGridColor() const;
        Color GetGhostColor() const;
};