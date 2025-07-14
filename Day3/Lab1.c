#include <stdio.h>
float Area(void);
float Volume(void);

void main(void)
{   
    Area();
    Volume();
}


float Area(void)
{
    float PI =3.14, radius;
    printf("please enter the radius : ");
    scanf("%f",&radius);
    float area = PI * (radius * radius) ;
    printf("the area of circle is : %f\n",area);
    return area;

}

float Volume(void)
{
    float PI =3.14, cylinder , height;
    printf("please enter the radius of cylinder: ");
    scanf("%f",&cylinder);
     printf("please enter the height of cylinder: ");
    scanf("%f",&height);
    float volume = PI * (cylinder * cylinder) * height ;
    printf("the volume of cylinder with radius is : %f\n",volume);
    return volume;
}