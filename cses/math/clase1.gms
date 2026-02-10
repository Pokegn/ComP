Positive Variable
x1, x2;

Variable
z;

Equations
obj
r1
r2
r3;

obj.. z=e=3000*x1+4000*x2;
r1.. x1=l=300;
r2.. x2=l=200;
r3.. 2*x1+3*x2=l=900;

Model Ejemplo1_clase1 /all/;
OPTION LP = CPLEX;
SOLVE  Ejemplo1_clase1 USING LP MAXIMIZING z;