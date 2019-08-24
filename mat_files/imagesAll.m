map = pink(90);

y = importdata('out.dat','\n');
count = 1;

for i = 1:128
    for j = 1:128
        for k = 1:24     
            X(i,j,k) = y(count);
            count = count + 1;
            
        end
    end
end




idxImages = 1:size(X,3);
figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
    'DefaultAxesFontSize',8,'Color','w')
colormap(map)
for k = 1:9
    j = idxImages(k);
    subplot(3,3,k);
    image(X(:,:,j));
    xlabel(['Z = ' int2str(j)]);
    if k==2
        title('Some slices along the Z-orientation of the original brain data');
    end
end
idxImages = 10:size(X,3);
figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
    'DefaultAxesFontSize',8,'Color','w')
colormap(map)
for k = 1:9
    j = idxImages(k);
    subplot(3,3,k);
    image(X(:,:,j));
    xlabel(['Z = ' int2str(j)]);
    if k==2
        title('Some slices along the Z-orientation of the original brain data');
    end
end
idxImages = 18:size(X,3);
figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
    'DefaultAxesFontSize',8,'Color','w')
colormap(map)
for k = 1:9
    j = idxImages(k);
    subplot(3,3,k);
    image(X(:,:,j));
    xlabel(['Z = ' int2str(j)]);
    if k==2
        title('Some slices along the Z-orientation of the original brain data');
    end
end
idxImages = 28:size(X,3);
figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
    'DefaultAxesFontSize',8,'Color','w')
colormap(map)
j = idxImages(1);
    subplot(3,3,1);
    image(X(:,:,j));
    xlabel(['Z = ' int2str(j)]);
    title('Some slices along the Z-orientation of the original brain data');