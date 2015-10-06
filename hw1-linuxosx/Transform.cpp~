// Transform.cpp: implementation of the Transform class.

#include <cstdio>
#include "Transform.h"
using namespace glm;

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {

// axis need to be unit
  // YOUR CODE FOR HW1 HERE

int i;


  mat3 I(1.0);

  mat3 M2= mat3(axis.x*axis.x, axis.x*axis.y,axis.x*axis.z,
		 axis.x*axis.y,axis.y*axis.y,axis.y*axis.z,   
         	axis.x*axis.z,axis.y*axis.z,axis.z*axis.z);


  

	printf("Coordinates: %.2f, %.2f, %.2f\n",M2[0][0],M2[1][0],M2[2][0]);

	printf("Coordinates: %.2f, %.2f, %.2f\n",M2[0][1],M2[1][1],M2[2][1]);
	
	printf("Coordinates: %.2f, %.2f, %.2f\n",M2[0][2],M2[1][2],M2[2][2]);
	
	

//	scanf("%d",&i);



  mat3 M3(0, axis.z, -axis.y,
	  -axis.z, 0, axis.x,
	  axis.y,-axis.x,0);

  mat3 M= cos(degrees)*I  + (1-cos(degrees) )*M2 +sin(degrees)*M3;
  

 

	/*printf("Coordinates: %.2f, %.2f, %.2f\n",M2[0][0],M2[1][0],M2[2][0]);

	printf("Coordinates: %.2f, %.2f, %.2f\n",M2[0][1],M2[1][1],M2[2][1]);
	
	printf("Coordinates: %.2f, %.2f, %.2f\n",M2[0][2],M2[1][2],M2[2][2]);
*/
  return M;


}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE

//	  printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));


      vec3 r= up;
	r= normalize(r);


	printf("axis %.2f, %.2f, %.2f\n",r.x,r.y,r.z);

      eye= rotate(degrees*pi/180,r)* eye;



   //  up=rotate(degrees,vec3(0,1,0))* up;
	  printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) 
{
    vec3 r= cross(up,eye);
	r= normalize(r);


	 printf("Eye: %.2f, %.2f, %.2f\n", eye.x, eye.y, eye.z);
	 printf("Up: %.2f, %.2f, %.2f\n", up.x, up.y, up.z);
	 printf("axis %.2f, %.2f, %.2f\n",r.x,r.y,r.z);
//

	 up= rotate(-degrees*pi/180,r)* up;

/* up = up*cos(degrees*pi/180) 
    + sin(degrees*pi/180)*cross(r,up)+
   (1-cos(degrees*pi/180))*r*(r*up);
*/
         eye= rotate(-degrees*pi/180,r)* eye;
    
  printf("Coordinates eye: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
  printf("Coordinates up: %.2f, %.2f, %.2f\n", up.x, up.y, up.z);
     
   

}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call

	printf("lookat\n");
	vec3 w = vec3(eye.x,eye.y,eye.z);
	w=normalize(w);

	//printf("Coordinates: %.2f, %.2f, %.2f\n",w.x, w.y, w.z);

	int i;
	//scanf("%d",&i);
	vec3 u = cross(up, w);
        u=normalize(u);


	//printf("Coordinates: %.2f, %.2f, %.2f\n",u.x, u.y, u.z);

	//int i;
	//scanf("%d",&i);

	vec3 v = cross(w,u);
        v= normalize(v);
     

	//	printf("Coordinates: %.2f, %.2f, %.2f\n",v.x, v.y, v.z);

	//int i;
	//scanf("%d",&i);

	mat4 R = mat4(u.x,u.y,u.z,0,
		      v.x,v.y,v.z,0,
		      w.x,w.y,w.z,0,
		      0,0,0,1 );

	R= transpose(R);

/*	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",R[0][0],R[1][0],R[2][0],R[3][0]);

	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",R[0][1],R[1][1],R[2][1],R[3][1]);
	
	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",R[0][2],R[1][2],R[2][2],R[3][2]);
	
	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",R[0][3],R[1][3],R[2][3],R[3][3]);


	scanf("%d",&i);

*/
	mat4 T= mat4(1,0,0,-eye.x,0,1,0,-eye.y,0,0,1,-eye.z,0,0,0,1);

	T= transpose(T);

	
/*	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",T[0][0],T[1][0],T[2][0],T[3][0]);

	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",T[0][1],T[1][1],T[2][1],T[3][1]);
	
	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",T[0][2],T[1][2],T[2][2],T[3][2]);
	
	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",T[0][3],T[1][3],T[2][3],T[3][3]);
*/
	mat4 result = R*T;


/*
	scanf("%d",&i);
	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",result[0][0],result[1][0],result[2][0],result[3][0]);

	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",result[0][1],result[1][1],result[2][1],result[3][1]);
	
	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",result[0][2],result[1][2],result[2][2],result[3][2]);
	
	printf("Coordinates: %.2f, %.2f, %.2f,%.2f\n",result[0][3],result[1][3],result[2][3],result[3][3]);



	//int i;
	scanf("%d",&i);
*/
  return result;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
