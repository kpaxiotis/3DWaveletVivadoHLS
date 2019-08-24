load wmri

file = fullfile('C:\Users\KOSTAS\Desktop', 'in_image.dat');
fileID = fopen(file,'wt');


for i = 1:2
    fprintf(fileID,'%d\n',size(X,i));
end

fprintf(fileID,'%d\n',size(X,3)-3);


for i = 1:size(X,1)
    for j = 1:size(X,2)
        for k = 1:size(X,3)-3        
        
            fprintf(fileID,'%f\n',X(i,j,k));
            
        end
    end
end
fclose(fileID);
