#include "raylib.h"

struct Player
{
    Vector2 pos;
    int vel_y;
    bool alive;
};

struct Enemy
{
    Vector2 pos;
    Vector2 vel;
};

const int SWIDTH = 1500;
const int SHEIGHT = 800;

int main()
{
    // float dt = GetFrameTime();
    float dt = 1;

    float acceleration = 1;
    float chase_elasticity = 0.05;
    float run_elasticity = 0.25;
    float run_error = 10;
    InitWindow(SWIDTH, SHEIGHT, "BVR1");
    SetTargetFPS(60);

    Player player{
        {SWIDTH / 2 + SWIDTH / 6, SHEIGHT / 2},
        {0},
        {true}};

    Enemy enemy{
        {SWIDTH / 2, SHEIGHT / 2},
        {1, 0}};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(player.pos.x, player.pos.y, 10, WHITE);
        DrawCircle(enemy.pos.x, enemy.pos.y, 15, RED);

        enemy.pos.y += (player.pos.y - enemy.pos.y) * chase_elasticity;

        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            player.pos.y -= (player.vel_y * dt) * run_elasticity;
            player.vel_y += acceleration;
        }
        else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            player.pos.y += (player.vel_y * dt) * run_elasticity;
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

        if (player.pos.x == enemy.pos.x && player.pos.y == enemy.pos.y)
        {
            player.alive = 0;
        }
        if (!player.alive)
        {
            DrawText("You are dead.", SWIDTH / 2, SHEIGHT / 2, 100, RED);
        }
        enemy.pos.x += enemy.vel.x;
        EndDrawing();
    }

    CloseWindow();
    return 0;
}