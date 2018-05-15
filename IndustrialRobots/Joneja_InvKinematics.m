clear all
disp(' ');
%% INPUT PARAMETERS
%world x,y,z coordinates and O,A,T angles in degrees
x = -212.92;
y = 156.40;
z = 1361.50;
O = -80.0;
A = -80.0;
T = 180.0;

x = -248.06;
y = 135.36;
z = 1347.12;
O = -66.3;
A = -60.42;
T = -153.09;

x = 278.33;
y = 460.06;
z = 1148.01;
O = 90.0;
A = -45.0;
T = -45.0;

fprintf('\nThe tool coordinates in world are: \n [x\t\t,y\t\t,z\t\t,O\t\t,A\t\t,T\t] \n [%.1f,%.1f,%.1f,%.1f,%.1f,%.1f]',x,y,z,O,A,T);

O = deg2rad(O);
A = deg2rad(A);
T = deg2rad(T);

%PUMA 762 link parameters
a2 = 650;
a3 = 0;
d3 = 191;
d4 = 600;

Twt = [cos(O)*sin(T)-sin(O)*sin(A)*cos(T),cos(O)*cos(T)+sin(O)*sin(A)*sin(T),sin(O)*cos(A),x; ...
       sin(O)*sin(T)+cos(O)*sin(A)*cos(T),sin(O)*cos(T)-cos(O)*sin(A)*sin(T),-cos(O)*cos(A),y; ...
       -cos(A)*cos(T),cos(A)*sin(T),-sin(A),z; ...
       0,0,0,1];
T6t = [-1,0,0,0;
       0,-1,0,0;
       0,0,1,125;
       0,0,0,1];
T06 = Twt*inv(T6t);
px = T06(1,4);
py = T06(2,4);
pz = T06(3,4);

%theta1
theta1(1)= atan2(py,px)-atan2(d3,(px^2+py^2-d3^2)^(1/2));
theta1(2)= atan2(py,px)-atan2(d3,-(px^2+py^2-d3^2)^(1/2));

%theta3 partial
W = (px^2+py^2+pz^2-a2^2-a3^2-d3^2-d4^2)/a2/2; %dummy param
theta3(1)= atan2(a3,d4)-atan2(W,(a3^2+d4^2-W^2)^(1/2));
theta3(2)= atan2(a3,d4)-atan2(W,-(a3^2+d4^2-W^2)^(1/2));

%theta2
theta23(1:2) = atan2((-a3-a2*cos(theta3(1)))*pz-(cos(theta1)*px+sin(theta1)*py)*(d4-a2*sin(theta3(1))),(a2*sin(theta3(1))-d4)*pz+(a3+a2*cos(theta3(1)))*(cos(theta1)*px+sin(theta1)*py));
theta23(3:4) = atan2((-a3-a2*cos(theta3(2)))*pz-(cos(theta1)*px+sin(theta1)*py)*(d4-a2*sin(theta3(2))),(a2*sin(theta3(2))-d4)*pz+(a3+a2*cos(theta3(2)))*(cos(theta1)*px+sin(theta1)*py));
theta2(1:2) = theta23(1:2) - [theta3(1),theta3(1)];
theta2(3:4) = theta23(3:4) - [theta3(2),theta3(2)];

%organizing first four solutions
theta(1,1:3)= [theta1(1),theta2(1),theta3(1)];
theta(2,1:3)= [theta1(2),theta2(2),theta3(1)];
theta(3,1:3)= [theta1(1),theta2(3),theta3(2)];
theta(4,1:3)= [theta1(2),theta2(4),theta3(2)];

%rotational matrix
r11 = T06(1,1);
r12 = T06(1,2);
r13 = T06(1,3);
r21 = T06(2,1);
r22 = T06(2,2);
r23 = T06(2,3);
r31 = T06(3,1);
r32 = T06(3,2);
r33 = T06(3,3);

%theta4 (implies theta5 != 0)
for n = 1:4
    theta4(n) = atan2(-r13*sin(theta(n,1))+r23*cos(theta(n,1)),-r13*cos(theta(n,1))*cos(theta23(n))-r23*sin(theta(n,1))*cos(theta23(n))+r33*sin(theta23(n)));
    theta(n,4) = theta4(n);
end

%theta
for n = 1:4
    s5(n) = -(r13*(cos(theta(n,1))*cos(theta23(n))*cos(theta(n,4))+sin(theta(n,1))*sin(theta(n,4)))+r23*(sin(theta(n,1))*cos(theta23(n))*cos(theta(n,4))-cos(theta(n,1))*sin(theta(n,4)))-r33*(sin(theta23(n))*cos(theta(n,4))));
    c5(n) = r13*(-cos(theta(n,1))*sin(theta23(n)))+r23*(-sin(theta(n,1))*sin(theta23(n)))+r33*(-cos(theta23(n)));
    theta5(n) = atan2(s5(n),c5(n));
    theta(n,5) = theta5(n);
end

%corresponding theta6s
for n = 1:4
    s6(n) = -r11*(cos(theta(n,1))*cos(theta23(n))*sin(theta(n,4))-sin(theta(n,1))*cos(theta(n,4)))-r21*(sin(theta(n,1))*cos(theta23(n))*sin(theta(n,4))+cos(theta(n,1))*cos(theta(n,4)))+r31*(sin(theta23(n))*sin(theta(n,4)));
    c6(n) = r11*((cos(theta(n,1))*cos(theta23(n))*cos(theta(n,4))+sin(theta(n,1))*sin(theta(n,4)))*cos(theta(n,5))-cos(theta(n,1))*sin(theta23(n))*sin(theta(n,5)))+r21*((sin(theta(n,1))*cos(theta23(n))*cos(theta(n,4))-cos(theta(n,1))*sin(theta(n,4)))*cos(theta(n,5))-sin(theta(n,1))*sin(theta23(n))*sin(theta(n,5)))-r31*(sin(theta23(n))*cos(theta(n,4))*cos(theta(n,5))+cos(theta23(n))*sin(theta(n,5)));
    theta(n,6) = atan2(s6(n),c6(n));
end

%adding "flipped" solutions
theta(5:8,:) = theta(1:4,:);
theta(5:8,4) = theta(1:4,4) - pi;
theta(5:8,5) = -theta(1:4,5);
theta(5:8,6) = theta(1:4,6) + pi;

%converting to degrees
theta = rad2deg(theta);

%convention for theta3
theta(:,3) = theta(:,3)-180;

%make sure all angles are between -180 to 180 degrees
%(I got help from Eli Xu for this section)
for n = 1:8
    for m = 1:6
        if theta(n,m) < -180
            theta(n,m) = theta(n,m) + 360;
        else if theta(n,m) > 180
                theta(n,m) = theta(n,m) - 360;
            end
        end
    end
end

%display results
fprintf('\nThe possible joint angle combinations are: ');
fprintf('\n   t1          t2        t3        t4        t5       t6\n');
disp(theta);



