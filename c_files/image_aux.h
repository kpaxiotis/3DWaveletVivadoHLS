#ifndef IMAGE_AUX_H_
#define IMAGE_AUX_H_
#define MAX_SIZE 24
#define MIN_SIZE 4



typedef struct {
	float x_size;
	float y_size;
	float z_size;
	float data3D[MAX_SIZE][MAX_SIZE][MAX_SIZE];
}image_t;

typedef struct {
	float size;
	float data1D[MAX_SIZE];
}array_t;

#endif
