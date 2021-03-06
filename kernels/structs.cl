#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct bbox {
    float4 min;
    float4 max;
} BBox;

typedef struct triangle {
    float4 v0;
    float4 v1;
    float4 v2;
    float4 normal;
    float4 color;
    struct bbox bbox;
} Triangle;

typedef struct light {
    float4 position;
    float4 color;
    float4 glob;
} Light;

typedef struct intersection {
    __global Triangle *triangle;
    float4 position;
    float distance;
} Intersection;

struct kdnode {
    struct bbox box;
    int left_index;
    int right_index;
    int num_triangles;
    int triangle_begin;
};

typedef struct ray {
    float4 origin;
    float4 direction;
} Ray;

#endif
