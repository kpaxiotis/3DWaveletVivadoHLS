gold = importdata('out.gold.dat','\n');
count = 1;
for i = 1:128
    for j = 1:128
        for k = 1:24       
            
            G(i,j,k) = gold(count);
            count = count + 1;
            
        end
    end
end

flag = 0;
for i = 1:128
    for j = 1:128
        for k = 1:24
%             if round(dwt(i,j,k)*100)/100 ~= ...
%                     round(X(i,j,k)*100)/100
             if G(i,j,k) ~= X(i,j,k)
                fprintf("i=%d\nj=%d\nk=%d\nX=%d\ndwt=%d\n\n",i,j,k,...
                    X(i,j,k),dwt(i,j,k));                
                if flag == 1
                    return;
                end
                flag = 0;            
            end            
        end
    end
end
if flag == 0
    fprintf("The two variables match\n");
end

% if X == dwt
%     fprintf("data match");
% else
%     fprintf("data don't match");
% end