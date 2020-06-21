#include <stdio.h>
#include <stdlib.h>

struct Shape {
	int color; 
	double area; 
} shape1, shape2, shape3, shape4; 

struct Rectangle {
	double a; 
	double b; 
	shape1.color; 
	shape1.area; 
	shape2.color; 
	shape2.area; 
} rect1, rect2; 

struct Circle {
	double radius;  
	shape3.color; 
	shape3.area; 
	shape4.color; 
	shape4.area; 
} circle1, circle 2; 

int main(int argc, char *argv[]){
	
	rect1.a = 3.0; 
	rect1.b = 4.0; 
	rect1.shape1.color = 1; 
	rect1.shape1.area = rect1.a * rect1.b; 
	
	rect2.a = 5.0; 
	rect2.b = 6.0; 
	rect2.shape2.color = 2; 
	rect2.shape2.area = rect2.a * rect2.b; 
	
	circle1.radius = 2.0; 
	circle1.shape3.color = 3; 
	circle1.shape3.area = 3.14*radius*radius; 
	
	circle2.radius = 10.0;
	circle2.shape4.color = 4; 
	circle2.shape4.area = 3.14*radius*radius; 

	printf("c1 has area %d and color %d ", circle1.shape3.area, circle1.shape3.color); 
	
	printf("c2 has area %d and color %d ", circle2.shape4.area, circle2.shape4.color); 

	printf("r1 has area %d and color %d ", rect1.shape1.area, rect1.shape1.color); 
	
	printf("r2 has area %d and color %d ", rect2.shape2.area, rect2.shape2.color); 
	
	
}