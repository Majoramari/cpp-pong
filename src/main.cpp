#include <string>
#include "ball.h"
#include "bot.h"
#include "paddle.h"
#include "raylib.h"


int main() {
    const short screen_width = 1280;
    const short screen_height = 800;

    int player_score = 0;
    int bot_score = 0;

    InitWindow(screen_width, screen_height, "MajorAmari's Pong");
    SetTargetFPS(60);

    Ball::Params ball_params = {screen_width / 2, screen_height / 2, 7, 7,
                                20.0};
    Ball ball(ball_params);

    Paddle::Params player_params = {screen_width - 35, (screen_height / 2) - 60,
                                    25, 120, 6};
    Paddle player(player_params);

    Bot::Params bot_params = {10, (screen_height / 2) - 60, 25, 120, 6};
    Bot bot(bot_params);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ball.update(player_score, bot_score);
        player.update();
        bot.update(ball.pos_y());

        if (CheckCollisionCircleRec(
                    Vector2{static_cast<float>(ball.pos_x()),
                            static_cast<float>(ball.pos_y())},
                    ball.radius(),
                    Rectangle{static_cast<float>(player.get_pos_x()),
                              static_cast<float>(player.get_pos_y()),
                              static_cast<float>(player.get_width()),
                              static_cast<float>(player.get_height())})) {
            ball.set_speed_x(ball.speed_x() * -1);
        }

        if (CheckCollisionCircleRec(
                    Vector2{static_cast<float>(ball.pos_x()),
                            static_cast<float>(ball.pos_y())},
                    ball.radius(),
                    Rectangle{static_cast<float>(bot.get_pos_x()),
                              static_cast<float>(bot.get_pos_y()),
                              static_cast<float>(bot.get_width()),
                              static_cast<float>(bot.get_height())})) {
            ball.set_speed_x(ball.speed_x() * -1);
        }

        ClearBackground(BLACK);
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        ball.draw();
        player.draw();
        bot.draw();

        std::string bot_score_text = std::to_string(bot_score);
        DrawText(bot_score_text.c_str(), (screen_width / 4) - 20, 20, 80,
                 WHITE);

        std::string player_score_text = std::to_string(player_score);
        DrawText(player_score_text.c_str(), (3 * (screen_width / 4)) - 20, 20,
                 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
