function funcaograficos()


    for i = 0:9
        filename = [num2str(i) '_17_1.wav'];
        [y, Fs] = audioread(filename);
        t = (0:length(y) - 1) / Fs; %eixo x
        subplot(5, 2, i + 1);  %subplots

        plot(t, y)
        ylim([-0.02, 0.02]); %Limite y para gráfico ficar mais uniforme
        xlabel('Time (s)');
        title(['Plot ', num2str(i)]);
        grid on;

    end
end