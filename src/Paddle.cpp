#include "paddle.h"
#include "raylib.h"

void Paddle::draw() const {
    DrawRectangle(get_pos_x(), get_pos_y(), get_width(), get_height(), WHITE);
}

void Paddle::update() {
    if (IsKeyDown(KEY_UP)) {
        set_pos_y(get_pos_y() - get_speed());
    }

    if (IsKeyDown(KEY_DOWN)) {
        set_pos_y(get_pos_y() + get_speed());
    }

    if (get_pos_y() <= 0) {
        set_pos_y(0);
    }

    if (get_pos_y() + get_height() >= GetScreenHeight()) {
        set_pos_y(GetScreenHeight() - get_height());
    }
}
