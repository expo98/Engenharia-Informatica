import java.util.ArrayList;
import java.util.Random;


public class POOTrivia {

        public static void main(String[] args) {
            GameFile gameFile = new GameFile();
            GUI gui = new GUI(gameFile.getGameQuestions());
        }



    protected String playerName;
    protected String dateTime;
    //protected ArrayList<AbstractQuestions> askedQuestions = new ArrayList<>();

    /*public POOTrivia(String playerName, String dateTime,ArrayList<AbstractQuestions> askedQuestions ){
        this.playerName=playerName;
        this.dateTime=dateTime;
        this.askedQuestions=askedQuestions;
    }
    */


        private void StartGame(GameFile gameFile){
            Random random = new Random();

            ArrayList<ArrayList<String>> gameQuestions = new ArrayList<ArrayList<String>>();
            ArrayList<Integer> questionType = new ArrayList<Integer>();

            for (int i =0; i <5; i++){
                questionType.add(random.nextInt(1,5));
            }

            for (int type : questionType){
                switch (type){
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:

                }
            }


        }


    }
