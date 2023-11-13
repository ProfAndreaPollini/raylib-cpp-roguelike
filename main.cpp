#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    // Texture2D texture = LoadTexture(ASSETS_PATH "test.jpg"); // Check README.md for how this works

    while (!WindowShouldClose())
    {

        // render the window
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        // const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        // DrawTexture(texture, texture_x, texture_y, WHITE);

        const char *text = "@";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, SCREEN_HEIGHT / 2 - text_size.y / 2, 20, BLACK);

        EndDrawing();
        // end render
    }

    CloseWindow();

    return 0;
}