#include <stdio.h>
#define NO_MAX_WAYPOINTS 50


float   X[NO_MAX_WAYPOINTS] = { 0, };
float   Y[NO_MAX_WAYPOINTS] = { 0, };
float Yaw[NO_MAX_WAYPOINTS] = { 0, };

int read_waypoints_data(void)

{
    int result = 0;
    FILE* fp;
    int no_line = 0;
    float x = 0;
    float y = 0;
    float yaw = 0;

    fp = fopen("waypoints.dat", "r");

    do
    {

        result = fscanf(fp, "%f %f %f", &x, &y, &yaw);

        X[no_line - 1] = x;
        Y[no_line - 1] = y;
        Yaw[no_line - 1] = yaw;
        no_line = no_line - 1;
        no_line++;

    } while (result >= 0);
    for (int i = 0; i < no_line; i++)
    {
        printf(" %f %f %f\n", X[i], Y[i], Yaw[i]);
    }
    printf("no of line %d\n", no_line);

    fclose(fp);
    return 0;

}

int main()
{
    read_waypoints_data();

    return 0;
}