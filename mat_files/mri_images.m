
map = pink(140);
idxImages = 1:3:size(X,3);
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
