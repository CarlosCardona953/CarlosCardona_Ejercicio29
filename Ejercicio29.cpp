#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
  ofstream outfile;  
  int lenx= 101;
  double t = 0;  
  double deltax = 0.01;
  double deltat =0.01; 
  double tmax = 6.0;
  double c = 0.5;
  double c1 = deltax/deltat;
  double ratio = (c*c)/(c1*c1);
    
  double u[3][lenx];

  int i;

    
  for(i=0;i<lenx;i++){
        u[0][i]=-pow((i/(lenx-1)*2-1),2)+1;
    }

  u[1][0]=0;
  u[1][-1]=0;

    for(i=1;i<lenx;i++){
        u[1][i]=u[0][i]+ratio/2*(u[0][i+1]+u[0][i-1]-2*u[0][i]);
    }
 
    

  outfile.open("Curvas.dat");
  while(t<tmax){
      
    
    
        for(int i=1;i<deltax-1;i++){
            u[2][i]=2*u[1][i]-u[0][i]+ratio*(u[1][i+1]+u[1][i-1]-2*u[1][i]);
        }

      
        for(i=0;i<deltax;i++){
        outfile << u[0][i] << " ";
        }
        outfile << "\n";

        for(i=1;i<(deltax-1);i++){
            u[0][i]=u[1][i];
            u[1][i]=u[2][i];
        }
        
         t= t+deltat;
    }
   
    return 0;
}
    
    
    

    
   
