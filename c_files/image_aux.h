#ifndef IMAGE_AUX_H_
#define IMAGE_AUX_H_
#define MAX_SIZE 24
#define MIN_SIZE 4



typedef struct {
	int x_size;
	int y_size;
	int z_size;
	float data3D[MAX_SIZE][MAX_SIZE][MAX_SIZE];
}image_t;

typedef struct {
	int size;
	float data1D[MAX_SIZE];
}array_t;

#endif
