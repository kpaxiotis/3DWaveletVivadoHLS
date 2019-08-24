y = importdata('in_image.dat','\n');

count = 4;

for i = 1:y(1)
    for j = 1:y(2)
        for k = 1:y(3)     
            X(i,j,k) = y(count);
            count = count + 1;
            
        end
    end
end

x_size = size(X,1);
y_size = size(X,2);
z_size = size(X,3);

for j = 1:y_size
    for k = 1:z_size
        for i = 1:x_size
            array(i) = X(i,j,k);
        end
        for i = 1:size(X,1)/2
            temp(i) =  array(i*2-1)*0.5*1.41421356 + array(i*2)*0.5*1.41421356;
            temp(i+size(X,1)/2) = array(i*2-1)*0.5*1.41421356 - array(i*2)*0.5*1.41421356;
        end
        for i = 1:size(X,1)
            X(i,j,k) = temp(i);
        end
    end
end

for k = 1:z_size
    for i = 1:x_size
        for j = 1:y_size
            array(j) = X(i,j,k);
        end
        for j = 1:size(X,2)/2
            temp(j) =  array(j*2-1)*0.5*1.41421356 + array(j*2)*0.5*1.41421356;
            temp(j+size(X,2)/2) = array(j*2-1)*0.5*1.41421356 - array(j*2)*0.5*1.41421356;
        end
        for j = 1:size(X,2)
            X(i,j,k) = temp(j);
        end
    end
end

for i = 1:x_size
    for j = 1:y_size
        for k = 1:z_size
            array(k) = X(i,j,k);
        end
        for k = 1:size(X,3)/2
            temp(k) =  array(k*2-1)*0.5*sqrt(2) + array(k*2)*0.5*sqrt(2);
            temp(k+size(X,1)/2) = array(k*2-1)*0.5*sqrt(2) - array(k*2)*0.5*sqrt(2);
        end
        for k = 1:size(X,3)
            X(i,j,k) = temp(k);
        end
    end
end

file = fullfile(...
    'C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\mat_files'...
    , 'out.dat');
fileID = fopen(file,'wt');


for i = 1:size(X,1)
    for j = 1:size(X,2)
        for k = 1:size(X,3)        
        
            fprintf(fileID,'%f\n',X(i,j,k));
            
        end
    end
end

fclose(fileID);