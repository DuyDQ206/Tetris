#include "VisualManager.h"
#include "raylib.h"
#include "Block.h"


VisualManager::VisualManager() : BlockTexture{},BackgroundColor{},
    GridColor{},GhostColor{},Sprite{} {
}
bool VisualManager::LoadAssets() {
    BlockTexture = LoadTexture("assets/texture/blocks.png");
    if(!IsTextureValid(BlockTexture)) return false;
    InitializeSprites();
    BackgroundColor = {21, 25, 35, 255};
    GridColor = {52, 59, 73, 255};
    GhostColor = {170, 180, 196, 100};
    return true;
}
void VisualManager::InitializeSprites() {
   // None
   Sprite[0][0] = Sprite[0][1] = Sprite[0][2] = Sprite[0][3] = {};
   // T
   Sprite[1][0] = {16,44,12,12};
   Sprite[1][1] = {32,44,12,12};
   Sprite[1][2] = {44,44,12,12};
   Sprite[1][3] = {56,44,12,12};
   // I
   Sprite[2][0] = Sprite[2][2] = {80,40,16,16};
   Sprite[2][1] = Sprite[2][3] = {96,40,16,16};
   // O
   Sprite[3][0] = Sprite[3][1] = Sprite[3][2] = Sprite[3][3] = {52,32,8,8};
   // J
   Sprite[4][0] = {76,16,12,12};
   Sprite[4][1] = {88,12,12,12};
   Sprite[4][2] = {100,16,12,12};
   Sprite[4][3] = {116,16,12,12};
   // L
   Sprite[5][0] = {12,16,12,12};
   Sprite[5][1] = {24,12,12,12};
   Sprite[5][2] = {36,16,12,12};
   Sprite[5][3] = {52,16,12,12};
   // S
   Sprite[6][0] = Sprite[6][2] = {80,32,12,12};
   Sprite[6][1] = Sprite[6][3] = {92,28,12,12};
   // Z
   Sprite[7][0] = Sprite[7][2] = {16,28,12,12};
   Sprite[7][1] = Sprite[7][3] = {28,28,12,12};
}
void VisualManager::UnloadAssets() {
    if(IsTextureValid(BlockTexture)) {
        UnloadTexture(BlockTexture);
        BlockTexture = {};
    }
    BackgroundColor = {};
    GridColor = {};
    GhostColor = {};
    for(auto& row : Sprite) {
        for(auto& rect : row) {
            rect = {};
        }
    }
}
const Texture2D& VisualManager::GetBlockTexture() const {
    return BlockTexture;
}
Rectangle VisualManager::GetBlockSourceRectangle(BlockType type,int rotation) const {
    int id = static_cast<int>(type);
    if(id<0||id>7||rotation<0||rotation>=4) return {};
    return Sprite[static_cast<int>(type)][rotation];
}
Color VisualManager::GetBackgroundColor() const {
    return BackgroundColor;
}
Color VisualManager::GetGridColor() const {
    return GridColor;
}
Color VisualManager::GetGhostColor() const {
    return GhostColor;
}