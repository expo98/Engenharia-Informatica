/*

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public abstract class AbstractQuestions {
    protected int score;
    protected int questionNumber;
    protected String question;
    protected ArrayList<String> questionOptions;

    public AbstractQuestions(int score, String question, ArrayList<String> questionOptions) {
        this.score=score;
        this.question=question;
        this.questionOptions=questionOptions;
    }

    protected void displayQuestionAndOptions(String question, ArrayList<String> options) {
        System.out.println(question);

        for (int i = 0; i < options.size(); i++) {
            System.out.println((i + 1) + ". " + options.get(i));
        }
    }

    protected abstract void loadQuestions(ArrayList<String> questions);

    //protected abstract int scoreUpdater();
    
    protected void shuffleListOptions(){
        Collections.shuffle(this.questionOptions);
    }
    public int getScore(){
        return this.score;
    }

    public ArrayList<String> getQuestionOptions(){
        return this.questionOptions;
    }

    public String getQuestion(){
        return this.question;
    }
    
    public int getQuestionNumber(){
        return this.questionNumber;
    }

    public void setScore(int score){
        this.score =score;
    }

    public void setQuestion(String question){
        this.question = question;
    }
    public  void setQuestionOptions(ArrayList<String> questionOptions){
        this.questionOptions = questionOptions;
    }
}

 */
