#include "raylib.h"

#include <cmath>
#include <vector>

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"
#define ENTITY_FONT_SIZE (20)

struct Entity
{
    float x;
    float y;
    float v;
    const char *glyph;
};

// struct Monster
// {
//     float x;
//     float y;
//     float v;
//     const char *glyph;
// };

void move_monster(Entity &monster, const Entity &hero)
{
    float dx = monster.x - hero.x;
    float dy = monster.y - hero.y;

    if (dx < 0)
    {
        monster.x += monster.v * GetFrameTime();
    }
    else if (dx > 0)
    {
        monster.x -= monster.v * GetFrameTime();
    }

    if (dy < 0)
    {
        monster.y += monster.v * GetFrameTime();
    }
    else if (dy > 0)
    {
        monster.y -= monster.v * GetFrameTime();
    }
}

void handle_user_input(float &x_pos, float &y_pos, float velocity)
{
    // user input
    if (IsKeyDown(KEY_RIGHT))
    {
        x_pos += velocity * GetFrameTime();
    }

    if (IsKeyDown(KEY_LEFT))
    {
        x_pos -= velocity * GetFrameTime();
    }

    if (IsKeyDown(KEY_UP))
    {
        y_pos -= velocity * GetFrameTime();
    }

    if (IsKeyDown(KEY_DOWN))
    {
        y_pos += velocity * GetFrameTime();
    }
}

int main(void)
{
    Entity hero = {
        .x = 10,
        .y = 10,
        .v = 10,
        .glyph = "@"};

    // float hero_x = 10;
    // float hero_y = 10;

    // float hero_v = 10;

    std::vector<Entity> monsters;

    Entity monster = {
        .x = 20,
        .y = 20,
        .v = 5,
        .glyph = "O"};

    monsters.push_back(monster);
    monsters.emplace_back(30, 30, 5, "T");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    const Vector2 text_size = MeasureTextEx(GetFontDefault(), hero.glyph, ENTITY_FONT_SIZE, 1);

    while (!WindowShouldClose())
    {
        handle_user_input(hero.x, hero.y, hero.v);

        for (auto &m : monsters)
        {
            move_monster(m, hero);
        }

        // render the window
        BeginDrawing();

        ClearBackground(RAYWHITE);

        int cell_x = floor(hero.x);
        int cell_y = floor(hero.y);

        DrawText(hero.glyph, cell_x * text_size.x, cell_y * text_size.y, ENTITY_FONT_SIZE, BLACK);
        // DrawText(text, hero_x * text_size.x, hero_y * text_size.y, 20, BLACK);

        // monster
        for (auto &m : monsters)
        {
            DrawText(m.glyph, m.x * text_size.x, m.y * text_size.y, ENTITY_FONT_SIZE, RED);
        }

        const char *position_text = TextFormat("x: %f, y: %f\nfps: %d", hero.x, hero.y, GetFPS());
        DrawText(position_text, 2, 2, 14, DARKGRAY);
        EndDrawing();
        // end render
    }

    CloseWindow();

    return 0;
}