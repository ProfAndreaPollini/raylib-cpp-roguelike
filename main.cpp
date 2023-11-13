#include "raylib.h"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"

int main(void)
{
    float hero_x = 10;
    float hero_y = 10;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    // SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        // user input
        if (IsKeyDown(KEY_RIGHT))
        {
            hero_x += GetFrameTime();
        }

        if (IsKeyDown(KEY_LEFT))
        {
            hero_x -= GetFrameTime();
        }

        if (IsKeyDown(KEY_UP))
        {
            hero_y -= GetFrameTime();
        }

        if (IsKeyDown(KEY_DOWN))
        {
            hero_y += GetFrameTime();
        }

        // render the window
        BeginDrawing();

        ClearBackground(RAYWHITE);

        const char *text = "@";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, hero_x * text_size.x, hero_y * text_size.y, 20, BLACK);

        const char *position_text = TextFormat("x: %f, y: %f\nfps: %d", hero_x, hero_y, GetFPS());
        DrawText(position_text, 2, 2, 20, DARKGRAY);
        EndDrawing();
        // end render
    }

    CloseWindow();

    return 0;
}