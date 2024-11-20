#ifndef BOT_H
#define BOT_H

#include "paddle.h"

class Bot : public Paddle {
public:
    using Paddle::Params;

    Bot(const Params &params) : Paddle(params) {}

    void update(int ball_y);
};

#endif
