load wmri

file = fullfile('C:\Users\KOSTAS\Desktop', 'arrayForC.txt');
fileID = fopen(file,'wt');

fprintf(fileID,"pic =\n{");
for i = 1:size(X,1)
    fprintf(fileID,'{');
    for j = 1:size(X,2)
        fprintf(fileID,'{');
        for k = 1:(size(X,3)+1)        

            if k == size(X,3)+1
                fprintf(fileID,'0');
            else
                fprintf(fileID,'%d, ',X(i,j,k));
            end
        end
        
        if j == size(X,2)
            fprintf(fileID,'}\n');
        else
            fprintf(fileID,'},\n');
        end
    end
    if i == size(X,1)
        fprintf(fileID,'}\n');
    else
        fprintf(fileID,'},\n');
    end
end
fprintf(fileID, '}');
fclose(fileID);
