clear;

file = fullfile(['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\' ...
     'Thesis\vivado\mat_files'], 'gold_images');
mkdir(file);
for h = 4:4:128
    for l = 4:4:128
        for n = 1:10
        
        clear X;
        
        image_in = 'in_image.dat';
        file1 = fullfile(...
    ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\' ...
     'Thesis\vivado\mat_files\in_images' num2str(h)...
     'x' num2str(l) 'x24\' num2str(n)]...
    , image_in);
        y = importdata(file1,'\n');

        count = 4;

        for i = 1:y(1)
            for j = 1:y(2)
                for k = 1:y(3)
                    X(i,j,k) = y(count);
                    count = count + 1;

                end
            end
        end


        n = 2;
        w = 'db1';
        wd1 = wavedec3(X,n,w);

        for i = 0:n-1
            if i == 0
                c{1} = wd1.dec{1};
            else
                c{1} = c{i*7};
            end
            c{1} = cat(1, c{1}, wd1.dec{i*7 + 3});
            c{2} = cat(1, wd1.dec{i*7 + 2}, wd1.dec{i*7 + 4});
            c{3} = cat(2, c{1}, c{2});
            c{4} = cat(1, wd1.dec{i*7 + 5}, wd1.dec{i*7 + 7});
            c{5} = cat(1, wd1.dec{i*7 + 6}, wd1.dec{i*7 + 8});
            c{6} = cat(2, c{4}, c{5});
            c{7} = cat(3, c{3}, c{6});
        end

        X = c{7};
        dwt = X;
        
        file_dir =...
            ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis' ...
            '\vivado\mat_files\gold_images\'];
        
        file_dir2 = [num2str(h) 'x' num2str(l) 'x24\' num2str(n)];
        mkdir ([file_dir file_dir2]);
        
        file2 = fullfile(file_dir, file_dir2, 'out.gold.dat');
        fileID = fopen(file2,'wt');


        for i = 1:size(X,1)
            for j = 1:size(X,2)
                for k = 1:size(X,3)

                    fprintf(fileID,'%f\n',X(i,j,k));

                end
            end
        end

        fclose(fileID);
        
        end
    end
end