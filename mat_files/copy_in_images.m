clear;
close all;


for i = 4:4:128
    for j = 4:4:128            
        for n = 1:10
            
            new_name = [ num2str(i) 'x' num2str(j) 'x24_' num2str(n)...
                '.dat'];
            file = fullfile(...
        ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\'... 
        'mat_files\in_images'], ...
        new_name);
            file_name = 'in_image.dat';        
            
            file2 = fullfile(...
        ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\'...
        'mat_files\in_images_f\' ...
        num2str(i) 'x' num2str(j) 'x24\' num2str(n)]...
        , file_name);
        
            copyfile(file2, file);
        end
    end
end