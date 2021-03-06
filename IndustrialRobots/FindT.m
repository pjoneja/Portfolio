function T = FindT(alpha,a,d,theta)

T = [cos(theta), -sin(theta), 0, alpha; ...
    sin(theta)*cos(alpha), cos(theta)*cos(alpha), -sin(alpha), -d*sin(alpha);...
    sin(theta)*sin(alpha), cos(theta)*sin(alpha), cos(alpha), d*cos(alpha);
    0, 0, 0, 1];
end