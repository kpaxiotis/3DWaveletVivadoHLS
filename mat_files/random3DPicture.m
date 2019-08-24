clear;
close all;


for i = 4:4:128
    for j = 4:4:128
        
        file1 = fullfile(...
        'C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\mat_files\in_images\');
            
        mkdir([file1 '\' num2str(i) 'x' num2str(j) 'x24']);
            
        for n = 1:10
            
            file2 = fullfile(...
        ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\mat_files\in_images\' ...
        num2str(i) 'x' num2str(j) 'x24\' num2str(n)]);
            
            mkdir(file2);
            file_name = 'in_image.dat';        
            
            file3 = fullfile(...
        ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\mat_files\in_images\' ...
        num2str(i) 'x' num2str(j) 'x24\' num2str(n)]...
        , file_name);

            fileID = fopen(file3,'wt');
            fprintf(fileID,'%d\n%d\n24\n',i,j);                 %printing dimensions
            for h = 1:i
                for l = 1:j
                    for k = 1:24
                        fprintf(fileID,'%d\n',randi([0, 128])); %printing random values
                    end
                end
            end
            fclose(fileID);
        end
    end
end