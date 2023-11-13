#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"

int main(void)
{
    int hero_x = 10;
    int hero_y = 10;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    // Texture2D texture = LoadTexture(ASSETS_PATH "test.jpg"); // Check README.md for how this works

    while (!WindowShouldClose())
    {

        // user input
        if (IsKeyDown(KEY_RIGHT))
        {
            hero_x++;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            hero_x--;
        }

        if (IsKeyDown(KEY_UP))
        {
            hero_y--;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            hero_y++;
        }

        // render the window
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        // const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        // DrawTexture(texture, texture_x, texture_y, WHITE);

        const char *text = "@";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, hero_x * text_size.x, hero_y * text_size.y, 20, BLACK);

        const char *position_text = TextFormat("x: %d, y: %d", hero_x, hero_y);
        DrawText(position_text, 2, 2, 20, DARKGRAY);
        EndDrawing();
        // end render
    }

    CloseWindow();

    return 0;
}