#include "ball.h"
#include <array>
#include "raylib.h"

void Ball::draw() const { DrawCircle(pos_x(), pos_y(), radius(), WHITE); }

void Ball::update(
        int &player_score, // NOLINT(bugprone-easily-swappable-parameters)
        int &bot_score) { // NOLINT(bugprone-easily-swappable-parameters)
    set_pos_x(pos_x() + speed_x());
    set_pos_y(pos_y() + speed_y());

    if (pos_y() + static_cast<int>(radius()) >= GetScreenHeight()
        || pos_y() <= 0) {
        set_speed_y(speed_y() * -1);
    }

    if (pos_x() + static_cast<int>(radius()) >= GetScreenWidth()) {
        bot_score++;
        reset_ball();
    }


    if (pos_x() - static_cast<int>(radius()) <= 0) {
        player_score++;
        reset_ball();
    }
}

void Ball::reset_ball() {
    set_pos_x(GetScreenWidth() / 2);
    set_pos_y(GetScreenHeight() / 2);

    int random_choice = GetRandomValue(0, 1);

    set_speed_x(speed_x() * (random_choice == 0 ? -1 : 1));
    set_speed_y(speed_y() * (random_choice == 0 ? -1 : 1));
}
