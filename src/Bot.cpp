#include "bot.h"

void Bot::update(int ball_y) {
    if (get_pos_y() + get_height() / 2 > ball_y) {
        set_pos_y(get_pos_y() - get_speed());
    }

    if (get_pos_y() + get_height() / 2 <= ball_y) {
        set_pos_y(get_pos_y() + get_speed());
    }
}
