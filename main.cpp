#include "raylib.h"

struct Player
{
    Vector2 pos;
    int vel_y;
};

const int SWIDTH = 1500;
const int SHEIGHT = 800;

int main()
{
    // float dt = GetFrameTime();
    float dt = 1;

    float acceleration = 1;
    InitWindow(SWIDTH, SHEIGHT, "BVR1");
    SetTargetFPS(60);

    Player player{
        {SWIDTH / 2 + SWIDTH / 6, SHEIGHT / 2},
        {0}};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(player.pos.x, player.pos.y, 10, WHITE);

        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            player.pos.y -= (player.vel_y * dt);
            player.vel_y += acceleration;
        }
        else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            player.pos.y += (player.vel_y * dt);
            player.vel_y += acceleration;
        }
        else
        {
            player.vel_y = 0;
        }

        if (player.pos.y < 0)
        {
            player.pos.y = 0;
        }
        else if (player.pos.y > SHEIGHT)
        {
            player.pos.y = SHEIGHT;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}