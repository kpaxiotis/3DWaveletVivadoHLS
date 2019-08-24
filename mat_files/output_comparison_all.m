clear;
close;

dif_max = 0;    
diff_arr = zeros(70,1);

for h = 4:4:128
    for l = 4:4:128
    clear Y;
    clear X;
    

    image_gold = [num2str(h) 'x' num2str(l) 'x24'];
        file1 = fullfile(...
    ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\' ...
     'Thesis\vivado\mat_files\gold_images\' image_gold]...
    , 'out.gold.dat');

        gold = importdata(file1,'\n');
        count = 1;
        for i = 1:h
            for j = 1:l
                for k = 1:24       

                    Y(i,j,k) = gold(count);
                    count = count + 1;

                end
            end
        end
        
        image_out = [num2str(h) 'x' num2str(l) 'x24'];
        file2 = fullfile(...
    ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\' ...
     'Thesis\c_code\all_images\out_images\' image_out]...
    , 'out.dat');

        out = importdata(file2,'\n');
        count = 1;
        for i = 1:h
            for j = 1:l
                for k = 1:24       

                    X(i,j,k) = out(count);
                    count = count + 1;
                    
                    dif = abs(X(i,j,k) - Y(i,j,k));
                    dif_int = uint8(1000000*abs(X(i,j,k) - Y(i,j,k))+1);
                    if dif > dif_max
                        dif_max = dif;
                        dif_image = [num2str(h) 'x' num2str(l) 'x24'];
                        count_flag = count;
                    end
                     diff_arr(dif_int) = diff_arr(dif_int) + 1;

                end
            end
        end

        
    end
end
plot(diff_arr);