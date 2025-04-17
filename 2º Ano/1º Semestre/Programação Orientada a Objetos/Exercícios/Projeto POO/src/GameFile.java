import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class GameFile {

    private ArrayList<ArrayList<String>> allGameQuestions = new ArrayList<ArrayList<String>>();

    private ArrayList<ArrayList<String>> gameQuestions = new ArrayList<ArrayList<String>>();

    public  GameFile(){
        loadQuestions();
        GameSetup(allGameQuestions);
    }

    private void loadQuestions(){
        try {
            String fileName = "Questions.txt";
            java.io.File f = new java.io.File(fileName);
            FileReader reader = new FileReader(f);
            BufferedReader br = new BufferedReader(reader);
            String line;

            while ((line = br.readLine()) != null) {
                ArrayList<String> tempQuestionLine = new ArrayList<String>();
                String[] parts;
                parts = line.split("\\|");

                for (String part : parts){
                    tempQuestionLine.add(part);
                }
                this.allGameQuestions.add(tempQuestionLine);
            }

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    public ArrayList<ArrayList<String>> getGameQuestions(){
        return gameQuestions;
    }

    protected void GameSetup(ArrayList<ArrayList<String>> allGameQuestions) {

        ArrayList<ArrayList<String>> gameQuestions = new ArrayList<ArrayList<String>>();
        ArrayList<String> tempQuestionOptions = new ArrayList<String>();

        ArrayList<String> tempQuestionList;
        String tempQuestionDifficulty;
        String tempQuestionType;

        Collections.shuffle(allGameQuestions);

        for (int i = 0; i < allGameQuestions.size(); i++) {
            int gameQuestionsSize=0;
            tempQuestionList = new ArrayList<>(allGameQuestions.get(i)); // Create a copy to avoid modifying the original list
            tempQuestionDifficulty = tempQuestionList.get(1);
            tempQuestionType = tempQuestionList.get(0);

            if (gameQuestionsSize < 2 && !Objects.equals(tempQuestionDifficulty, "Hard") && !Objects.equals(tempQuestionDifficulty, "Name")) {
                if (Objects.equals(tempQuestionType, "Art")) {
                    // Extract correct option
                    String correctOption = tempQuestionList.get(tempQuestionList.size() - 1);

                    // Extract incorrect options
                    ArrayList<String> incorrectOptions = new ArrayList<>(tempQuestionList.subList(3, tempQuestionList.size() - 1));

                    // Shuffle the incorrect options
                    Collections.shuffle(incorrectOptions);

                    // Ensure the size of tempQuestionOptions is at most 2
                    incorrectOptions.subList(2, incorrectOptions.size()).clear();

                    // Add the correct option last
                    tempQuestionList.clear();
                    tempQuestionList.add("Art");
                    tempQuestionList.add("");
                    tempQuestionList.add("Questão 1");
                    tempQuestionList.addAll(incorrectOptions);
                    tempQuestionList.add(correctOption);

                    gameQuestions.add(tempQuestionList);
                    gameQuestionsSize++;
                    System.out.println("Olá 1");
                }
                 else {
                    gameQuestions.add(tempQuestionList);
                    gameQuestionsSize++;
                    System.out.println("Olá 2");
                }
            } else if (gameQuestions.size() >= 3){
                if (Objects.equals(tempQuestionType, "Art") || (Objects.equals(tempQuestionType, "Science") && Objects.equals(tempQuestionDifficulty, "Hard")) || Objects.equals(tempQuestionType, "Skiing") || Objects.equals(tempQuestionType, "Swimming") || ((Objects.equals(tempQuestionType, "Football") && Objects.equals(tempQuestionDifficulty, "Number")))) {
                    gameQuestions.add(tempQuestionList);
                    gameQuestionsSize++;
                    System.out.println("Olá 3 ");
                }
            }
        }
        this.gameQuestions = gameQuestions;
    }

    /*
    protected ArrayList<ArrayList<String>> GameSetup(ArrayList<ArrayList<String>> allGameQuestions){

        ArrayList<ArrayList<String>> gameQuestions = new ArrayList<ArrayList<String>>();
        ArrayList<String> tempQuestionOptions = new ArrayList<String>();

        ArrayList<String> tempQuestionList = new ArrayList<String>();
        String tempQuestionDifficulty;
        String tempQuestionType;

        Collections.shuffle(allGameQuestions);

        for (int i =0; i < allGameQuestions.size() && gameQuestions.size() <5; i++){
            tempQuestionList = allGameQuestions.get(i);
            tempQuestionDifficulty = tempQuestionList.get(1);
            tempQuestionType = tempQuestionList.get(0);

            if (gameQuestions.size()<2 && (!Objects.equals(tempQuestionDifficulty, "Hard")) && (!Objects.equals(tempQuestionDifficulty,"Name"))){
                if (Objects.equals(tempQuestionType, "Art")){
                    for (int j =3; j< tempQuestionList.size()-1;j++){
                        tempQuestionOptions.add(tempQuestionList.get(j));
                    }

                    Collections.shuffle(tempQuestionOptions);

                    for (int j = tempQuestionOptions.size(); j>2;j--){
                        tempQuestionOptions.remove(j);
                    }
                    tempQuestionOptions.add(tempQuestionList.get(tempQuestionList.size()-1));

                    for (int j =tempQuestionList.size(); j>3;j--){
                        tempQuestionList.remove(j);
                    }
                    tempQuestionList.addAll(tempQuestionOptions);
                    gameQuestions.add(tempQuestionList);

                }
                else {
                    gameQuestions.add(tempQuestionList);
                }
            } else if (gameQuestions.size()>=3 && !(Objects.equals(tempQuestionDifficulty,"Easy")) && !(Objects.equals(tempQuestionDifficulty,"Number"))){
                gameQuestions.add(tempQuestionList);
            }
        }
        return gameQuestions;
    }

     */
}

