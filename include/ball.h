#ifndef BALL_H
#define BALL_H

class Ball {
private:
    int pos_x_, pos_y_;
    int speed_x_ = 0, speed_y_ = 0;
    float radius_;

public:
    struct Params {
        int pos_x, pos_y;
        int speed_x, speed_y;
        float radius;
    };

    Ball(const Params &params) :
        pos_x_(params.pos_x), pos_y_(params.pos_y), speed_x_(params.speed_x),
        speed_y_(params.speed_y), radius_(params.radius) {}

    [[nodiscard]] int pos_x() const { return pos_x_; };
    void set_pos_x(int value) { pos_x_ = value; };

    [[nodiscard]] int pos_y() const { return pos_y_; };
    void set_pos_y(int value) { pos_y_ = value; };

    [[nodiscard]] int speed_x() const { return speed_x_; };
    void set_speed_x(int value) { speed_x_ = value; };

    [[nodiscard]] int speed_y() const { return speed_y_; };
    void set_speed_y(int value) { speed_y_ = value; };

    [[nodiscard]] float radius() const { return radius_; };
    void set_radius(float value) { radius_ = value; };

    void draw() const;
    void update(int &player_score, int &bot_score);
    void reset_ball();
};

#endif
