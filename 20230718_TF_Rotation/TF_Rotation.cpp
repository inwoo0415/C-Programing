// TF_Rotation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include "math.h"

#define RAD2DEG(x)   x*180/M_PI
#define DEG2RAD(x)   x*M_PI/180

double MAP_X = -2.0;
double MAP_Y = 4.0;

double BASE_X = 4.0;
double BASE_Y = 2.0;



typedef struct 
{
	double x;
	double y;
	double theta;
} Pose2D;

typedef struct
{
	double x;
	double y;	
} Point2D;


Pose2D    base_link_origin;
Point2D   base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;

double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

 
void set_rotation_matrix(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix[0][0] = cos(angle_radian);   Rotation_matrix[0][1] = -sin(angle_radian);
	Rotation_matrix[1][0] = sin(angle_radian);   Rotation_matrix[1][1] = cos(angle_radian);
	printf("Rotation_matrix : \n");
	printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
	printf("%6.3lf  %6.3lf\n\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);
	printf("===================================================== \n\n");
}

void set_rotation_matrix_inverse(double m_angle_degree)
{
	angle_radian = DEG2RAD(m_angle_degree);

	Rotation_matrix_inverse[0][0] =  cos(angle_radian);   Rotation_matrix_inverse[0][1] = sin(angle_radian);
	Rotation_matrix_inverse[1][0] = -sin(angle_radian);   Rotation_matrix_inverse[1][1] = cos(angle_radian);

	printf("Rotation_matrix_inverse : \n");
	printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[0][0], Rotation_matrix_inverse[0][1]);
	printf("%6.3lf  %6.3lf\n\n", Rotation_matrix_inverse[1][0], Rotation_matrix_inverse[1][1]);
	printf("===================================================== \n\n");
}

void TF_base_link_map_to_base_link(Point2D base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{

	base_link_point2d.x = (MAP_X * Rotation_matrix[0][0]) + (MAP_Y * Rotation_matrix[0][1]);
	base_link_point2d.y = (MAP_X * Rotation_matrix[1][0]) + (MAP_Y * Rotation_matrix[1][1]);

	printf("base_link.x :     %6.3lf  base_link.y:     %6.3lf\n", base_link_point2d.x, base_link_point2d.y);
	
}
void TF_base_link_to_base_link_map(Point2D base_link_point2d, Point2D *base_link_map_point2d, Pose2D base_link_origin)
{
	

	base_link_map_point2d->x = (BASE_X * Rotation_matrix_inverse[0][0]) + (BASE_Y * Rotation_matrix_inverse[0][1]);
	base_link_map_point2d->y = (BASE_X * Rotation_matrix_inverse[1][0]) + (BASE_Y * Rotation_matrix_inverse[1][1]);

	printf("base_link_map_x : %6.3lf  base_link_map :  %6.3lf\n", base_link_map_point2d->x, base_link_map_point2d->y);

}

void data_Input()
{
	
	printf("base_link_origin.x : ");
	scanf_s("%lf", &base_link_origin.x);
	printf("base_link_origin.y : ");
	scanf_s("%lf", &base_link_origin.y);
	printf("base_link_origin.theta : ");
	scanf_s("%lf", &base_link_origin.theta);
	printf("===================================================== \n\n");
}






int _tmain(int argc, _TCHAR* argv[])
{
	

	data_Input();

	set_rotation_matrix(base_link_origin.theta);
	set_rotation_matrix_inverse(base_link_origin.theta);

	TF_base_link_map_to_base_link(base_link_Point2D, &base_link_map_Point2D, base_link_origin);
	TF_base_link_to_base_link_map(base_link_Point2D,&base_link_map_Point2D, base_link_origin);

	return 0;
}

