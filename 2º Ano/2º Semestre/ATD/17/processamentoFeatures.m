function matrizResultado = processamentoFeatures(matrizResultado,i, j)
        myArray = [];
        filename = [num2str(i) '_17_' num2str(j) '.wav']; 
        [y, Fs] = audioread(filename);
        for x = 1:numel(y) 
            if y(x) >= -0.001 && y(x) <= 0.001 %Vai ver todos os valores onde o y reune a condição
                myArray = [myArray,x]; %guarda os indices onde a condição é verdadeira
            end
        end
        
        for x = 1:numel(myArray)
            if myArray(x) - x > 250 %Quando houver uma descrepância maior que 250 entre o indice x e o valor guardado no myArray
                y = y(x:end); %Eliminamos todos os valores de y para trás desse indice x
                break;
            end
        end
        
        
        y_norm = y /  max(abs(y)); %Normalizar o som
        zeros = 41600 - numel(y); %Numeros de zeros necessários para atingir o tamanho desejado
        y = padarray(y_norm, zeros, "post"); %Adicionar zeros no fim do Array para que tenham todos o mesmo tamanho
        
        index = (i * 50) + j + 1; %Calcular o indice para guardar as features num array de uma maneira mais ótima
        
        matrizResultado(index,1) = i; %500 audiofiles para uma search mais eficiente
        
        matrizResultado(index,2) = mean(y); %Amplitude Media
        
        matrizResultado(index,3) = std(y); %desvio padrão
        
        [~, indice] = max(abs(y)); %Indice do valor Max de y
        
        matrizResultado(index,4) = indice / Fs; %Duração Pico Inicial
        
        Amppico = y(1:indice); %valores de y do inicio do som até ao Pico Inicial
        
        matrizResultado(index,5) = sum(Amppico.^2); %Energia do Pico inicial
        
        matrizResultado(index,6) = sum(abs(y).^2); %Energia total
            
        
        return;
       
end