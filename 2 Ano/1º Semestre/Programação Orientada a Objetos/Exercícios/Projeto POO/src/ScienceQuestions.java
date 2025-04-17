/*
import java.util.ArrayList;

import java.util.Objects;
import java.util.Random;

public class ScienceQuestions extends AbstractQuestions {

    private ArrayList<String> easyQuestions = new ArrayList<String>();
    private ArrayList<String> hardQuestions = new ArrayList<String>();

    public ScienceQuestions(int score, String question, ArrayList<String> questionOptions, ArrayList<String> ScienceQuestions) {
        super(score, question, questionOptions);
        loadQuestions(ScienceQuestions);
    }

    @Override
    protected void loadQuestions(ArrayList<String> questions) {
        String questionLine;
        for (String s : questions) {
            questionLine = s;
            String[] parts = questionLine.split("\\|");

            String questionDifficulty = parts[1];

            if (Objects.equals(parts[1], "Easy")) {
                easyQuestions.add(questionLine);
            }
            if (Objects.equals(parts[1], "Hard")) {
                hardQuestions.add(questionLine);
            }
        }
    }

}
*/
