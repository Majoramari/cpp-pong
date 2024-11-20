#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
protected:
    int pos_x = 0, pos_y = 0;
    int width = 0, height = 0;
    int speed = 0;

public:
    struct Params {
        int x, y;
        int width, height;
        int speed;
    };

    Paddle(const Params &params) :
        pos_x(params.x), pos_y(params.y), width(params.width),
        height(params.height), speed(params.speed) {}

    [[nodiscard]] int get_pos_x() const { return pos_x; }
    void set_pos_x(int value) { pos_x = value; }

    [[nodiscard]] int get_pos_y() const { return pos_y; }
    void set_pos_y(int value) { pos_y = value; }

    [[nodiscard]] int get_width() const { return width; }
    void set_width(int value) { width = value; }

    [[nodiscard]] int get_height() const { return height; }
    void set_height(int value) { height = value; }

    [[nodiscard]] int get_speed() const { return speed; }
    void set_speed(int value) { speed = value; }

    void draw() const;

    void update();
};

#endif
