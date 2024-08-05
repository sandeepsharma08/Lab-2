#include<iostream>
#include<iomanip>
#include<math.h>
#define A 3
#define B 5
float u[B+1][A+1];

using namespace std;
float func(float x) {
	float pi = 3.14;
	return (sin(pi*x));
}
int main() {
	float h=0.2, k=0.02,csqr,alpha,ust,uet;
	int i,j;
	cout<<"Enter the square of 'c'"<<endl;
	cin >> csqr;
	alpha = (csqr*k)/(h*h);
	cout <<"Enter the value of u[0,t]"<<endl;
	cin>>ust;
	cout <<"Enter the value of u[1,t]"<<endl;
	cin>>uet;
	cout<<fixed;
	for (j=0; j<=A; j++) {
		u[0][j] = u[B][j]=ust;
	}
	for(i=1; i<=B-1; i++) {
		u[i][0] = func(i*h);
	}
	for(j=0; j<=A-1; j++) {
		for(i=1; i<=B-1; i++) {
			u[i][j+1]=alpha*u[i-1][j] + (1-2*alpha)*u[i][j] + alpha*u[i+1][j];
		}
	}
	cout<<"The value of alpha is"<<setw(4) << setprecision(2)<<alpha<<endl;
	cout<<"THe values of u[i,j] are:-"<<endl;
	for(j=0; j<=A; j++) {
		for(i=0; i<=B; i++) {
			cout<<setw(7) <<setprecision(3)<<u[i][j];

		}
		cout<<endl;
	}
	return 0;
}

