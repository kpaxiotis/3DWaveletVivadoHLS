%Implemetes wavedec mamually only for the first value

y = importdata('in_image_test.dat','\n');

count = 4;

for i = 1:y(1)
    for j = 1:y(2)
        for k = 1:y(3)     
            X(i,j,k) = y(count);
            count = count + 1;
            
        end
    end
end

var = 0.7071;%0.5*sqrt(2);

dwttt = (((X(1,1,1)*var+X(2,1,1)*var)+(X(1,2,1)*var+X(2,2,1)*var))*var+...
   ((X(1,1,2)*var+X(2,1,2)*var)+(X(1,2,2)*var+X(2,2,2)*var))*var)*var;
fprintf('dwttt = %f\n', dwttt);

% dwttt = (((X(1,1,1)+X(2,1,1))*var+(X(1,2,1)+X(2,2,1))*var)*var+...
%    ((X(1,1,2)+X(2,1,2))*var+(X(1,2,2)+X(2,2,2))*var)*var)*var