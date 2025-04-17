load handel.mat

funcaograficos() %Visualização de 0 a 9
figure;
Matriz = zeros(500,6); %Matriz só com 0's
for i = 0:9
    for j = 0:49
        Matriz = processamentoFeatures(Matriz,i,j); %Altera a matriz 
        
    end
end

for i = 2:6
    title(num2str(i));
    for j = 1:500
        scatter(Matriz(1:j,1),Matriz(1:j,i)); %fazer os gráficos
        xlim([-1,10]); %Limite para uma visualização mais fácil
    end
    if i < 6 %Para não criar uma ultima figure vazia
        figure;
    end
end
