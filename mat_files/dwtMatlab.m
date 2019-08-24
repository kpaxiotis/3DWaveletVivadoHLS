% map = pink(90);
clear;

file = fullfile(...
    ['C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\' ...
     'Thesis\vivado\mat_files\in_images']...
    , '4x4x24.dat');

y = importdata(file,'\n');

count = 4;

for i = 1:y(1)
    for j = 1:y(2)
        for k = 1:y(3)     
            X(i,j,k) = y(count);
            count = count + 1;
            
        end
    end
end


n = 1;
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

file = fullfile(...
    'C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\mat_files'...
    , 'out.gold.dat');
fileID = fopen(file,'wt');


for i = 1:size(X,1)
    for j = 1:size(X,2)
        for k = 1:size(X,3)        
        
            fprintf(fileID,'%f\n',X(i,j,k));
            
        end
    end
end

fclose(fileID);

file = fullfile(...
    'C:\Users\KOSTAS\Documents\1.RADIOELECTROLOGY\Thesis\vivado\c_files\struct'...
    , 'out.gold.dat');
fileID = fopen(file,'wt');


for i = 1:size(X,1)
    for j = 1:size(X,2)
        for k = 1:size(X,3)        
        
            fprintf(fileID,'%f\n',X(i,j,k));
            
        end
    end
end

fclose(fileID);


% idxImages = 1:size(X,3);
% figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
%     'DefaultAxesFontSize',8,'Color','w')
% colormap(map)
% for k = 1:9
%     j = idxImages(k);
%     subplot(3,3,k);
%     image(X(:,:,j));
%     xlabel(['Z = ' int2str(j)]);
%     if k==2
%         title('Some slices along the Z-orientation of the original brain data');
%     end
% end
% idxImages = 10:size(X,3);
% figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
%     'DefaultAxesFontSize',8,'Color','w')
% colormap(map)
% for k = 1:9
%     j = idxImages(k);
%     subplot(3,3,k);
%     image(X(:,:,j));
%     xlabel(['Z = ' int2str(j)]);
%     if k==2
%         title('Some slices along the Z-orientation of the original brain data');
%     end
% end
% idxImages = 18:size(X,3);
% figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
%     'DefaultAxesFontSize',8,'Color','w')
% colormap(map)
% for k = 1:9
%     j = idxImages(k);
%     subplot(3,3,k);
%     image(X(:,:,j));
%     xlabel(['Z = ' int2str(j)]);
%     if k==2
%         title('Some slices along the Z-orientation of the original brain data');
%     end
% end
% idxImages = 28:size(X,3);
% figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
%     'DefaultAxesFontSize',8,'Color','w')
% colormap(map)
% j = idxImages(1);
%     subplot(3,3,1);
%     image(X(:,:,j));
%     xlabel(['Z = ' int2str(j)]);
%     title('Some slices along the Z-orientation of the original brain data');