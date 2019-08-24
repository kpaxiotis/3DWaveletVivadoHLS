file = fullfile('C:\Users\KOSTAS\Desktop', 'in_image.dat');
fileID = fopen(file,'wt');

x_size = 4;
y_size = 4;
z_size = 4;

fprintf(fileID,'%d\n',x_size);
fprintf(fileID,'%d\n',y_size);
fprintf(fileID,'%d\n',z_size);

for i = 1:x_size
    for j = 1:y_size
        for k = 1:z_size
        
            fprintf(fileID,'1\n');
            
        end
    end
end
fclose(fileID);