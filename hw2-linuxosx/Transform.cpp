// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp
// See FAQ for more details or if you're having problems.

#include "Transform.h"
#include <cstdio>

using namespace glm;
// input pi degree and normalized axis
mat3 Transform::rotate(const float degrees, const vec3& axis) 
{
 
  float degree = degrees*pi/180;
  mat3 I(1.0);

  mat3 M2= mat3(axis.x*axis.x, axis.x*axis.y, axis.x*axis.z,
		 axis.x*axis.y,axis.y*axis.y,axis.y*axis.z,   
         	axis.x*axis.z,axis.y*axis.z,axis.z*axis.z);

  mat3 M3(0, axis.z, -axis.y,
	  -axis.z, 0, axis.x,
	  axis.y,-axis.x,0);

  mat3 M= cos(degree)*I  + (1-cos(degree) )*M2 +sin(degree)*M3;
  
 
  return M;
}

void Transform::left(float degrees, vec3& eye, vec3& up) 
{
  
 	vec3 r= up;
	r= normalize(r);

       eye= rotate(degrees,r)* eye;

printf("Coordinates eye: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
  printf("Coordinates up: %.2f, %.2f, %.2f\n", up.x, up.y, up.z);

}

void Transform::up(float degrees, vec3& eye, vec3& up) 
{
 
   vec3 r= cross(eye,up);
	r= normalize(r);


	 up= rotate(degrees,r)* up;

         eye= rotate(degrees,r)* eye;
   
printf("Coordinates eye: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
  printf("Coordinates up: %.2f, %.2f, %.2f\n", up.x, up.y, up.z);
}

mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) 
{

printf("look at \n");
	vec3 w = eye-center;
	w=normalize(w);

	
	vec3 u = cross(up, w);
        u=normalize(u);


	vec3 v = cross(w,u);
        v= normalize(v);
    

	mat4 R = mat4(u.x,u.y,u.z,0,
		      v.x,v.y,v.z,0,
		      w.x,w.y,w.z,0,
		      0,0,0,1 );

	R= transpose(R);


	mat4 T= mat4(1,0,0,-eye.x,0,1,0,-eye.y,0,0,1,-eye.z,0,0,0,1);

	T= transpose(T);


	mat4 result = R*T;

  return result;


}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
 
  // YOUR CODE FOR HW2 HERE
  // New, to implement the perspective transform as well.  
printf("aspect %f , fovy %f\n",aspect, fovy);


 float theta = fovy*pi/180/2;
 float d = 1/tan(theta);
 float f = zFar;
 float n = zNear; 
 
 float A =-(f+n)/(f-n);
 float B =- 2*f*n/(f-n);
 mat4 ret = mat4( d/aspect, 0, 0, 0,
		  0,       d, 0, 0, 
  		  0, 0, A, -1,
		  0, 0, B, 0);


  return ret;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) 
{
printf("scale\n");
  mat4 ret= mat4( sx,0,0,0,
		  0,sy,0,0,
                  0,0,sz,0,
		  0,0,0,1 );
  
  return ret;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) 
{

printf("translate\n");
  mat4 ret = mat4( 1,0,0,0,
		   0,1,0,0,
		   0,0,1,0,
                   tx,ty,tz,1);


  return ret;
}

// To normalize the up direction and construct a coordinate frame.  
// As discussed in the lecture.  May be relevant to create a properly 
// orthogonal and normalized up. 
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  

vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) 
{
  vec3 x = glm::cross(up,zvec); 
  vec3 y = glm::cross(zvec,x); 
  vec3 ret = glm::normalize(y); 
  return ret; 
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
