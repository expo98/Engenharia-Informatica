/*import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Random;
import java.util.Scanner;
public class FootballQuestions extends AbstractQuestions {

    private ArrayList<String> numberQuestions = new ArrayList<String>();
    private ArrayList<String> nameQuestions = new ArrayList<String>();

    public FootballQuestions(int score, String question, ArrayList<String> questionOptions) {
        super(score, question, questionOptions);

    }
    protected void loadQuestions(ArrayList<String> questions){
        String questionLine;
        for (String s : questions) {
            questionLine = s;
            String[] parts = questionLine.split("\\|");

            String questionDifficulty = parts[1];

            if (Objects.equals(parts[1], "Name")) {
                nameQuestions.add(questionLine);
            }
            if (Objects.equals(parts[1], "Number")) {
                numberQuestions.add(questionLine);
            }
        }
    }
}
*/
