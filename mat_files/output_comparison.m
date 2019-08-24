clear;
clc;

x_max = 4;
y_max = 4;
z_max = 24;

gold = importdata('out2.gold.dat','\n');
count = 1;
max = 0;
for i = 1:x_max
    for j = 1:y_max
        for k = 1:z_max       
            
            Y(i,j,k) = gold(count);
            count = count + 1;
            
        end
    end
end

out = importdata('out2.dat','\n');
count = 1;
for i = 1:x_max
    for j = 1:y_max
        for k = 1:z_max       
            
            X(i,j,k) = out(count);
            count = count + 1;
            
        end
    end
end

count = 1;
dif = 0;
countzero = 0;
countdiff = 0;
flag = 0;
for i = 1:x_max
    for j = 1:y_max
        for k = 1:z_max                   
            
            dif = abs(X(i,j,k) - Y(i,j,k));
            
            if dif > 1
                    fprintf("count = %d\n", count);
                    fprintf("%d,%d,%d\n\n", i, j, k);
            end
            
            count = count + 1;
            
        end
    end
end

fprintf('%f %% \n',countzero/(countzero + countdiff)*100);

% if flag == 0
%     fprintf('output matches gold output\n');
% end
