import java.awt.event.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import javax.swing.*;

public class GUI extends JFrame{
    JPanel panel;

    private JPanel questionPanel;
    private JPanel questionPanelEasy;
    private JPanel questionPanelTF;


    //gameFile.getGameQuestions(); Array das perguntas
    // ArrayList de opcoes
    // Tipo| Dificuldade | QUestão | Opção Errada 1 | ... | Opção Errada Ultima | Opcao Correta
    //                                     ^                                            ^
    //                                     | -------------------------------------------|
    //                                                  ArrayList de Opções
    //                                             Se ArrayList.size()>2 -> multAnswerGUI()
    //                                                 else -> trueFalseGUI()
    //                                                      Shuffle
    //                                          Se botão devolver String "Opção Correta" -> Acertou


    public GUI(ArrayList<ArrayList<String>> gameQuestions){
        this.setTitle("POO Trivia!");
        this.setSize(1000,700);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        menuGUI(gameQuestions);
    }

    public void menuGUI(ArrayList<ArrayList<String>> gameQuestions){

        JPanel menuPanel = new JPanel(); //Adding the panel that contains the components of the main menu design
        JLabel helloLabel = new JLabel("Who Wants To Be A POOlionaire?");
        helloLabel.setLayout(new FlowLayout(FlowLayout.CENTER));
        helloLabel.setFont(new Font("Arial", Font.BOLD, 40));
        helloLabel.setHorizontalAlignment(JLabel.CENTER);
        menuPanel.add(helloLabel);

        JLabel rulesLabel = new JLabel("<html>After the question is generated, choose the correct option!<br/>The questions can be either multiple choice or of the type true/false.<br/>If you choose the right option, your points tally will increase!<br/>Try to get the most points, and enjoy the quiz!");
        rulesLabel.setLayout(new FlowLayout(FlowLayout.LEADING));
        rulesLabel.setFont(new Font("Arial", Font.BOLD, 25));
        rulesLabel.setHorizontalAlignment(JLabel.CENTER);
        menuPanel.add(rulesLabel);


        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JButton startButton = new JButton("Start Game!");
        startButton.setFont(new Font("Comic Sans", Font.BOLD, 30));
        startButton.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
        startButton.setBackground(new Color(230,240,245));
        startButton.setPreferredSize(new Dimension(400,200));
        buttonsPanel.add(startButton);
        startButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (!gameQuestions.isEmpty()) {
                    clearFrame();
                    System.out.println("Botão correctamente clicaldo!");
                    multanswerGUI(gameQuestions);
                } else {
                    // Handle the case when gameQuestions is empty
                    System.out.println("No questions available.");
                }
            }
        });


        JButton topButton = new JButton("Leaderboard");
        topButton.setFont(new Font("Comic Sans", Font.BOLD, 30));
        topButton.setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
        topButton.setBackground(new Color(230,240,245));
        topButton.setPreferredSize(new Dimension(400,200));

        buttonsPanel.add(startButton);
        buttonsPanel.add(topButton);

        menuPanel.add(buttonsPanel, BorderLayout.SOUTH);
        this.add(menuPanel, BorderLayout.CENTER);
        this.setContentPane(menuPanel);
        this.setVisible(true);
    }

    private void clearFrame(){
        this.getContentPane().removeAll();
    }

    private void multanswerGUI(ArrayList<ArrayList<String>> gameQuestions) {

            String gameQuestionType = gameQuestion.get(0);
            String gameQuestionText = gameQuestion.get(2);
            String correctOption = gameQuestion.get(gameQuestion.size() - 1);

            ArrayList<String> gameOptions = new ArrayList<String>();

            for (int i = 3; i < gameQuestion.size(); i++) {
                gameOptions.add(gameQuestion.get(i));
            }
            Collections.shuffle(gameOptions);


            if (gameOptions.size() == 5) {

                questionPanel = new JPanel();
                questionPanel.setLayout(new GridLayout(6, 1));

                JLabel questionLabel = new JLabel("Questão: ");
                questionLabel.setFont(new Font("Arial", Font.BOLD, 30));
                JButton option1Button = new JButton(gameOptions.get(0));
                JButton option2Button = new JButton(gameOptions.get(1));
                JButton option3Button = new JButton(gameOptions.get(2));
                JButton option4Button = new JButton(gameOptions.get(3));
                JButton option5Button = new JButton(gameOptions.get(4));


                questionPanel.add(questionLabel);
                questionPanel.add(option1Button);
                questionPanel.add(option2Button);
                questionPanel.add(option3Button);
                questionPanel.add(option4Button);
                questionPanel.add(option5Button);

                this.setContentPane(questionPanel);
                this.revalidate();
                this.repaint();
            } else if (gameOptions.size() == 3) {
                //COdigo 3 perguntas
                questionPanelEasy = new JPanel();
                questionPanelEasy.setLayout(new GridLayout(4, 1));

                JLabel questionLabel = new JLabel("Questão: ");
                questionLabel.setFont(new Font("Arial", Font.BOLD, 30));
                JButton option1Button = new JButton(gameOptions.get(0));
                JButton option2Button = new JButton(gameOptions.get(1));
                JButton option3Button = new JButton(gameOptions.get(2));


                questionPanelEasy.add(questionLabel);
                questionPanelEasy.add(option1Button);
                questionPanelEasy.add(option2Button);
                questionPanelEasy.add(option3Button);


                this.setContentPane(questionPanelEasy);
                this.revalidate();
                this.repaint();

            } else if (gameOptions.size() == 2) {

                questionPanelTF = new JPanel();
                questionPanelTF.setLayout(new BorderLayout());

                JLabel questionLabel = new JLabel("A Terra é plana?");
                questionLabel.setFont(new Font("Arial", Font.BOLD, 30));
                questionLabel.setHorizontalAlignment(JLabel.CENTER);
                questionPanelTF.add(questionLabel, BorderLayout.NORTH);

                JPanel optionsPanel = new JPanel(new GridLayout(1, 2));
                JRadioButton trueButton = new JRadioButton(gameOptions.get(0));
                JRadioButton falseButton = new JRadioButton(gameOptions.get(1));

                ButtonGroup group = new ButtonGroup();
                group.add(trueButton);
                group.add(falseButton);

                optionsPanel.add(trueButton);
                optionsPanel.add(falseButton);

                questionPanelTF.add(optionsPanel, BorderLayout.CENTER);

                JButton submitButton = new JButton("Submit");
                submitButton.addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        // Aqui você pode verificar qual botão está selecionado e fazer o tratamento da resposta
                        if (trueButton.isSelected()) {
                            // Resposta verdadeira
                        } else if (falseButton.isSelected()) {
                            // Resposta falsa
                        }
                    }
                });

                questionPanelTF.add(submitButton, BorderLayout.SOUTH);

                this.setContentPane(questionPanelTF);
                this.revalidate();
                this.repaint();

            } else {
                System.out.println("Size not met");
            }
        
    }
    private void loadNextQuestion(){
    }
    /*private void truefalseGUI(){
        questionPanelTF = new JPanel();
        questionPanelTF.setLayout(new BorderLayout());

        JLabel questionLabel = new JLabel("A Terra é plana?");
        questionLabel.setFont(new Font("Arial", Font.BOLD, 30));
        questionLabel.setHorizontalAlignment(JLabel.CENTER);
        questionPanelTF.add(questionLabel, BorderLayout.NORTH);

        JPanel optionsPanel = new JPanel(new GridLayout(1, 2));
        JRadioButton trueButton = new JRadioButton("Verdadeiro");
        JRadioButton falseButton = new JRadioButton("Falso");

        ButtonGroup group = new ButtonGroup();
        group.add(trueButton);
        group.add(falseButton);

        optionsPanel.add(trueButton);
        optionsPanel.add(falseButton);

        questionPanelTF.add(optionsPanel, BorderLayout.CENTER);

        JButton submitButton = new JButton("Submit");
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Aqui você pode verificar qual botão está selecionado e fazer o tratamento da resposta
                if (trueButton.isSelected()) {
                    // Resposta verdadeira
                } else if (falseButton.isSelected()) {
                    // Resposta falsa
                }
            }
        });

        questionPanelTF.add(submitButton, BorderLayout.SOUTH);

        this.setContentPane(questionPanelTF);
        this.revalidate();
        this.repaint();
    }
*/
    private void finalGUI(){
        JPanel endPanel = new JPanel();
        endPanel.setLayout(new BorderLayout());

        JLabel endLabel = new JLabel("Jogo Terminado!");
        endLabel.setFont(new Font("Arial", Font.BOLD, 40));
        endLabel.setHorizontalAlignment(JLabel.CENTER);
        endPanel.add(endLabel, BorderLayout.NORTH);

        JPanel scorePanel = new JPanel(new GridLayout(4, 1));

        JLabel scoreLabel = new JLabel("Pontuação Final: ");
        scoreLabel.setFont(new Font("Arial", Font.BOLD, 25));
        scoreLabel.setHorizontalAlignment(JLabel.CENTER);
        scorePanel.add(scoreLabel);

        JLabel nameLabel = new JLabel("Insira o seu nome completo:");
        nameLabel.setFont(new Font("Arial", Font.PLAIN, 20));
        nameLabel.setHorizontalAlignment(JLabel.CENTER);
        scorePanel.add(nameLabel);

        JTextField nameField = new JTextField();
        scorePanel.add(nameField);

        JButton viewTopScoresButton = new JButton("Ver TOP 3");
        viewTopScoresButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Aqui você pode mostrar o TOP 3 de pontuações
                // Implemente a lógica para exibir as melhores pontuações
            }
        });
        scorePanel.add(viewTopScoresButton);

        endPanel.add(scorePanel, BorderLayout.CENTER);

        JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JButton newGameButton = new JButton("Novo Jogo");
        JButton exitButton = new JButton("Sair");

        buttonsPanel.add(newGameButton);
        buttonsPanel.add(exitButton);

        endPanel.add(buttonsPanel, BorderLayout.SOUTH);

        this.setContentPane(endPanel);
        this.revalidate();
        this.repaint();
        this.setVisible(true);

        // Adicionar a lógica de eventos para os botões 'Novo Jogo' e 'Sair'
        newGameButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Lógica para iniciar um novo jogo
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Lógica para sair do jogo
                System.exit(0); // Exemplo simples: encerra o programa
            }
        });
    }

}


