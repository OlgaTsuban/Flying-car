#pragma once

typedef struct s_vector2 {
    float x;
    float y;
} t_vector2;

t_vector2 plus_vectors(t_vector2 v1, t_vector2 v2);
t_vector2 negate_vector(t_vector2 vector2);
t_vector2 devide_vector_by(t_vector2 vector2, float devider);
