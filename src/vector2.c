#include "../inc/vector2.h"

t_vector2 plus_vectors(t_vector2 v1, t_vector2 v2) {
    t_vector2 new_vector2 = {v1.x + v2.x, v1.y + v2.y};
    return new_vector2;
}

t_vector2 negate_vector(t_vector2 vector2) {
    t_vector2 new_vector2 = {-vector2.x, -vector2.y};
    return new_vector2;
}

t_vector2 devide_vector_by(t_vector2 vector2, float devider) {
    t_vector2 new_vector2 = {vector2.x / devider, vector2.y / devider};
    return new_vector2;
}

