% Input Parameters
% joint angles in degrees (write in angles here)
theta = [0 -90 90 0 0 0]; 
%handle theta3 convenction
%theta(3) = theta(3) - 180;
% degrees to radians
theta = theta*pi/180;

% joint alpha,a,d values (all fixed)
alpha = [0 -90 0 -90 -90 -90]*pi/180;
a = [0 0 650 0 0 0];
d = [0 0 191 600 0 0];

T01 = FindT(alpha(1),a(1),d(1),theta(1));
T12 = FindT(alpha(2),a(2),d(2),theta(2));
T23 = FindT(alpha(3),a(3),d(3),theta(3));
T34 = FindT(alpha(4),a(4),d(4),theta(4));
T45 = FindT(alpha(5),a(5),d(5),theta(5));
T56 = FindT(alpha(6),a(6),d(6),theta(6));
T_6_Tool = [-1 0 0 0; 0 -1 0 0; 0 0 1 125; 0 0 0 1];

T_WT = T01*T12*T23*T34*T45*T56*T_6_Tool;
R_WT = T_WT(1:3,1:3);

ToolXYZ = R_WT*[0; 0; 0]+T_WT(1:3,4);

if (R_WT(3,3)+1 < 0.001) %Tool points UP
    A = pi/2;
    T = 0;
    O = atan2(-R_WT(1,1),R_WT(1,2));
elseif (R_WT(3,3)-1 < 0.001) %Tool points DOWN
    A = -pi/2;
    T = 0;
    O = atan2(R_WT(1,1),R_WT(1,2));
else
    A = atan2(-R_WT(3,3),sqrt(R_WT(3,1).^2+R_WT(3,2).^2));
    T = atan2(-R_WT(3,2)/cos(A),-R_WT(3,1)/cos(A));
    O = atan2(-R_WT(1,3)/cos(A),-R_WT(2,3)/cos(A));
end 

XYZ = ToolXYZ'
OAT = [O, A, T]*180/pi %degrees
