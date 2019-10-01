%load wmri
clear;

gold = importdata('outfull.dat','\n');
count = 1;
for i = 1:128
    for j = 1:128
        for k = 1:24      
              
            
            X(i,j,k) = gold(count);
            count = count + 1;
            
        end
    end
end

map = pink(140);
figure('DefaultAxesXTick',[],'DefaultAxesYTick',[],...
        'DefaultAxesFontSize',8,'Color','w')
XR = X;
Ds = smooth3(XR);
hiso = patch(isosurface(Ds,5),'FaceColor',[1,.75,.65],'EdgeColor','none');
hcap = patch(isocaps(XR,5),'FaceColor','interp','EdgeColor','none');
colormap(map)
daspect(gca,[1,1,.4])
lightangle(305,30); 
fig = gcf;
fig.Renderer = 'zbuffer';
lighting phong
isonormals(Ds,hiso)
hcap.AmbientStrength = .6;
hiso.SpecularColorReflectance = 0;
hiso.SpecularExponent = 50;
ax = gca;
ax.View = [315,30];%[215,30]
ax.Box = 'On';
axis tight
%title('Original Data');