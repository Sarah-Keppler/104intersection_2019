/*
** EPITECH PROJECT, 2019
** 103intersection
** File description:
** wait..loading..
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/my.h"

void disp_hflag(void)
{
    printf("USAGE\n");
    printf("    ./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n");
    printf("    opt             surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n");
    printf("    (xp, yp, zp)    coordinates of a point by which the light ray passes through\n");
    printf("    (xv, yv, zv)    coordinates of a vector parallel to the light ray\n");
    printf("    p               parameter: radius of the sphere, radius of the cylinder, or\n");
    printf("                    angle formed by the cone and the Z-axis\n");
}

void calc_sphere(char **av)
{
    float sph[7];
    for (int i = 2; 9 > i; ++i) {
        sph[i - 2] = atof(av[i]);
    }
    float eval[3];
    eval[0] = pow(sph[0], 2.0) + pow(sph[1], 2.0) + pow(sph[2], 2.0);
    eval[1] = (2 * (sph[0] * sph[3])) + (2 * (sph[1] * sph[4])) + (2 * (sph[2] * sph[5]));;
    eval[2] = pow(sph[0], 2.0) + pow(sph[1], 2.0) + pow(sph[2], 2.0);
    float discrim = pow(eval[1], 2.0) - (4 * eval[0] * eval[3]);

    printf("Sphere of radius %d\n", (int)sph[6]);
    printf("Line passing through the point (%.2f, %.2f%, %.2f) ", sph[0], sph[1], sph[2]);
    printf("and parallel to the vector (%.2f, %.2f, %.2f)", sph[3], sph[4], sph[5]);
    
    float res = 0;
    res = (eval[1] * -1);    
    if (0 < discrim) {
        printf("2 intersection points:\n");
        res -= sqrt(res);
        res /= (2 * eval[0]);
        printf("(%.2f, %.2f, %.2f\n)", (eval[0] * res) + eval[3], (eval[1] * res) + eval[4],
               (eval[2] * res) + eval[5]);
        res = (eval[1] * -1);
        res += sqrt(res);
        res /= (2 * eval[0]);
        printf("(%.2f, %.2f, %.2f\n)", (eval[0] * res) + eval[3], (eval[1] * res) + eval[4],
               (eval[2] * res) + eval[5]);
    } else if (0 == discrim) {
        printf("1 intersection point:\n");
        res /= (2 * eval[0]);
        printf("(%.2f, %.2f, %.2f\n)", (eval[0] * res) + eval[3], (eval[1] * res) + eval[4],
               (eval[2] * res) + eval[5]);
    } else {
        printf("No intersection point.\n");
    }
}

void calc_cylinder(char **av)
{
    float cy[7];
    for (int i = 2; 9 > i; ++i) {
        cy[i - 2] = atof(av[i]);
    }
    float eval[3];
    eval[0] = pow(cy[0], 2.0) + pow(cy[1], 2.0);
    eval[1] = (2 * (cy[0] * cy[3])) + (2 * (cy[1] * cy[4]));
    eval[2] = pow(cy[3], 2.0) + pow(cy[4], 2.0) - pow(cy[6], 2.0);
    float discrim = pow(eval[1], 2.0) - (4 * eval[0] * eval[3]);

    printf("Cylinder of radius %d\n", (int)cy[6]);
    printf("Line passing through the point (%.2f, %.2f%, %.2f) ", cy[0], cy[1], cy[2]);
    printf("and parallel to the vector (%.2f, %.2f, %.2f)", cy[3], cy[4], cy[5]);
    float res = 0;
    res = (eval[1] * -1);
    
    if (0 < discrim) {
        printf("2 intersection points:\n");
        res -= sqrt(res);
        res /= (2 * eval[0]);
        printf("(%.2f, %.2f, %.2f\n)", (eval[0] * res) + eval[3], (eval[1] * res) + eval[4],
               (eval[2] * res) + eval[5]);
        res = (eval[1] * -1);
        res += sqrt(res);
        res /= (2 * eval[0]);
        printf("(%.2f, %.2f, %.2f\n)", (eval[0] * res) + eval[3], (eval[1] * res) + eval[4],
               (eval[2] * res) + eval[5]);
    } else if (0 == discrim) {
        printf("1 intersection point:\n");
        res /= (2 * eval[0]);
        printf("(%.2f, %.2f, %.2f\n)", (eval[0] * res) + eval[3], (eval[1] * res) + eval[4],
               (eval[2] * res) + eval[5]);
    } else {
        printf("No intersection point.\n");
    }
}

_Bool errors(char **av)
{
    if (!('0' < av[1][0] && '4' > av[1][0])) {
        printf("Wrong first parameter.\n");
        return (true);
    }
    for (int i = 2; 9 > i; ++i) {
        if (0 == my_str_isint_float(av[i])) {
            printf("Wrong arguments.\n");
            return (true);
        }
    }
    if (0.0 > atof(av[8])) {
        printf("Wrong last argument.\n");
        return (true);
    }
    return (false);
}

int main(int ac, char **av)
{
    if (2 != ac && 9 != ac) {
        printf("Wrong numbers of arguments -- Error\n");
        return (84);
    }
    if ('-' == av[1][0] && 'h' == av[1][1]) {
        disp_hflag();
        return (0);
    } else if (2 == ac){
        printf("~ Wrong first parameter.\n");
        return (84);
    }
    if (true == errors(av))
        return (84);
    if (av[1][0] == '2')
        calc_cylinder(av);
    else if (av[1][0] == '1')
        calc_sphere(av);
    return (0);
}
